/****************************************************************************
** Meta object code from reading C++ file 'maincontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../controller/maincontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maincontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainController_t {
    QByteArrayData data[10];
    char stringdata[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainController_t qt_meta_stringdata_MainController = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 9),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 9),
QT_MOC_LITERAL(4, 36, 9),
QT_MOC_LITERAL(5, 46, 13),
QT_MOC_LITERAL(6, 60, 6),
QT_MOC_LITERAL(7, 67, 30),
QT_MOC_LITERAL(8, 98, 5),
QT_MOC_LITERAL(9, 104, 30)
    },
    "MainController\0exit_game\0\0show_game\0"
    "show_menu\0show_end_menu\0winner\0"
    "onWhitePlayerVirtualityChanged\0value\0"
    "onBlackPlayerVirtualityChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a,
       3,    0,   45,    2, 0x0a,
       4,    0,   46,    2, 0x0a,
       5,    1,   47,    2, 0x0a,
       7,    1,   50,    2, 0x08,
       9,    1,   53,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void MainController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainController *_t = static_cast<MainController *>(_o);
        switch (_id) {
        case 0: _t->exit_game(); break;
        case 1: _t->show_game(); break;
        case 2: _t->show_menu(); break;
        case 3: _t->show_end_menu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onWhitePlayerVirtualityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onBlackPlayerVirtualityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainController.data,
      qt_meta_data_MainController,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainController.stringdata))
        return static_cast<void*>(const_cast< MainController*>(this));
    return QObject::qt_metacast(_clname);
}

int MainController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
