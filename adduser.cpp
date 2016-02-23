#include "adduser.h"
#include "ui_adduser.h"
#include <QMessageBox>
#include <QDebug>

Adduser::Adduser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adduser)
{
    ui->setupUi(this);
}

Adduser::~Adduser()
{
    delete ui;
}

void Adduser::setDBpath(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    if (!db.open()){
        qDebug() << "Error in open Database";
        QMessageBox::critical(this,"ERROR","Error in open database: " + path);
        usr = "";
    }else{
        qDebug() << "ADDUSER: Opened Database";
    }
    qry = new QSqlQuery(db);
}

QString Adduser::getUsr()
{
    return this->usr;
}

void Adduser::closeDB()
{
    this->db.close();
    this->db.removeDatabase(QSqlDatabase::defaultConnection);
}

void Adduser::on_btnAdd_clicked()
{
    usr = ui->leUsr->text();
    des = ui->txtDes->toPlainText();
    QString sqry = "SELECT * FROM user WHERE usr='" + usr + "';";
    int count = 0;
    if(qry->exec(sqry)){
        while(qry->next()){
            count++;
        }
    }

    if (!count && usr != ""){
        sqry = "INSERT INTO user VALUES ('" + usr + "','" + des +"');";
        if (qry->exec(sqry)){
            qDebug() << "Done";

            sqry = "CREATE TABLE IF NOT EXISTS money_" + usr +
                    " (date VARCHAR NOT NULL, event VARCHAR, money INTEGER NOT NULL, id INTEGER PRIMARY KEY NOT NULL);";
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
            sqry = "CREATE TABLE IF NOT EXISTS history_" + usr +
                    " (date VARCHAR NOT NULL, event VARCHAR);";
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
        }else{
            qDebug() << "ERROR in add User into user";
            QMessageBox::critical(this,"ERROR","ERROR in create user");
            usr = "";
        }
        closeDB();
        this->close();
    }else{
        if (usr == ""){
            QMessageBox::critical(this,"ERROR","Username must not be empty");
        }else{
            QMessageBox::critical(this,"ERROR","Username is exists.");
        }
    }
}

void Adduser::on_btnCancel_clicked()
{
    usr = "";
    closeDB();
    this->close();
}
