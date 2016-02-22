/********************************************************************************
** Form generated from reading UI file 'editdate.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDATE_H
#define UI_EDITDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditDate
{
public:
    QCalendarWidget *calendarWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbDate;
    QDateEdit *date;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnOK;
    QPushButton *btnCan;

    void setupUi(QDialog *EditDate)
    {
        if (EditDate->objectName().isEmpty())
            EditDate->setObjectName(QStringLiteral("EditDate"));
        EditDate->resize(323, 267);
        calendarWidget = new QCalendarWidget(EditDate);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 10, 296, 183));
        layoutWidget = new QWidget(EditDate);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 200, 221, 61));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbDate = new QLabel(layoutWidget);
        lbDate->setObjectName(QStringLiteral("lbDate"));

        horizontalLayout->addWidget(lbDate);

        date = new QDateEdit(layoutWidget);
        date->setObjectName(QStringLiteral("date"));

        horizontalLayout->addWidget(date);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnOK = new QPushButton(layoutWidget);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        horizontalLayout_2->addWidget(btnOK);

        btnCan = new QPushButton(layoutWidget);
        btnCan->setObjectName(QStringLiteral("btnCan"));

        horizontalLayout_2->addWidget(btnCan);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(EditDate);

        QMetaObject::connectSlotsByName(EditDate);
    } // setupUi

    void retranslateUi(QDialog *EditDate)
    {
        EditDate->setWindowTitle(QApplication::translate("EditDate", "Edit Date", 0));
        lbDate->setText(QApplication::translate("EditDate", "Change Date", 0));
        btnOK->setText(QApplication::translate("EditDate", "OK", 0));
        btnCan->setText(QApplication::translate("EditDate", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class EditDate: public Ui_EditDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDATE_H
