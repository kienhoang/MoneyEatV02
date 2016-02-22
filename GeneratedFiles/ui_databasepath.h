/********************************************************************************
** Form generated from reading UI file 'databasepath.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEPATH_H
#define UI_DATABASEPATH_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabasePath
{
public:
    QLineEdit *lePath;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOK;
    QPushButton *btnCan;

    void setupUi(QDialog *DatabasePath)
    {
        if (DatabasePath->objectName().isEmpty())
            DatabasePath->setObjectName(QStringLiteral("DatabasePath"));
        DatabasePath->resize(331, 91);
        lePath = new QLineEdit(DatabasePath);
        lePath->setObjectName(QStringLiteral("lePath"));
        lePath->setGeometry(QRect(10, 30, 311, 21));
        label = new QLabel(DatabasePath);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 451, 16));
        widget = new QWidget(DatabasePath);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(160, 60, 161, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnOK = new QPushButton(widget);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        horizontalLayout->addWidget(btnOK);

        btnCan = new QPushButton(widget);
        btnCan->setObjectName(QStringLiteral("btnCan"));

        horizontalLayout->addWidget(btnCan);


        retranslateUi(DatabasePath);

        QMetaObject::connectSlotsByName(DatabasePath);
    } // setupUi

    void retranslateUi(QDialog *DatabasePath)
    {
        DatabasePath->setWindowTitle(QApplication::translate("DatabasePath", "Set Path of Database", 0));
        label->setText(QApplication::translate("DatabasePath", "( Extention \"*.db\" automatic add if path does not content \"*.db\")", 0));
        btnOK->setText(QApplication::translate("DatabasePath", "OK", 0));
        btnCan->setText(QApplication::translate("DatabasePath", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class DatabasePath: public Ui_DatabasePath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEPATH_H
