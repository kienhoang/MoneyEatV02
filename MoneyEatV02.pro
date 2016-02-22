#-------------------------------------------------
#
# Project created by QtCreator 2015-10-14T20:24:01
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MoneyEatV02
TEMPLATE = app


SOURCES += main.cpp\
        mw.cpp \
    editdate.cpp \
    editchilditem.cpp \
    log.cpp \
    money.cpp \
    databasepath.cpp

HEADERS  += mw.h \
    editdate.h \
    editchilditem.h \
    log.h \
    money.h \
    databasepath.h

FORMS    += mw.ui \
    editdate.ui \
    editchilditem.ui \
    log.ui \
    money.ui \
    databasepath.ui

CONFIG   += c++11

RESOURCES += \
    res.qrc

win32:RC_ICONS += money.ico

CONFIG += static
