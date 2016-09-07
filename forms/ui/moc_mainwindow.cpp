/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/eprosimashapesdemo/qt/mainwindow.h"
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
    QByteArrayData data[20];
    char stringdata0[437];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_bt_publish_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 23), // "on_bt_subscribe_clicked"
QT_MOC_LITERAL(4, 58, 30), // "on_actionPreferences_triggered"
QT_MOC_LITERAL(5, 89, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(6, 113, 43), // "on_tableEndpoint_customContex..."
QT_MOC_LITERAL(7, 157, 3), // "pos"
QT_MOC_LITERAL(8, 161, 33), // "on_actionDelete_Enpoint_trigg..."
QT_MOC_LITERAL(9, 195, 24), // "on_tableEndpoint_clicked"
QT_MOC_LITERAL(10, 220, 5), // "index"
QT_MOC_LITERAL(11, 226, 23), // "on_MainWindow_destroyed"
QT_MOC_LITERAL(12, 250, 10), // "closeEvent"
QT_MOC_LITERAL(13, 261, 12), // "QCloseEvent*"
QT_MOC_LITERAL(14, 274, 5), // "event"
QT_MOC_LITERAL(15, 280, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(16, 305, 30), // "on_actionUser_Manual_triggered"
QT_MOC_LITERAL(17, 336, 51), // "on_actionInteroperability_Tro..."
QT_MOC_LITERAL(18, 388, 24), // "on_actionStart_triggered"
QT_MOC_LITERAL(19, 413, 23) // "on_actionStop_triggered"

    },
    "MainWindow\0on_bt_publish_clicked\0\0"
    "on_bt_subscribe_clicked\0"
    "on_actionPreferences_triggered\0"
    "on_actionExit_triggered\0"
    "on_tableEndpoint_customContextMenuRequested\0"
    "pos\0on_actionDelete_Enpoint_triggered\0"
    "on_tableEndpoint_clicked\0index\0"
    "on_MainWindow_destroyed\0closeEvent\0"
    "QCloseEvent*\0event\0on_actionAbout_triggered\0"
    "on_actionUser_Manual_triggered\0"
    "on_actionInteroperability_Troubleshooting_triggered\0"
    "on_actionStart_triggered\0"
    "on_actionStop_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    1,   92,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    1,   96,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x0a /* Public */,
      19,    0,  103,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_bt_publish_clicked(); break;
        case 1: _t->on_bt_subscribe_clicked(); break;
        case 2: _t->on_actionPreferences_triggered(); break;
        case 3: _t->on_actionExit_triggered(); break;
        case 4: _t->on_tableEndpoint_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 5: _t->on_actionDelete_Enpoint_triggered(); break;
        case 6: _t->on_tableEndpoint_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_MainWindow_destroyed(); break;
        case 8: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 9: _t->on_actionAbout_triggered(); break;
        case 10: _t->on_actionUser_Manual_triggered(); break;
        case 11: _t->on_actionInteroperability_Troubleshooting_triggered(); break;
        case 12: _t->on_actionStart_triggered(); break;
        case 13: _t->on_actionStop_triggered(); break;
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
QT_END_MOC_NAMESPACE
