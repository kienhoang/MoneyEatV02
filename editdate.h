#ifndef EDITDATE_H
#define EDITDATE_H

#include <QDialog>
#include <QDate>

namespace Ui {
class EditDate;
}

class EditDate : public QDialog
{
    Q_OBJECT

public:
    explicit EditDate(QWidget *parent = 0);
    ~EditDate();
    void setDate(QDate &date);
    QDate getDate();
    bool Update();
public slots:
    void calendarChanged();
    void _dateChanged();
private slots:
    void on_btnOK_clicked();

    void on_btnCan_clicked();

private:
    Ui::EditDate *ui;
    QDate date;
    bool isUpdate;
};

#endif // EDITDATE_H
