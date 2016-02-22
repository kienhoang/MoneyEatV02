#ifndef MONEY_H
#define MONEY_H

#include <QDialog>

namespace Ui {
class Money;
}

class Money : public QDialog
{
    Q_OBJECT

public:
    explicit Money(QWidget *parent = 0);
    ~Money();
void setMoney(const QString &money);
private:
    Ui::Money *ui;
};

#endif // MONEY_H
