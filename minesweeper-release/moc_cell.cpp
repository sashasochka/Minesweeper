/****************************************************************************
** Meta object code from reading C++ file 'cell.h'
**
** Created: Mon Jan 7 12:17:36 2013
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/cell.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cell.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Cell_t {
    QByteArrayData data[19];
    char stringdata[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Cell_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Cell_t qt_meta_stringdata_Cell = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 18),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 10),
QT_MOC_LITERAL(4, 36, 12),
QT_MOC_LITERAL(5, 49, 6),
QT_MOC_LITERAL(6, 56, 4),
QT_MOC_LITERAL(7, 61, 12),
QT_MOC_LITERAL(8, 74, 14),
QT_MOC_LITERAL(9, 89, 10),
QT_MOC_LITERAL(10, 100, 3),
QT_MOC_LITERAL(11, 104, 15),
QT_MOC_LITERAL(12, 120, 5),
QT_MOC_LITERAL(13, 126, 15),
QT_MOC_LITERAL(14, 142, 15),
QT_MOC_LITERAL(15, 158, 14),
QT_MOC_LITERAL(16, 173, 10),
QT_MOC_LITERAL(17, 184, 6),
QT_MOC_LITERAL(18, 191, 7)
    },
    "Cell\0zeroBombNeighbours\0\0cellOpened\0"
    "beforeOpened\0defeat\0open\0changeStatus\0"
    "updateFontSize\0setPressed\0arg\0"
    "setDefaultStyle\0color\0setHoveredStyle\0"
    "setPressedStyle\0setOpenedStyle\0"
    "empty_prop\0status\0pressed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cell[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       3,  106, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x05,
       3,    0,   82,    2, 0x05,
       4,    2,   83,    2, 0x05,
       5,    0,   88,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   89,    2, 0x0a,
       7,    0,   90,    2, 0x0a,
       8,    1,   91,    2, 0x0a,
       9,    1,   94,    2, 0x0a,
      11,    1,   97,    2, 0x0a,
      11,    0,  100,    2, 0x2a,
      13,    0,  101,    2, 0x0a,
      14,    0,  102,    2, 0x0a,
      15,    1,  103,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QSize,    2,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

 // properties: name, type, flags
      16, QMetaType::Bool, 0x00095001,
      17, QMetaType::Int, 0x00095001,
      18, QMetaType::Bool, 0x00095103,

       0        // eod
};

void Cell::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cell *_t = static_cast<Cell *>(_o);
        switch (_id) {
        case 0: _t->zeroBombNeighbours((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->cellOpened(); break;
        case 2: _t->beforeOpened((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->defeat(); break;
        case 4: _t->open(); break;
        case 5: _t->changeStatus(); break;
        case 6: _t->updateFontSize((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 7: _t->setPressed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setDefaultStyle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setDefaultStyle(); break;
        case 10: _t->setHoveredStyle(); break;
        case 11: _t->setPressedStyle(); break;
        case 12: _t->setOpenedStyle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cell::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cell::zeroBombNeighbours)) {
                *result = 0;
            }
        }
        {
            typedef void (Cell::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cell::cellOpened)) {
                *result = 1;
            }
        }
        {
            typedef void (Cell::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cell::beforeOpened)) {
                *result = 2;
            }
        }
        {
            typedef void (Cell::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cell::defeat)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Cell::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_Cell.data,
      qt_meta_data_Cell,  qt_static_metacall, 0, 0}
};


const QMetaObject *Cell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cell::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Cell.stringdata))
        return static_cast<void*>(const_cast< Cell*>(this));
    return QLabel::qt_metacast(_clname);
}

int Cell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = empty(); break;
        case 1: *reinterpret_cast< int*>(_v) = getStatus(); break;
        case 2: *reinterpret_cast< bool*>(_v) = pressed(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: setPressed(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Cell::zeroBombNeighbours(QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cell::cellOpened()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Cell::beforeOpened(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Cell::defeat()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
