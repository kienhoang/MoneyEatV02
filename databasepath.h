#ifndef DATABASEPATH_H
#define DATABASEPATH_H

#include <QDialog>

namespace Ui {
class DatabasePath;
}

class DatabasePath : public QDialog
{
    Q_OBJECT

public:
    explicit DatabasePath(QWidget *parent = 0);
    ~DatabasePath();
    bool changed();
    void setPath(QString &path);
    QString getPath() const;
private slots:
    void on_btnOK_clicked();

    void on_btnCan_clicked();

private:
    Ui::DatabasePath *ui;
    bool isChanged;
    QString opath;
};

#endif // DATABASEPATH_H
