#include "databasepath.h"
#include "ui_databasepath.h"
#include <QMessageBox>

DatabasePath::DatabasePath(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabasePath)
{
    ui->setupUi(this);
    isChanged = false;
    this->setFixedSize(this->width(),this->height());
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

DatabasePath::~DatabasePath()
{
    delete ui;
}

bool DatabasePath::changed(){
    return this->isChanged;
}

void DatabasePath::setPath(QString &path){
    this->opath = path;
    ui->lePath->setText(path);
}

QString DatabasePath::getPath() const{
    QString path = ui->lePath->text();
    QString ext = "";
	if(path.length() < 4){
		return path + ".db";
	}
	else{
		for(int i = path.length() - 3 ; i < path.length() ; i++){
			ext = ext + path.at(i);
		}
		if(ext != ".db"){
			return path + ".db";
		}else{
			return path;
		}
	}
}

void DatabasePath::on_btnOK_clicked()
{
    if(ui->lePath->text() != ""){
		isChanged = true;
        this->close();
    }
    else{
        QMessageBox::critical(this,"ERROR","The path field is empty.");
    }
}

void DatabasePath::on_btnCan_clicked()
{
    isChanged = false;
    this->close();
}
