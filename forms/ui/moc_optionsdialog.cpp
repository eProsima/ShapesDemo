/****************************************************************************
** Meta object code from reading C++ file 'optionsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/eprosimashapesdemo/qt/optionsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OptionsDialog_t {
    QByteArrayData data[7];
    char stringdata0[131];
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
QT_MOC_LITERAL(3, 41, 27), // "on_pushButton_start_clicked"
QT_MOC_LITERAL(4, 69, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(5, 96, 29), // "on_spin_domainId_valueChanged"
QT_MOC_LITERAL(6, 126, 4) // "arg1"

    },
    "OptionsDialog\0on_OptionsDialog_accepted\0"
    "\0on_pushButton_start_clicked\0"
    "on_pushButton_stop_clicked\0"
    "on_spin_domainId_valueChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionsDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void OptionsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionsDialog *_t = static_cast<OptionsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_OptionsDialog_accepted(); break;
        case 1: _t->on_pushButton_start_clicked(); break;
        case 2: _t->on_pushButton_stop_clicked(); break;
        case 3: _t->on_spin_domainId_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject OptionsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OptionsDialog.data,
      qt_meta_data_OptionsDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OptionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsDialog.stringdata0))
        return static_cast<void*>(const_cast< OptionsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int OptionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
