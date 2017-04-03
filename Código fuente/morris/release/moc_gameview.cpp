/****************************************************************************
** Meta object code from reading C++ file 'gameview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../view/gameview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameView_t {
    QByteArrayData data[18];
    char stringdata[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GameView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GameView_t qt_meta_stringdata_GameView = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 18),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 6),
QT_MOC_LITERAL(4, 36, 19),
QT_MOC_LITERAL(5, 56, 19),
QT_MOC_LITERAL(6, 76, 2),
QT_MOC_LITERAL(7, 79, 12),
QT_MOC_LITERAL(8, 92, 8),
QT_MOC_LITERAL(9, 101, 8),
QT_MOC_LITERAL(10, 110, 11),
QT_MOC_LITERAL(11, 122, 6),
QT_MOC_LITERAL(12, 129, 9),
QT_MOC_LITERAL(13, 139, 11),
QT_MOC_LITERAL(14, 151, 4),
QT_MOC_LITERAL(15, 156, 10),
QT_MOC_LITERAL(16, 167, 7),
QT_MOC_LITERAL(17, 175, 14)
    },
    "GameView\0triggerVertexClick\0\0vertex\0"
    "triggerAnimationEnd\0triggerUpdateSelect\0"
    "id\0showMovement\0Movement\0movement\0"
    "onSetPlayer\0player\0showError\0std::string\0"
    "text\0clearError\0animate\0popSourcePiece\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x05,
       4,    0,   62,    2, 0x05,
       5,    1,   63,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    1,   66,    2, 0x0a,
      10,    1,   69,    2, 0x0a,
      12,    1,   72,    2, 0x0a,
      15,    0,   75,    2, 0x0a,
      16,    0,   76,    2, 0x0a,
      17,    1,   77,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void GameView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameView *_t = static_cast<GameView *>(_o);
        switch (_id) {
        case 0: _t->triggerVertexClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->triggerAnimationEnd(); break;
        case 2: _t->triggerUpdateSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->showMovement((*reinterpret_cast< Movement(*)>(_a[1]))); break;
        case 4: _t->onSetPlayer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->showError((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 6: _t->clearError(); break;
        case 7: _t->animate(); break;
        case 8: _t->popSourcePiece((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameView::triggerVertexClick)) {
                *result = 0;
            }
        }
        {
            typedef void (GameView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameView::triggerAnimationEnd)) {
                *result = 1;
            }
        }
        {
            typedef void (GameView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameView::triggerUpdateSelect)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject GameView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameView.data,
      qt_meta_data_GameView,  qt_static_metacall, 0, 0}
};


const QMetaObject *GameView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameView.stringdata))
        return static_cast<void*>(const_cast< GameView*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GameView::triggerVertexClick(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameView::triggerAnimationEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GameView::triggerUpdateSelect(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
