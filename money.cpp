#include "money.h"
#include "ui_money.h"

Money::Money(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Money)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(10);
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

Money::~Money()
{
    delete ui;
}

void Money::setMoney(const QString &money){
    ui->lcdNumber->display(money);
}
