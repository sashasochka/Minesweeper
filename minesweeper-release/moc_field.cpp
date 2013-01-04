/****************************************************************************
** Meta object code from reading C++ file 'field.h'
**
** Created: Sat Jan 5 00:40:02 2013
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/field.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'field.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Field_t {
    QByteArrayData data[18];
    char stringdata[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Field_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Field_t qt_meta_stringdata_Field = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 11),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 10),
QT_MOC_LITERAL(4, 30, 1),
QT_MOC_LITERAL(5, 32, 1),
QT_MOC_LITERAL(6, 34, 9),
QT_MOC_LITERAL(7, 44, 9),
QT_MOC_LITERAL(8, 54, 14),
QT_MOC_LITERAL(9, 69, 14),
QT_MOC_LITERAL(10, 84, 14),
QT_MOC_LITERAL(11, 99, 12),
QT_MOC_LITERAL(12, 112, 10),
QT_MOC_LITERAL(13, 123, 3),
QT_MOC_LITERAL(14, 127, 17),
QT_MOC_LITERAL(15, 145, 13),
QT_MOC_LITERAL(16, 159, 12),
QT_MOC_LITERAL(17, 172, 15)
    },
    "Field\0needRestart\0\0needResize\0w\0h\0"
    "fillCells\0testIfWin\0openNeighbours\0"
    "changeSettings\0changeLanguage\0"
    "askMarkAllow\0defeatGame\0win\0"
    "statistics_dialog\0optionsDialog\0"
    "saveSettings\0clearStatistics\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Field[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x05,
       3,    2,   85,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    2,   90,    2, 0x08,
       7,    0,   95,    2, 0x08,
       8,    1,   96,    2, 0x08,
       9,    3,   99,    2, 0x08,
      10,    1,  106,    2, 0x08,
      11,    1,  109,    2, 0x08,
      12,    0,  112,    2, 0x08,
      13,    0,  113,    2, 0x08,
      14,    0,  114,    2, 0x0a,
      15,    0,  115,    2, 0x0a,
      16,    0,  116,    2, 0x0a,
      17,    0,  117,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Field::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Field *_t = static_cast<Field *>(_o);
        switch (_id) {
        case 0: _t->needRestart(); break;
        case 1: _t->needResize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->fillCells((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->testIfWin(); break;
        case 4: _t->openNeighbours((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->changeSettings((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->changeLanguage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->askMarkAllow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->defeatGame(); break;
        case 9: _t->win(); break;
        case 10: _t->statistics_dialog(); break;
        case 11: _t->optionsDialog(); break;
        case 12: _t->saveSettings(); break;
        case 13: _t->clearStatistics(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Field::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Field::needRestart)) {
                *result = 0;
            }
        }
        {
            typedef void (Field::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Field::needResize)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Field::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Field.data,
      qt_meta_data_Field,  qt_static_metacall, 0, 0}
};


const QMetaObject *Field::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Field::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Field.stringdata))
        return static_cast<void*>(const_cast< Field*>(this));
    return QWidget::qt_metacast(_clname);
}

int Field::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Field::needRestart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Field::needResize(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
