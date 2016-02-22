#include "editchilditem.h"
#include "ui_editchilditem.h"
#include <QDebug>
#include <QMessageBox>

EditChildItem::EditChildItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditChildItem)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->spMoney->setSingleStep(1000);
}

EditChildItem::~EditChildItem()
{
    delete ui;
}

void EditChildItem::setItem(const QString &item){
    this->item = item;
    ui->leItem->setText(this->item);
}

void EditChildItem::setMoney(const QString &money){
    this->money = money;
    ui->spMoney->setValue(this->money.toInt());
}

QString EditChildItem::getItem() const {
    return this->item;
}

QString EditChildItem::getMoney() const {
    return this->money;
}

void EditChildItem::on_btnOK_clicked()
{
    if(ui->leItem->text() == this->item && ui->spMoney->text() == this->money){
        this->isUpdate = false;
        this->close();
    }else{
        if(ui->leItem->text() != ""){
            this->item = ui->leItem->text();
            this->money = ui->spMoney->text();
            this->isUpdate = true;
#ifdef _DEBUG
            qDebug() <<"Changed Values to " + this->item +" " + this->money;
#endif
            this->close();
        }else{
            QMessageBox::information(this,"ERROR", "Item Field cannot be empty.");
        }
    }
}

void EditChildItem::on_btnCan_clicked()
{
    this->isUpdate = false;
    this->close();
}

bool EditChildItem::Update(){
    return this->isUpdate;
}
