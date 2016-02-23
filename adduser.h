#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Adduser;
}

class Adduser : public QDialog
{
    Q_OBJECT

public:
    explicit Adduser(QWidget *parent = 0);
    ~Adduser();
    void setDBpath(const QString & path);
    QString getUsr();
    void closeDB();
private slots:
    void on_btnAdd_clicked();

    void on_btnCancel_clicked();

private:
    Ui::Adduser *ui;
    QString usr, des, dbpath;
    QSqlDatabase db;
    QSqlQuery * qry;
};

#endif // ADDUSER_H
