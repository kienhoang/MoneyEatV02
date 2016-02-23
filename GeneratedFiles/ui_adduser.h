/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Adduser
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *lbUsr;
    QLineEdit *leUsr;
    QLabel *lbDescription;
    QPlainTextEdit *txtDes;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAdd;
    QPushButton *btnCancel;

    void setupUi(QDialog *Adduser)
    {
        if (Adduser->objectName().isEmpty())
            Adduser->setObjectName(QStringLiteral("Adduser"));
        Adduser->resize(361, 260);
        verticalLayout_2 = new QVBoxLayout(Adduser);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lbUsr = new QLabel(Adduser);
        lbUsr->setObjectName(QStringLiteral("lbUsr"));

        verticalLayout->addWidget(lbUsr);

        leUsr = new QLineEdit(Adduser);
        leUsr->setObjectName(QStringLiteral("leUsr"));

        verticalLayout->addWidget(leUsr);

        lbDescription = new QLabel(Adduser);
        lbDescription->setObjectName(QStringLiteral("lbDescription"));

        verticalLayout->addWidget(lbDescription);

        txtDes = new QPlainTextEdit(Adduser);
        txtDes->setObjectName(QStringLiteral("txtDes"));

        verticalLayout->addWidget(txtDes);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnAdd = new QPushButton(Adduser);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));

        horizontalLayout->addWidget(btnAdd);

        btnCancel = new QPushButton(Adduser);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Adduser);

        QMetaObject::connectSlotsByName(Adduser);
    } // setupUi

    void retranslateUi(QDialog *Adduser)
    {
        Adduser->setWindowTitle(QApplication::translate("Adduser", "Dialog", 0));
        lbUsr->setText(QApplication::translate("Adduser", "Username", 0));
        lbDescription->setText(QApplication::translate("Adduser", "Description", 0));
        btnAdd->setText(QApplication::translate("Adduser", "Create user", 0));
        btnCancel->setText(QApplication::translate("Adduser", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Adduser: public Ui_Adduser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
