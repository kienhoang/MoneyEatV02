#ifndef MW_H
#define MW_H

#include <QMainWindow>
#include <QtSql>
#include <QSettings>
#include <QMessageBox>
#include <QDate>
#include <QTreeWidgetItem>
#include "enter.h"
#include "log.h"
#include <QLabel>

#ifdef _DEBUG
#undef _DEBUG
#endif

#define VERSION "1.0.3"

namespace Ui {
class MW;
}

class MW : public QMainWindow
{
    Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event);
public:
    explicit MW(QWidget *parent = 0);
    ~MW();
protected:
    void closeEvent(QCloseEvent *);
public:

    void saveSetting();
    void loadSetting();
    void connectDatabase();
    void closeDatabase();
    void createEvent(QString event);
    void loadEvent();
    QTreeWidgetItem * addEventToTree(QDate &date,QString &event, unsigned int money, QString &id);
    bool addEventToDB(QDate &date, QString &event, unsigned int money, QString &id);
    void connectEvent();
    void calcTotalTop(QTreeWidgetItem * item);
    void calcAllTop();
    QString generateID();
    void importFromDB();
    void deleteItem(QTreeWidgetItem * item);
    void editItem(QTreeWidgetItem * item);
    void reLoadTree();
    void clearTreeLog();
    unsigned int totalMoney();
    void swapItem(QTreeWidgetItem *item1, QTreeWidgetItem *item2);
    void sortTreeWidget(QTreeWidget * treeWidget);
public slots:
    void calendarChanged();
    void dateChanged();
    void onDoubleClick();
    void showContextMenu(const QPoint &pos);
private slots:
    void on_btnAddItem_clicked();

    void on_btnDelete_clicked();

    void on_btnToday_clicked();
    void on_btnEdit_clicked();

    void on_btnLog_clicked();

    void on_btnCalc_clicked();

    void on_actionNew_database_triggered();

    void on_actionConnect_database_triggered();

    void on_actionExit_triggered();

    void on_actionConnect_relative_database_triggered();

    void on_btnSort_clicked();

    void on_actionAbout_triggered();

private:
    Ui::MW *ui;
    QSqlDatabase db;
    QSqlQuery * qry;
    QString dbPath;
    QString sqry;
    Log * log;
    QLabel * statusLabel;
};

#endif // MW_H
