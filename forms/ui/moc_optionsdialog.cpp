/****************************************************************************
** Meta object code from reading C++ file 'optionsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/eprosimashapesdemo/qt/optionsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
struct qt_meta_stringdata_OptionsDialog_t {
    QByteArrayData data[15];
    char stringdata0[398];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionsDialog_t qt_meta_stringdata_OptionsDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "OptionsDialog"
QT_MOC_LITERAL(1, 14, 25), // "on_OptionsDialog_accepted"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 25), // "on_pushButton_udp_clicked"
QT_MOC_LITERAL(4, 67, 32), // "on_pushButton_tcp_client_clicked"
QT_MOC_LITERAL(5, 100, 32), // "on_pushButton_tcp_server_clicked"
QT_MOC_LITERAL(6, 133, 27), // "on_pushButton_start_clicked"
QT_MOC_LITERAL(7, 161, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(8, 188, 29), // "on_spin_domainId_valueChanged"
QT_MOC_LITERAL(9, 218, 4), // "arg1"
QT_MOC_LITERAL(10, 223, 32), // "on_spin_server_port_valueChanged"
QT_MOC_LITERAL(11, 256, 32), // "on_spin_listen_port_valueChanged"
QT_MOC_LITERAL(12, 289, 33), // "on_lineEdit_server_ip_textCha..."
QT_MOC_LITERAL(13, 323, 35), // "on_spin_updateInterval_valueC..."
QT_MOC_LITERAL(14, 359, 38) // "on_horizontalSlider_speed_val..."

    },
    "OptionsDialog\0on_OptionsDialog_accepted\0"
    "\0on_pushButton_udp_clicked\0"
    "on_pushButton_tcp_client_clicked\0"
    "on_pushButton_tcp_server_clicked\0"
    "on_pushButton_start_clicked\0"
    "on_pushButton_stop_clicked\0"
    "on_spin_domainId_valueChanged\0arg1\0"
    "on_spin_server_port_valueChanged\0"
    "on_spin_listen_port_valueChanged\0"
    "on_lineEdit_server_ip_textChanged\0"
    "on_spin_updateInterval_valueChanged\0"
    "on_horizontalSlider_speed_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionsDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    1,   80,    2, 0x08 /* Private */,
      10,    1,   83,    2, 0x08 /* Private */,
      11,    1,   86,    2, 0x08 /* Private */,
      12,    1,   89,    2, 0x08 /* Private */,
      13,    1,   92,    2, 0x08 /* Private */,
      14,    1,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void OptionsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionsDialog *_t = static_cast<OptionsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_OptionsDialog_accepted(); break;
        case 1: _t->on_pushButton_udp_clicked(); break;
        case 2: _t->on_pushButton_tcp_client_clicked(); break;
        case 3: _t->on_pushButton_tcp_server_clicked(); break;
        case 4: _t->on_pushButton_start_clicked(); break;
        case 5: _t->on_pushButton_stop_clicked(); break;
        case 6: _t->on_spin_domainId_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_spin_server_port_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_spin_listen_port_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_lineEdit_server_ip_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_spin_updateInterval_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_horizontalSlider_speed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject OptionsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OptionsDialog.data,
      qt_meta_data_OptionsDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OptionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int OptionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
