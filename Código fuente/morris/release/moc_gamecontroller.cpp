/****************************************************************************
** Meta object code from reading C++ file 'gamecontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../controller/gamecontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamecontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameController_t {
    QByteArrayData data[21];
    char stringdata[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GameController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GameController_t qt_meta_stringdata_GameController = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 10),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 6),
QT_MOC_LITERAL(4, 34, 16),
QT_MOC_LITERAL(5, 51, 11),
QT_MOC_LITERAL(6, 63, 4),
QT_MOC_LITERAL(7, 68, 21),
QT_MOC_LITERAL(8, 90, 20),
QT_MOC_LITERAL(9, 111, 6),
QT_MOC_LITERAL(10, 118, 23),
QT_MOC_LITERAL(11, 142, 8),
QT_MOC_LITERAL(12, 151, 8),
QT_MOC_LITERAL(13, 160, 21),
QT_MOC_LITERAL(14, 182, 12),
QT_MOC_LITERAL(15, 195, 13),
QT_MOC_LITERAL(16, 209, 6),
QT_MOC_LITERAL(17, 216, 7),
QT_MOC_LITERAL(18, 224, 9),
QT_MOC_LITERAL(19, 234, 6),
QT_MOC_LITERAL(20, 241, 14)
    },
    "GameController\0triggerEnd\0\0winner\0"
    "triggerViewError\0std::string\0text\0"
    "triggerViewClearError\0triggerViewSetPlayer\0"
    "player\0triggerViewShowMovement\0Movement\0"
    "movement\0triggerPopSourcePiece\0"
    "playerColour\0onVertexClick\0vertex\0"
    "onPause\0onRestart\0onQuit\0onAnimationEnd\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x05,
       4,    1,   72,    2, 0x05,
       7,    0,   75,    2, 0x05,
       8,    1,   76,    2, 0x05,
      10,    1,   79,    2, 0x05,
      13,    1,   82,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      15,    1,   85,    2, 0x0a,
      17,    0,   88,    2, 0x0a,
      18,    0,   89,    2, 0x0a,
      19,    0,   90,    2, 0x0a,
      20,    0,   91,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameController *_t = static_cast<GameController *>(_o);
        switch (_id) {
        case 0: _t->triggerEnd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->triggerViewError((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->triggerViewClearError(); break;
        case 3: _t->triggerViewSetPlayer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->triggerViewShowMovement((*reinterpret_cast< Movement(*)>(_a[1]))); break;
        case 5: _t->triggerPopSourcePiece((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onVertexClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onPause(); break;
        case 8: _t->onRestart(); break;
        case 9: _t->onQuit(); break;
        case 10: _t->onAnimationEnd(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::triggerEnd)) {
                *result = 0;
            }
        }
        {
            typedef void (GameController::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::triggerViewError)) {
                *result = 1;
            }
        }
        {
            typedef void (GameController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::triggerViewClearError)) {
                *result = 2;
            }
        }
        {
            typedef void (GameController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::triggerViewSetPlayer)) {
                *result = 3;
            }
        }
        {
            typedef void (GameController::*_t)(Movement );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::triggerViewShowMovement)) {
                *result = 4;
            }
        }
        {
            typedef void (GameController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::triggerPopSourcePiece)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject GameController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameController.data,
      qt_meta_data_GameController,  qt_static_metacall, 0, 0}
};


const QMetaObject *GameController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameController.stringdata))
        return static_cast<void*>(const_cast< GameController*>(this));
    return QObject::qt_metacast(_clname);
}

int GameController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void GameController::triggerEnd(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameController::triggerViewError(std::string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameController::triggerViewClearError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GameController::triggerViewSetPlayer(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GameController::triggerViewShowMovement(Movement _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GameController::triggerPopSourcePiece(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
