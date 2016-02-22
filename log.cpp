#include "log.h"
#include "ui_log.h"

Log::Log(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log)
{
    ui->setupUi(this);
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

Log::~Log()
{
    delete ui;
}
void Log::addEvent(const QString &event){
    ui->text->insertPlainText(event + "\n");
}
void Log::clear(){
    ui->text->clear();
}
