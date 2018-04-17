/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "SliderALineEdit"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 1), // "i"
QT_MOC_LITERAL(4, 30, 8), // "PopUpLum"
QT_MOC_LITERAL(5, 39, 8), // "PopUpObj"
QT_MOC_LITERAL(6, 48, 8), // "IncNbLum"
QT_MOC_LITERAL(7, 57, 8), // "IncNbObj"
QT_MOC_LITERAL(8, 66, 15), // "OnClicDeleteLum"
QT_MOC_LITERAL(9, 82, 15), // "OnClicDeleteObj"
QT_MOC_LITERAL(10, 98, 16), // "receptionLumiere"
QT_MOC_LITERAL(11, 115, 10), // "LumierePos"
QT_MOC_LITERAL(12, 126, 2), // "lp"
QT_MOC_LITERAL(13, 129, 14), // "receptionObjet"
QT_MOC_LITERAL(14, 144, 22), // "std::shared_ptr<forme>"
QT_MOC_LITERAL(15, 167, 3), // "ptr"
QT_MOC_LITERAL(16, 171, 6) // "parent"

    },
    "MainWindow\0SliderALineEdit\0\0i\0PopUpLum\0"
    "PopUpObj\0IncNbLum\0IncNbObj\0OnClicDeleteLum\0"
    "OnClicDeleteObj\0receptionLumiere\0"
    "LumierePos\0lp\0receptionObjet\0"
    "std::shared_ptr<forme>\0ptr\0parent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    0,   62,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    1,   68,    2, 0x0a /* Public */,
      13,    2,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::QString,   15,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SliderALineEdit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->PopUpLum(); break;
        case 2: _t->PopUpObj(); break;
        case 3: _t->IncNbLum(); break;
        case 4: _t->IncNbObj(); break;
        case 5: _t->OnClicDeleteLum(); break;
        case 6: _t->OnClicDeleteObj(); break;
        case 7: _t->receptionLumiere((*reinterpret_cast< LumierePos(*)>(_a[1]))); break;
        case 8: _t->receptionObjet((*reinterpret_cast< std::shared_ptr<forme>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
