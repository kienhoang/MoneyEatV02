#include "mw.h"
#include "ui_mw.h"
#include <QSpinBox>
#include <QKeyEvent>
#include <QFileDialog>

#include "editdate.h"
#include "editchilditem.h"
#include "money.h"
#include "databasepath.h"

MW::MW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    statusLabel = new QLabel();
    ui->statusBar->addWidget(statusLabel);
    loadSetting();
    if(this->dbPath == ""){
        this->dbPath = "default.db";
        QMessageBox::information(this,"Info","Database not set. Connect to default.db");
    }
    connectDatabase();
    connectEvent();
    importFromDB();

    log = new Log(this);
    loadEvent();
    ui->sbMoney->setSingleStep(1000);
    sortTreeWidget(ui->moneyList);
    //ui->moneyList->sortByColumn(0,Qt::DescendingOrder);
    //ui->moneyList->setSortingEnabled(true);
    connect(ui->moneyList,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onDoubleClick()));
    ui->moneyList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->moneyList,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showContextMenu(QPoint)));
}

MW::~MW()
{
    delete qry;
    delete log;
    delete ui;
}

bool MW::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->sbMoney){
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return){
                on_btnAddItem_clicked();
                return true;
            }else{
                return false;
            }
        } else {
            // standard event processing
            return QObject::eventFilter(obj, event);
        }
    }else{
        return false;
    }
}

//Connect to database
void MW::connectDatabase(){
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(this->dbPath);
    DatabasePath * mDatabasePath;
    while(!this->db.open()){
#ifdef _DEBUG
        qDebug() << "Failed to Connect Database, Path: " + this->dbPath + " . You must set Database path now.";
#endif
        QMessageBox::critical(this,"ERROR","Failed to Connect Database, Path: " + this->dbPath+ " . You must set Database path now.");
        mDatabasePath = new DatabasePath(this);
        mDatabasePath->setPath(this->dbPath);
        mDatabasePath->exec();
        if (mDatabasePath->changed()){
            this->dbPath = mDatabasePath->getPath();
            this->db.setDatabaseName(this->dbPath);
            delete mDatabasePath;
        }else{
            //this->close();
			exit(0);

        }
    }
//    if(this->db.open()){
        //Do Somethings if Opened
        //ui->statusBar->showMessage("Connected to " + this->dbPath);
        //ui->statusBar->addWidget(new QLabel("Connected to " + this->dbPath));
        statusLabel->setText("Connected to " + this->dbPath);
        qry = new QSqlQuery(db);

        // Create table Money : DATE|EVENT|MONEY
        sqry = "CREATE TABLE IF NOT EXISTS money (date VARCHAR NOT NULL, event VARCHAR, money INTEGER NOT NULL, id INTEGER PRIMARY KEY NOT NULL);";
        if(qry->exec(sqry)){
#ifdef _DEBUG
            qDebug() << "Success for create table money";
#endif
        }else{
#ifdef _DEBUG
            qDebug() << "Failed for create or ignore table money";
#endif
            QMessageBox::critical(this,"ERROR","Failed for create or ignore table money");
        }

        //Create table History: DATE|EVENT
        sqry = "CREATE TABLE IF NOT EXISTS history (date VARCHAR NOT NULL, event VARCHAR);";
        if(qry->exec(sqry)){
#ifdef _DEBUG
            qDebug() << "Success for create table history";
#endif
        }else{
#ifdef _DEBUG
            qDebug() << "Failed for create or ignore table history";
#endif
            QMessageBox::critical(this,"ERROR","Failed for create or ignore table history");
        }
//    }else{
        //Do Somethings if not Opened
        //qDebug() << "Failed to Connect Database, Path: " + this->dbPath;
        //QMessageBox::critical(this,"ERROR","Failed to Connect Database, Path: " + this->dbPath);
//    }

}

//Close database
void MW::closeDatabase(){
    this->db.close();
    this->db.removeDatabase(QSqlDatabase::defaultConnection);
}

//Save current settings
void MW::saveSetting(){
    /*
    QSettings * set = new QSettings("HK","app");
    set->beginGroup("Save State");
    //Save Somthings here
    set->setValue("path",this->dbPath);
    set->endGroup();
    */
    QFile f("config");
    if (f.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&f);
        stream << this->dbPath;
    }else{
        QMessageBox::critical(this,"ERROR IO","Error in write config file.");
    }
    f.close();
}

/************************************************************************/
/* Load last Settings                                                   */
/************************************************************************/
void MW::loadSetting()
{
    /*
    QSettings * set = new QSettings("HK","app");
    set->beginGroup("Save State");
    // Load somethings here
    this->dbPath = set->value("path").toString();
    set->endGroup();
    */
    QFile f("config");
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&f);
        this->dbPath = stream.readLine();
    }else{
        this->dbPath = "";
    }
    f.close();
}

/************************************************************************/
/* Do somethings when application close                                 */
/************************************************************************/
void MW::closeEvent(QCloseEvent *){
    //Do somthings
    saveSetting();
    closeDatabase();
}

/**
 * Create a Event history
 * */
void MW::createEvent(QString event){
    //Do somethings
    QString sdate = QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss");
    sqry = "INSERT INTO history VALUES('" + sdate + "','" + event + "');" ;
    if(qry->exec(sqry)){
#ifdef _DEBUG
        qDebug() << "Success to AddEvent";
#endif
        log->addEvent(sdate + " | " + event);
    }else{
#ifdef _DEBUG
        qDebug() << "Failed to AddEvent";
#endif
    }
}

/**
  * Load Event
  * */
void MW::loadEvent(){
    sqry = "SELECT * FROM history;";
    if(qry->exec(sqry)){
        while(qry->next()){
            log->addEvent(qry->value(0).toString() + " | "+ qry->value(1).toString());
        }
    }
}



/**
 * Add a Event to Money Tree
 * */
QTreeWidgetItem * MW::addEventToTree(QDate &date, QString &event, 
						unsigned int money, QString &id)
{
    int count = ui->moneyList->topLevelItemCount();
    QString sdate = date.toString("dd/MM/yyyy");
    bool flag = true;
    QTreeWidgetItem * item, * child;
    for(int i = 0; i < count; i++){
        item = ui->moneyList->topLevelItem(i);
        if(item->data(0,0).toString() == sdate){
            child = new QTreeWidgetItem();
            child->setText(0,event);
            child->setText(1,QString::number(money));
            child->setText(2,id);
            item->addChild(child);
            flag = false;
            break;
        }
    }
    if(flag){
        item = new QTreeWidgetItem();
        item->setText(0,sdate);
        item->setText(1,"0");
        ui->moneyList->addTopLevelItem(item);
        child = new QTreeWidgetItem();
        child->setText(0,event);
        child->setText(1,QString::number(money));
        child->setText(2,id);
        item->addChild(child);
    }
    ui->moneyList->setCurrentItem(child);
    return item;
}

// Add Event to Database
bool MW::addEventToDB(QDate &date, QString &event, unsigned int money, QString &id){
    QString sdate = date.toString("dd/MM/yyyy");
    QString smoney = QString::number(money);
    sqry = "INSERT INTO money VALUES('" + sdate + "','" + event + "'," + smoney + "," + id + ");";
    if(qry->exec(sqry)){
#ifdef _DEBUG
        qDebug() << "Success Add value to Database";
#endif
        createEvent("Added : " + sdate + " | " + event + " | " + smoney);
        return true;
    }else{
#ifdef _DEBUG
        qDebug() << "Failed to Add value to Database";
#endif
        createEvent("Failed Add : " + sdate + " | " + event + " | " + smoney);
        QMessageBox::critical(this,"ERROR","Failed to Add value to Database");
        return false;
    }
}

//Connect Widgets Events
void MW::connectEvent(){
    ui->date->setDate(ui->calendar->selectedDate());
    connect(ui->calendar,SIGNAL(selectionChanged()),this,SLOT(calendarChanged()));
    connect(ui->date,SIGNAL(dateChanged(QDate)),this,SLOT(dateChanged()));
    ui->moneyList->setColumnHidden(2,true);
    ui->sbMoney->installEventFilter(this);
    ui->sbMoney->setSingleStep(3);
}
/*When calendar changed*/
void MW::calendarChanged(){
    ui->date->setDate(ui->calendar->selectedDate());
}

/*When dateEdit changed*/
void MW::dateChanged(){
    ui->calendar->setSelectedDate(ui->date->date());
}

void MW::onDoubleClick()
{
    QTreeWidgetItem * item = ui->moneyList->currentItem();
    bool expand = item->isExpanded();
    if (item){
        editItem(item);
    } else{
        QMessageBox::information(this,"Info","Nothing to Edit");
    }
    item->setExpanded(expand);
}

void MW::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->moneyList->mapToGlobal(pos);
    QMenu myMenu;
    myMenu.addAction("Edit",this,SLOT(on_btnEdit_clicked()));
    myMenu.exec(globalPos);
}
/*Calc Total of top level*/
void MW::calcTotalTop(QTreeWidgetItem *item){
    int count = item->childCount();
    unsigned int s = 0;
    for(int i = 0; i < count; i++){
        s = s + item->child(i)->data(1,0).toInt();
    }
    item->setText(1,QString::number(s));
}
/*Calc All top level*/
void MW::calcAllTop(){
    int topCount = ui->moneyList->topLevelItemCount();
    int childCount;
    unsigned int s = 0;
    QTreeWidgetItem * topItem;
    for(int i = 0; i < topCount; i++){
        s = 0;
        topItem = ui->moneyList->topLevelItem(i);
        childCount = topItem->childCount();
        for(int j = 0; j < childCount; j++){
            s = s + topItem->child(j)->data(1,0).toInt();
        }
        topItem->setText(1,QString::number(s));
    }
}

//Auto Generate ID by Datetime
QString MW::generateID(){
    return QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
}
//Import data from database
void MW::importFromDB(){
    QDate date;
    QString event;
    unsigned int money;
    QString id;
    sqry = "SELECT * FROM money;";
    if(qry->exec(sqry)){
        while(qry->next()){
            date = QDate::fromString(qry->value(0).toString(),"dd/MM/yyyy");
            event = qry->value(1).toString();
            money = qry->value(2).toInt();
            id = qry->value(3).toString();
            addEventToTree(date,event,money,id);
        }
    }
    calcAllTop();
}

/**
 * Reload Tree
 * */
void MW::reLoadTree(){
    ui->moneyList->clear();
    importFromDB();
}

/*Delete a Item*/
void MW::deleteItem(QTreeWidgetItem * item){
    if(QMessageBox::question(this,"Delete","Are you sure want to delete?",
                             QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok){
        if(!item->parent()){
            QString date = item->data(0,0).toString();
            sqry = "DELETE FROM money WHERE date='" + date + "';";
            if(qry->exec(sqry)){
                createEvent("Deleted: " + date);
                int count = item->childCount();
                for (int i = 0; i < count ; i++){
                    createEvent("Deleted :" + item->data(0,0).toString() + " "
                                + item->child(i)->data(0,0).toString() + " "
                                + item->child(i)->data(1,0).toString());
                }
#ifdef _DEBUG
                qDebug() << "Success to Delete";
#endif
            }else{
                createEvent("Failed Delete: " + date);
#ifdef _DEBUG
                qDebug() << "Failed to Delete";
#endif
                QMessageBox::critical(this,"ERROR","Failed to Delete");
            }
            delete item;
        }else{
            auto parent = item->parent();
            QString id = item->data(2,0).toString();
            sqry = "DELETE FROM money WHERE id=" + id + ";";
            if(qry->exec(sqry)){
                createEvent("Deleted : "+item->parent()->data(0,0).toString() + " "
                            + item->data(0,0).toString() + " | "
                            + item->data(1,0).toString());
#ifdef _DEBUG
                qDebug() << "Success to Delete";
#endif
            }else{
#ifdef _DEBUG
                qDebug() << "Failed to Delete";
#endif
                QMessageBox::critical(this,"ERROR","Failed to Delete");
            }
            delete item;
            if(parent->childCount() == 0){
                delete parent;
            }else{
                calcTotalTop(parent);
            }
        }
    }else{
#ifdef _DEBUG
        qDebug()<< "Canceled";
#endif
    }
}

/*Edit a Item*/
void MW::editItem(QTreeWidgetItem *item){
    if(!item->parent()){
        QDate odate = QDate::fromString(item->data(0,0).toString(),"dd/MM/yyyy");
        EditDate mED(this);
        mED.setDate(odate);
        mED.setModal(true);
        mED.exec();
        if(mED.Update()){
            QDate date = mED.getDate();
            item->setText(0,date.toString("dd/MM/yyyy"));
            sqry = "UPDATE money SET date='" + date.toString("dd/MM/yyyy") +
                "' WHERE date='" + odate.toString("dd/MM/yyyy") + "';";
            if(qry->exec(sqry)){
                createEvent("Edit date: "+ odate.toString("dd/MM/yyyy") 
					+" to "+ date.toString("dd/MM/yyyy"));
#ifdef _DEBUG
                qDebug() << "Success to Update";
#endif
            }else{
#ifdef _DEBUG
                qDebug() << "Failed to Update";
#endif
                QMessageBox::critical(this,"ERROR","Failed to update data");
            }
            reLoadTree();
        }
    }else{
        QString oItem = item->data(0,0).toString() ,oMoney = item->data(1,0).toString();
        EditChildItem mED(this);
        mED.setModal(true);
        mED.setItem(oItem);
        mED.setMoney(oMoney);
        mED.exec();
        if(mED.Update()){
            QString nItem = mED.getItem();
            QString nMoney = mED.getMoney();
            item->setText(0,nItem);
            item->setText(1,nMoney);
            sqry = "UPDATE money SET event='" + mED.getItem() + 
				"', money=" + mED.getMoney() + " WHERE id=" + item->data(2,0).toString() + ";";
            if(qry->exec(sqry)){
#ifdef _DEBUG
                qDebug() << "Success to Update";
#endif
                createEvent("Edited: " + oItem + "|" + oMoney + " -> " + nItem + "|" + nMoney);
            }else{
#ifdef _DEBUG
                qDebug() << "Failed to Update";
#endif
                createEvent("Failed Edit: " + oItem + "|" + oMoney + " -> " + nItem + "|" + nMoney);
                QMessageBox::critical(this,"ERROR","Failed to update data");
            }
            calcTotalTop(item->parent());
        }
    }
}

unsigned int MW::totalMoney(){
    sqry = "SELECT * FROM money;";
    unsigned int total = 0;
    if(qry->exec(sqry)){
        while(qry->next()){
            total = total + qry->value(2).toInt();
        }
    }else{
#ifdef _DEBUG
        qDebug() << "Failed to calc";
#endif
    }
    return total;
}

void MW::clearTreeLog(){
    ui->moneyList->clear();
    log->clear();
}

void MW::swapItem(QTreeWidgetItem *item1, QTreeWidgetItem *item2){
    int i;
    QList<QTreeWidgetItem *> list1, list2;
	QTreeWidgetItem * itemchild;
	QString str;
	for (i = 0; i < ui->moneyList->columnCount(); i++){
		str = item1->text(i);
		item1->setText(i,item2->text(i));
		item2->setText(i,str);
	}
   
	// Copy List
    for (i = 0; i < item1->childCount(); i++){
        list1.append(item1->child(i));
    }
    for (i = 0; i < item2->childCount(); i++){
        list2.append(item2->child(i));
    }

    // Remove
    while (item1->childCount()){
		itemchild = item1->child(0);
        item1->removeChild(itemchild);
        //delete itemchild;
    }
    while(item2->childCount()){
		itemchild = item2->child(0);
        item2->removeChild(itemchild);
        //delete itemchild;
    }

    //Replace
    for (i = 0; i < list2.count(); i++){
        item1->addChild(list2.at(i));
    }
    for (i = 0; i < list1.count(); i++){
        item2->addChild(list1.at(i));
    }
    list1.clear();
    list2.clear();
}

void MW::sortTreeWidget(QTreeWidget *treeWidget){
    QDate date1,date2;
    QTreeWidgetItem *item1,*item2;
    int count = treeWidget->topLevelItemCount();
    for (int i = 0 ; i < count - 1; i++){
        for (int j = i + 1; j < count ; j++){
            item1 = treeWidget->topLevelItem(i);
            item2 = treeWidget->topLevelItem(j);
            date1 = QDate::fromString(item1->data(0,0).toString(),"dd/MM/yyyy");
            date2 = QDate::fromString(item2->data(0,0).toString(),"dd/MM/yyyy");
            if (date1 > date2){
                swapItem(item1,item2);
            }
        }
    }
}

void MW::on_btnAddItem_clicked()
{
    QDate date = ui->date->date();
    QString itemEvent = ui->leItem->text();
    QString money = ui->sbMoney->text();
    QString id = generateID();
    if(itemEvent != ""){
        if(addEventToDB(date,itemEvent,money.toInt(),id)){
            auto item = addEventToTree(date,itemEvent,money.toInt(),id);
            calcTotalTop(item);
            ui->leItem->setText("");
            ui->sbMoney->setValue(0);

        }
    }else{
        QMessageBox::information(this,"Info","Item Field cannot be empty.");
    }
}

void MW::on_btnDelete_clicked()
{
    QTreeWidgetItem * item = ui->moneyList->currentItem();
    if (item){
        deleteItem(item);
    } else {
        QMessageBox::information(this,"Info","Nothing to Delete");
    }
}

void MW::on_btnToday_clicked()
{
    ui->calendar->setSelectedDate(QDate::currentDate());
}

void MW::on_btnEdit_clicked()
{
    QTreeWidgetItem * item = ui->moneyList->currentItem();
    if (item){
        editItem(item);
    } else{
        QMessageBox::information(this,"Info","Nothing to Edit");
    }
}

void MW::on_btnLog_clicked()
{
    log->show();
}

void MW::on_btnCalc_clicked()
{
    Money money(this);
    money.setVisible(false);
    money.setMoney(QString::number(totalMoney()));
    money.exec();
}

void MW::on_actionNew_database_triggered()
{
    QString path = QFileDialog::getSaveFileName(this,"New database",".","Database (*.db);;All file (*.*)");
    if(path != ""){
        this->dbPath = path;
        closeDatabase();
        clearTreeLog();
        connectDatabase();
    }
}

void MW::on_actionConnect_database_triggered()
{
    QString path = QFileDialog::getOpenFileName(this,"Connect database",".","Database (*.db);;All file (*.*)");
    if(path != ""){
        this->dbPath = path;
        closeDatabase();
        clearTreeLog();
        connectDatabase();
        importFromDB();
        loadEvent();
    }
}

void MW::on_actionExit_triggered()
{
    this->close();
}

void MW::on_actionConnect_relative_database_triggered()
{
    DatabasePath databasepath(this);
    databasepath.setPath(this->dbPath);
    databasepath.exec();
    databasepath.setModal(false);
    if(databasepath.changed()){
        this->dbPath = databasepath.getPath();
        closeDatabase();
        clearTreeLog();
        connectDatabase();
        importFromDB();
        loadEvent();
    }
}

void MW::on_btnSort_clicked()
{
    sortTreeWidget(ui->moneyList);
}

void MW::on_actionAbout_triggered()
{
    QMessageBox::information(this,"Version info",tr("Money Eat v%0").arg(VERSION));

}
