/********************************************************************************
** Form generated from reading UI file 'mw.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MW_H
#define UI_MW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MW
{
public:
    QAction *actionConnect_database;
    QAction *actionNew_database;
    QAction *actionExit;
    QAction *actionConnect_relative_database;
    QAction *actionAbout;
    QWidget *centralWidget;
    QCalendarWidget *calendar;
    QTreeWidget *moneyList;
    QPushButton *btnAddItem;
    QPushButton *btnDelete;
    QPushButton *btnEdit;
    QPushButton *btnLog;
    QPushButton *btnCalc;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbDate;
    QLabel *lbItem;
    QLabel *lbMoney;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDateEdit *date;
    QPushButton *btnToday;
    QLineEdit *leItem;
    QSpinBox *sbMoney;
    QPushButton *btnSort;
    QMenuBar *menuBar;
    QMenu *menuOption;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MW)
    {
        if (MW->objectName().isEmpty())
            MW->setObjectName(QStringLiteral("MW"));
        MW->resize(612, 398);
        actionConnect_database = new QAction(MW);
        actionConnect_database->setObjectName(QStringLiteral("actionConnect_database"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect_database->setIcon(icon);
        actionNew_database = new QAction(MW);
        actionNew_database->setObjectName(QStringLiteral("actionNew_database"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/new.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_database->setIcon(icon1);
        actionExit = new QAction(MW);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/exit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionConnect_relative_database = new QAction(MW);
        actionConnect_relative_database->setObjectName(QStringLiteral("actionConnect_relative_database"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/img/connect.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect_relative_database->setIcon(icon3);
        actionAbout = new QAction(MW);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MW);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        calendar = new QCalendarWidget(centralWidget);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setGeometry(QRect(11, 10, 296, 191));
        moneyList = new QTreeWidget(centralWidget);
        moneyList->setObjectName(QStringLiteral("moneyList"));
        moneyList->setGeometry(QRect(320, 10, 281, 291));
        btnAddItem = new QPushButton(centralWidget);
        btnAddItem->setObjectName(QStringLiteral("btnAddItem"));
        btnAddItem->setGeometry(QRect(10, 300, 101, 31));
        btnDelete = new QPushButton(centralWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setGeometry(QRect(510, 310, 91, 23));
        btnEdit = new QPushButton(centralWidget);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));
        btnEdit->setGeometry(QRect(410, 310, 91, 23));
        btnLog = new QPushButton(centralWidget);
        btnLog->setObjectName(QStringLiteral("btnLog"));
        btnLog->setGeometry(QRect(230, 300, 81, 31));
        btnCalc = new QPushButton(centralWidget);
        btnCalc->setObjectName(QStringLiteral("btnCalc"));
        btnCalc->setGeometry(QRect(120, 300, 101, 31));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(13, 210, 291, 81));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lbDate = new QLabel(layoutWidget);
        lbDate->setObjectName(QStringLiteral("lbDate"));

        verticalLayout_2->addWidget(lbDate);

        lbItem = new QLabel(layoutWidget);
        lbItem->setObjectName(QStringLiteral("lbItem"));

        verticalLayout_2->addWidget(lbItem);

        lbMoney = new QLabel(layoutWidget);
        lbMoney->setObjectName(QStringLiteral("lbMoney"));

        verticalLayout_2->addWidget(lbMoney);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        date = new QDateEdit(layoutWidget);
        date->setObjectName(QStringLiteral("date"));

        horizontalLayout->addWidget(date);

        btnToday = new QPushButton(layoutWidget);
        btnToday->setObjectName(QStringLiteral("btnToday"));

        horizontalLayout->addWidget(btnToday);


        verticalLayout->addLayout(horizontalLayout);

        leItem = new QLineEdit(layoutWidget);
        leItem->setObjectName(QStringLiteral("leItem"));

        verticalLayout->addWidget(leItem);

        sbMoney = new QSpinBox(layoutWidget);
        sbMoney->setObjectName(QStringLiteral("sbMoney"));
        sbMoney->setMaximum(999999999);
        sbMoney->setSingleStep(1000);

        verticalLayout->addWidget(sbMoney);


        horizontalLayout_2->addLayout(verticalLayout);

        btnSort = new QPushButton(centralWidget);
        btnSort->setObjectName(QStringLiteral("btnSort"));
        btnSort->setGeometry(QRect(324, 310, 81, 23));
        MW->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MW);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 612, 21));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QStringLiteral("menuOption"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MW->setMenuBar(menuBar);
        statusBar = new QStatusBar(MW);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MW->setStatusBar(statusBar);
        QWidget::setTabOrder(leItem, sbMoney);
        QWidget::setTabOrder(sbMoney, btnAddItem);
        QWidget::setTabOrder(btnAddItem, btnDelete);
        QWidget::setTabOrder(btnDelete, btnEdit);
        QWidget::setTabOrder(btnEdit, date);
        QWidget::setTabOrder(date, btnToday);
        QWidget::setTabOrder(btnToday, calendar);
        QWidget::setTabOrder(calendar, moneyList);

        menuBar->addAction(menuOption->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuOption->addAction(actionNew_database);
        menuOption->addAction(actionConnect_database);
        menuOption->addSeparator();
        menuOption->addAction(actionConnect_relative_database);
        menuOption->addSeparator();
        menuOption->addAction(actionExit);
        menuAbout->addAction(actionAbout);

        retranslateUi(MW);

        QMetaObject::connectSlotsByName(MW);
    } // setupUi

    void retranslateUi(QMainWindow *MW)
    {
        MW->setWindowTitle(QApplication::translate("MW", "Money List", 0));
        actionConnect_database->setText(QApplication::translate("MW", "&Connect database", 0));
        actionConnect_database->setShortcut(QApplication::translate("MW", "Ctrl+O", 0));
        actionNew_database->setText(QApplication::translate("MW", "&New database", 0));
        actionNew_database->setShortcut(QApplication::translate("MW", "Ctrl+N", 0));
        actionExit->setText(QApplication::translate("MW", "Exit", 0));
        actionConnect_relative_database->setText(QApplication::translate("MW", "C&onnect relative database", 0));
        actionConnect_relative_database->setShortcut(QApplication::translate("MW", "F12", 0));
        actionAbout->setText(QApplication::translate("MW", "About", 0));
        QTreeWidgetItem *___qtreewidgetitem = moneyList->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("MW", "ID", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MW", "Total", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MW", "Date", 0));
        btnAddItem->setText(QApplication::translate("MW", "Add", 0));
        btnDelete->setText(QApplication::translate("MW", "Delete", 0));
        btnEdit->setText(QApplication::translate("MW", "Edit", 0));
        btnLog->setText(QApplication::translate("MW", "View Log", 0));
        btnCalc->setText(QApplication::translate("MW", "Caculator", 0));
        lbDate->setText(QApplication::translate("MW", "Date", 0));
        lbItem->setText(QApplication::translate("MW", "Item", 0));
        lbMoney->setText(QApplication::translate("MW", "Money", 0));
        btnToday->setText(QApplication::translate("MW", "Go Today", 0));
        btnSort->setText(QApplication::translate("MW", "Sort By Date", 0));
        menuOption->setTitle(QApplication::translate("MW", "Option", 0));
        menuAbout->setTitle(QApplication::translate("MW", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MW: public Ui_MW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MW_H
