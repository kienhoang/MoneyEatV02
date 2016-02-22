/********************************************************************************
** Form generated from reading UI file 'editchilditem.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCHILDITEM_H
#define UI_EDITCHILDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditChildItem
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lbItem;
    QLabel *lbMoney;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *leItem;
    QSpinBox *spMoney;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnOK;
    QPushButton *btnCan;

    void setupUi(QDialog *EditChildItem)
    {
        if (EditChildItem->objectName().isEmpty())
            EditChildItem->setObjectName(QStringLiteral("EditChildItem"));
        EditChildItem->resize(281, 77);
        layoutWidget = new QWidget(EditChildItem);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 260, 56));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lbItem = new QLabel(layoutWidget);
        lbItem->setObjectName(QStringLiteral("lbItem"));

        verticalLayout->addWidget(lbItem);

        lbMoney = new QLabel(layoutWidget);
        lbMoney->setObjectName(QStringLiteral("lbMoney"));

        verticalLayout->addWidget(lbMoney);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        leItem = new QLineEdit(layoutWidget);
        leItem->setObjectName(QStringLiteral("leItem"));

        verticalLayout_2->addWidget(leItem);

        spMoney = new QSpinBox(layoutWidget);
        spMoney->setObjectName(QStringLiteral("spMoney"));
        spMoney->setMaximum(999999999);

        verticalLayout_2->addWidget(spMoney);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        btnOK = new QPushButton(layoutWidget);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        verticalLayout_3->addWidget(btnOK);

        btnCan = new QPushButton(layoutWidget);
        btnCan->setObjectName(QStringLiteral("btnCan"));

        verticalLayout_3->addWidget(btnCan);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(EditChildItem);

        QMetaObject::connectSlotsByName(EditChildItem);
    } // setupUi

    void retranslateUi(QDialog *EditChildItem)
    {
        EditChildItem->setWindowTitle(QApplication::translate("EditChildItem", "Edit Item", 0));
        lbItem->setText(QApplication::translate("EditChildItem", "Item", 0));
        lbMoney->setText(QApplication::translate("EditChildItem", "Money", 0));
        btnOK->setText(QApplication::translate("EditChildItem", "OK", 0));
        btnCan->setText(QApplication::translate("EditChildItem", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class EditChildItem: public Ui_EditChildItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCHILDITEM_H
