/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialsnackbar_internal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialsnackbar_internal.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialsnackbar_internal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_QtMaterialSnackbarStateMachine_t {
    uint offsetsAndSizes[10];
    char stringdata0[31];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialSnackbarStateMachine_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialSnackbarStateMachine_t qt_meta_stringdata_QtMaterialSnackbarStateMachine = {
    {
        QT_MOC_LITERAL(0, 30),  // "QtMaterialSnackbarStateMachine"
        QT_MOC_LITERAL(31, 8),  // "progress"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 13),  // "snackbarShown"
        QT_MOC_LITERAL(55, 6)   // "offset"
    },
    "QtMaterialSnackbarStateMachine",
    "progress",
    "",
    "snackbarShown",
    "offset"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialSnackbarStateMachine[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x0a,    2 /* Public */,
       3,    0,   27,    2, 0x09,    3 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::QReal, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialSnackbarStateMachine::staticMetaObject = { {
    QMetaObject::SuperData::link<QStateMachine::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialSnackbarStateMachine.offsetsAndSizes,
    qt_meta_data_QtMaterialSnackbarStateMachine,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialSnackbarStateMachine_t,
        // property 'offset'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialSnackbarStateMachine, std::true_type>,
        // method 'progress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'snackbarShown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QtMaterialSnackbarStateMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtMaterialSnackbarStateMachine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->progress(); break;
        case 1: _t->snackbarShown(); break;
        default: ;
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialSnackbarStateMachine *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->offset(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialSnackbarStateMachine *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOffset(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *QtMaterialSnackbarStateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialSnackbarStateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialSnackbarStateMachine.stringdata0))
        return static_cast<void*>(this);
    return QStateMachine::qt_metacast(_clname);
}

int QtMaterialSnackbarStateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStateMachine::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
