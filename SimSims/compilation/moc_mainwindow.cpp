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
    QByteArrayData data[22];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "envoiLumiereOGL"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "LumierePos"
QT_MOC_LITERAL(4, 39, 2), // "lp"
QT_MOC_LITERAL(5, 42, 15), // "SliderALineEdit"
QT_MOC_LITERAL(6, 58, 1), // "i"
QT_MOC_LITERAL(7, 60, 8), // "PopUpLum"
QT_MOC_LITERAL(8, 69, 8), // "PopUpObj"
QT_MOC_LITERAL(9, 78, 15), // "OnClicDeleteLum"
QT_MOC_LITERAL(10, 94, 15), // "OnClicDeleteObj"
QT_MOC_LITERAL(11, 110, 15), // "MAJInterfaceLum"
QT_MOC_LITERAL(12, 126, 15), // "MAJInterfaceObj"
QT_MOC_LITERAL(13, 142, 17), // "SliderALumierePos"
QT_MOC_LITERAL(14, 160, 12), // "SliderAObjet"
QT_MOC_LITERAL(15, 173, 16), // "receptionLumiere"
QT_MOC_LITERAL(16, 190, 14), // "receptionObjet"
QT_MOC_LITERAL(17, 205, 22), // "std::shared_ptr<forme>"
QT_MOC_LITERAL(18, 228, 3), // "ptr"
QT_MOC_LITERAL(19, 232, 6), // "parent"
QT_MOC_LITERAL(20, 239, 16), // "changementParent"
QT_MOC_LITERAL(21, 256, 9) // "nomParent"

    },
    "MainWindow\0envoiLumiereOGL\0\0LumierePos\0"
    "lp\0SliderALineEdit\0i\0PopUpLum\0PopUpObj\0"
    "OnClicDeleteLum\0OnClicDeleteObj\0"
    "MAJInterfaceLum\0MAJInterfaceObj\0"
    "SliderALumierePos\0SliderAObjet\0"
    "receptionLumiere\0receptionObjet\0"
    "std::shared_ptr<forme>\0ptr\0parent\0"
    "changementParent\0nomParent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   82,    2, 0x0a /* Public */,
       7,    0,   85,    2, 0x0a /* Public */,
       8,    0,   86,    2, 0x0a /* Public */,
       9,    0,   87,    2, 0x0a /* Public */,
      10,    0,   88,    2, 0x0a /* Public */,
      11,    0,   89,    2, 0x0a /* Public */,
      12,    0,   90,    2, 0x0a /* Public */,
      13,    0,   91,    2, 0x0a /* Public */,
      14,    0,   92,    2, 0x0a /* Public */,
      15,    1,   93,    2, 0x0a /* Public */,
      16,    2,   96,    2, 0x0a /* Public */,
      20,    1,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 17, QMetaType::QString,   18,   19,
    QMetaType::Void, QMetaType::QString,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->envoiLumiereOGL((*reinterpret_cast< LumierePos(*)>(_a[1]))); break;
        case 1: _t->SliderALineEdit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->PopUpLum(); break;
        case 3: _t->PopUpObj(); break;
        case 4: _t->OnClicDeleteLum(); break;
        case 5: _t->OnClicDeleteObj(); break;
        case 6: _t->MAJInterfaceLum(); break;
        case 7: _t->MAJInterfaceObj(); break;
        case 8: _t->SliderALumierePos(); break;
        case 9: _t->SliderAObjet(); break;
        case 10: _t->receptionLumiere((*reinterpret_cast< LumierePos(*)>(_a[1]))); break;
        case 11: _t->receptionObjet((*reinterpret_cast< std::shared_ptr<forme>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->changementParent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(LumierePos );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::envoiLumiereOGL)) {
                *result = 0;
            }
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::envoiLumiereOGL(LumierePos _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
