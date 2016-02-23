/****************************************************************************
** Meta object code from reading C++ file 'mw.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mw.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MW_t {
    QByteArrayData data[22];
    char stringdata0[442];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MW_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MW_t qt_meta_stringdata_MW = {
    {
QT_MOC_LITERAL(0, 0, 2), // "MW"
QT_MOC_LITERAL(1, 3, 15), // "calendarChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "dateChanged"
QT_MOC_LITERAL(4, 32, 13), // "onDoubleClick"
QT_MOC_LITERAL(5, 46, 15), // "showContextMenu"
QT_MOC_LITERAL(6, 62, 3), // "pos"
QT_MOC_LITERAL(7, 66, 21), // "on_btnAddItem_clicked"
QT_MOC_LITERAL(8, 88, 20), // "on_btnDelete_clicked"
QT_MOC_LITERAL(9, 109, 19), // "on_btnToday_clicked"
QT_MOC_LITERAL(10, 129, 18), // "on_btnEdit_clicked"
QT_MOC_LITERAL(11, 148, 17), // "on_btnLog_clicked"
QT_MOC_LITERAL(12, 166, 18), // "on_btnCalc_clicked"
QT_MOC_LITERAL(13, 185, 31), // "on_actionNew_database_triggered"
QT_MOC_LITERAL(14, 217, 35), // "on_actionConnect_database_tri..."
QT_MOC_LITERAL(15, 253, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(16, 277, 44), // "on_actionConnect_relative_dat..."
QT_MOC_LITERAL(17, 322, 18), // "on_btnSort_clicked"
QT_MOC_LITERAL(18, 341, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(19, 366, 18), // "on_btnLoad_clicked"
QT_MOC_LITERAL(20, 385, 25), // "on_btnDescription_clicked"
QT_MOC_LITERAL(21, 411, 30) // "on_actionAdd_Account_triggered"

    },
    "MW\0calendarChanged\0\0dateChanged\0"
    "onDoubleClick\0showContextMenu\0pos\0"
    "on_btnAddItem_clicked\0on_btnDelete_clicked\0"
    "on_btnToday_clicked\0on_btnEdit_clicked\0"
    "on_btnLog_clicked\0on_btnCalc_clicked\0"
    "on_actionNew_database_triggered\0"
    "on_actionConnect_database_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionConnect_relative_database_triggered\0"
    "on_btnSort_clicked\0on_actionAbout_triggered\0"
    "on_btnLoad_clicked\0on_btnDescription_clicked\0"
    "on_actionAdd_Account_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MW[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x0a /* Public */,
       3,    0,  110,    2, 0x0a /* Public */,
       4,    0,  111,    2, 0x0a /* Public */,
       5,    1,  112,    2, 0x0a /* Public */,
       7,    0,  115,    2, 0x08 /* Private */,
       8,    0,  116,    2, 0x08 /* Private */,
       9,    0,  117,    2, 0x08 /* Private */,
      10,    0,  118,    2, 0x08 /* Private */,
      11,    0,  119,    2, 0x08 /* Private */,
      12,    0,  120,    2, 0x08 /* Private */,
      13,    0,  121,    2, 0x08 /* Private */,
      14,    0,  122,    2, 0x08 /* Private */,
      15,    0,  123,    2, 0x08 /* Private */,
      16,    0,  124,    2, 0x08 /* Private */,
      17,    0,  125,    2, 0x08 /* Private */,
      18,    0,  126,    2, 0x08 /* Private */,
      19,    0,  127,    2, 0x08 /* Private */,
      20,    0,  128,    2, 0x08 /* Private */,
      21,    0,  129,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MW::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MW *_t = static_cast<MW *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->calendarChanged(); break;
        case 1: _t->dateChanged(); break;
        case 2: _t->onDoubleClick(); break;
        case 3: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->on_btnAddItem_clicked(); break;
        case 5: _t->on_btnDelete_clicked(); break;
        case 6: _t->on_btnToday_clicked(); break;
        case 7: _t->on_btnEdit_clicked(); break;
        case 8: _t->on_btnLog_clicked(); break;
        case 9: _t->on_btnCalc_clicked(); break;
        case 10: _t->on_actionNew_database_triggered(); break;
        case 11: _t->on_actionConnect_database_triggered(); break;
        case 12: _t->on_actionExit_triggered(); break;
        case 13: _t->on_actionConnect_relative_database_triggered(); break;
        case 14: _t->on_btnSort_clicked(); break;
        case 15: _t->on_actionAbout_triggered(); break;
        case 16: _t->on_btnLoad_clicked(); break;
        case 17: _t->on_btnDescription_clicked(); break;
        case 18: _t->on_actionAdd_Account_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MW::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MW.data,
      qt_meta_data_MW,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MW::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MW::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MW.stringdata0))
        return static_cast<void*>(const_cast< MW*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MW::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
