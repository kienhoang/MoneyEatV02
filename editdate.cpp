#include "editdate.h"
#include "ui_editdate.h"
#include <QDebug>

EditDate::EditDate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDate)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(ui->calendarWidget,SIGNAL(selectionChanged()),this,SLOT(calendarChanged()));
    connect(ui->date,SIGNAL(dateChanged(QDate)),this,SLOT(_dateChanged()));
}

EditDate::~EditDate()
{
    delete ui;
}

void EditDate::calendarChanged(){
    ui->date->setDate(ui->calendarWidget->selectedDate());
}
void EditDate::_dateChanged(){
    ui->calendarWidget->setSelectedDate(ui->date->date());
}

void EditDate::setDate(QDate &date){
    this->date = date;
    ui->date->setDate(this->date);
}

QDate EditDate::getDate(){
    return this->date;
}

void EditDate::on_btnOK_clicked()
{
    if (date == ui->date->date()){
        this->isUpdate = false;
    }else{
        this->date = ui->date->date();
#ifdef _DEBUG
        qDebug() << "Changed value to " + this->date.toString("dd/MM/yyyy");
#endif
        this->isUpdate = true;
    }
    this->close();
}


void EditDate::on_btnCan_clicked()
{
#ifdef _DEBUG
    qDebug() << "Canceled";
#endif
    this->isUpdate = false;
    this->close();
}

bool EditDate::Update(){
    return this->isUpdate;
}
