/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialflatbutton_internal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialflatbutton_internal.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialflatbutton_internal.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialFlatButtonStateMachine_t {
    uint offsetsAndSizes[20];
    char stringdata0[33];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[16];
    char stringdata5[15];
    char stringdata6[23];
    char stringdata7[12];
    char stringdata8[9];
    char stringdata9[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialFlatButtonStateMachine_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialFlatButtonStateMachine_t qt_meta_stringdata_QtMaterialFlatButtonStateMachine = {
    {
        QT_MOC_LITERAL(0, 32),  // "QtMaterialFlatButtonStateMachine"
        QT_MOC_LITERAL(33, 13),  // "buttonPressed"
        QT_MOC_LITERAL(47, 0),  // ""
        QT_MOC_LITERAL(48, 13),  // "buttonChecked"
        QT_MOC_LITERAL(62, 15),  // "buttonUnchecked"
        QT_MOC_LITERAL(78, 14),  // "overlayOpacity"
        QT_MOC_LITERAL(93, 22),  // "checkedOverlayProgress"
        QT_MOC_LITERAL(116, 11),  // "haloOpacity"
        QT_MOC_LITERAL(128, 8),  // "haloSize"
        QT_MOC_LITERAL(137, 15)   // "haloScaleFactor"
    },
    "QtMaterialFlatButtonStateMachine",
    "buttonPressed",
    "",
    "buttonChecked",
    "buttonUnchecked",
    "overlayOpacity",
    "checkedOverlayProgress",
    "haloOpacity",
    "haloSize",
    "haloScaleFactor"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialFlatButtonStateMachine[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       5,   35, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    6 /* Public */,
       3,    0,   33,    2, 0x06,    7 /* Public */,
       4,    0,   34,    2, 0x06,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::QReal, 0x00015103, uint(-1), 0,
       6, QMetaType::QReal, 0x00015103, uint(-1), 0,
       7, QMetaType::QReal, 0x00015103, uint(-1), 0,
       8, QMetaType::QReal, 0x00015103, uint(-1), 0,
       9, QMetaType::QReal, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialFlatButtonStateMachine::staticMetaObject = { {
    QMetaObject::SuperData::link<QStateMachine::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialFlatButtonStateMachine.offsetsAndSizes,
    qt_meta_data_QtMaterialFlatButtonStateMachine,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialFlatButtonStateMachine_t,
        // property 'overlayOpacity'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'checkedOverlayProgress'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'haloOpacity'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'haloSize'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'haloScaleFactor'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialFlatButtonStateMachine, std::true_type>,
        // method 'buttonPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buttonChecked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buttonUnchecked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QtMaterialFlatButtonStateMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtMaterialFlatButtonStateMachine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->buttonPressed(); break;
        case 1: _t->buttonChecked(); break;
        case 2: _t->buttonUnchecked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtMaterialFlatButtonStateMachine::*)();
            if (_t _q_method = &QtMaterialFlatButtonStateMachine::buttonPressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtMaterialFlatButtonStateMachine::*)();
            if (_t _q_method = &QtMaterialFlatButtonStateMachine::buttonChecked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtMaterialFlatButtonStateMachine::*)();
            if (_t _q_method = &QtMaterialFlatButtonStateMachine::buttonUnchecked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialFlatButtonStateMachine *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->overlayOpacity(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->checkedOverlayProgress(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->haloOpacity(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = _t->haloSize(); break;
        case 4: *reinterpret_cast< qreal*>(_v) = _t->haloScaleFactor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialFlatButtonStateMachine *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOverlayOpacity(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setCheckedOverlayProgress(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->setHaloOpacity(*reinterpret_cast< qreal*>(_v)); break;
        case 3: _t->setHaloSize(*reinterpret_cast< qreal*>(_v)); break;
        case 4: _t->setHaloScaleFactor(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *QtMaterialFlatButtonStateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialFlatButtonStateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialFlatButtonStateMachine.stringdata0))
        return static_cast<void*>(this);
    return QStateMachine::qt_metacast(_clname);
}

int QtMaterialFlatButtonStateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStateMachine::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QtMaterialFlatButtonStateMachine::buttonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtMaterialFlatButtonStateMachine::buttonChecked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtMaterialFlatButtonStateMachine::buttonUnchecked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
