/********************************************************************************
** Form generated from reading UI file 'money.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONEY_H
#define UI_MONEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Money
{
public:
    QVBoxLayout *verticalLayout;
    QLCDNumber *lcdNumber;

    void setupUi(QDialog *Money)
    {
        if (Money->objectName().isEmpty())
            Money->setObjectName(QStringLiteral("Money"));
        Money->resize(564, 133);
        verticalLayout = new QVBoxLayout(Money);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lcdNumber = new QLCDNumber(Money);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        verticalLayout->addWidget(lcdNumber);


        retranslateUi(Money);

        QMetaObject::connectSlotsByName(Money);
    } // setupUi

    void retranslateUi(QDialog *Money)
    {
        Money->setWindowTitle(QApplication::translate("Money", "Total Money", 0));
    } // retranslateUi

};

namespace Ui {
    class Money: public Ui_Money {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONEY_H
