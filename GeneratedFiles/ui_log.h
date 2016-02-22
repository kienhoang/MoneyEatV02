/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Log
{
public:
    QHBoxLayout *horizontalLayout;
    QTextEdit *text;

    void setupUi(QDialog *Log)
    {
        if (Log->objectName().isEmpty())
            Log->setObjectName(QStringLiteral("Log"));
        Log->resize(385, 396);
        horizontalLayout = new QHBoxLayout(Log);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        text = new QTextEdit(Log);
        text->setObjectName(QStringLiteral("text"));
        text->setReadOnly(true);
        text->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(text);


        retranslateUi(Log);

        QMetaObject::connectSlotsByName(Log);
    } // setupUi

    void retranslateUi(QDialog *Log)
    {
        Log->setWindowTitle(QApplication::translate("Log", "Log", 0));
    } // retranslateUi

};

namespace Ui {
    class Log: public Ui_Log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
