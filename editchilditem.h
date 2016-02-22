#ifndef EDITCHILDITEM_H
#define EDITCHILDITEM_H

#include <QDialog>

namespace Ui {
class EditChildItem;
}

class EditChildItem : public QDialog
{
    Q_OBJECT

public:
    explicit EditChildItem(QWidget *parent = 0);
    ~EditChildItem();
    void setItem(const QString &item);
    void setMoney(const QString &money);
    QString getItem() const;
    QString getMoney() const;
    bool Update();
private slots:
    void on_btnOK_clicked();

    void on_btnCan_clicked();

private:
    Ui::EditChildItem *ui;
    QString item;
    QString money;
    bool isUpdate;
};

#endif // EDITCHILDITEM_H
