/****************************************************************************
** Meta object code from reading C++ file 'widgetOGL.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widgetOGL.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetOGL.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WidgetOGL_t {
    QByteArrayData data[19];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetOGL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetOGL_t qt_meta_stringdata_WidgetOGL = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WidgetOGL"
QT_MOC_LITERAL(1, 10, 11), // "timeOutSlot"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "slotUpdate"
QT_MOC_LITERAL(4, 34, 12), // "setAmbianteR"
QT_MOC_LITERAL(5, 47, 1), // "r"
QT_MOC_LITERAL(6, 49, 12), // "setAmbianteV"
QT_MOC_LITERAL(7, 62, 1), // "v"
QT_MOC_LITERAL(8, 64, 12), // "setAmbianteB"
QT_MOC_LITERAL(9, 77, 1), // "b"
QT_MOC_LITERAL(10, 79, 10), // "setPosXCam"
QT_MOC_LITERAL(11, 90, 1), // "x"
QT_MOC_LITERAL(12, 92, 10), // "setPosYCam"
QT_MOC_LITERAL(13, 103, 1), // "y"
QT_MOC_LITERAL(14, 105, 10), // "setPosZCam"
QT_MOC_LITERAL(15, 116, 1), // "z"
QT_MOC_LITERAL(16, 118, 10), // "setAngXCam"
QT_MOC_LITERAL(17, 129, 10), // "setAngYCam"
QT_MOC_LITERAL(18, 140, 10) // "setAngZCam"

    },
    "WidgetOGL\0timeOutSlot\0\0slotUpdate\0"
    "setAmbianteR\0r\0setAmbianteV\0v\0"
    "setAmbianteB\0b\0setPosXCam\0x\0setPosYCam\0"
    "y\0setPosZCam\0z\0setAngXCam\0setAngYCam\0"
    "setAngZCam"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetOGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    1,   71,    2, 0x0a /* Public */,
       6,    1,   74,    2, 0x0a /* Public */,
       8,    1,   77,    2, 0x0a /* Public */,
      10,    1,   80,    2, 0x0a /* Public */,
      12,    1,   83,    2, 0x0a /* Public */,
      14,    1,   86,    2, 0x0a /* Public */,
      16,    1,   89,    2, 0x0a /* Public */,
      17,    1,   92,    2, 0x0a /* Public */,
      18,    1,   95,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void WidgetOGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetOGL *_t = static_cast<WidgetOGL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timeOutSlot(); break;
        case 1: _t->slotUpdate(); break;
        case 2: _t->setAmbianteR((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setAmbianteV((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setAmbianteB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setPosXCam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setPosYCam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setPosZCam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setAngXCam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setAngYCam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setAngZCam((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject WidgetOGL::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_WidgetOGL.data,
      qt_meta_data_WidgetOGL,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WidgetOGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetOGL::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetOGL.stringdata0))
        return static_cast<void*>(const_cast< WidgetOGL*>(this));
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(const_cast< WidgetOGL*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int WidgetOGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
