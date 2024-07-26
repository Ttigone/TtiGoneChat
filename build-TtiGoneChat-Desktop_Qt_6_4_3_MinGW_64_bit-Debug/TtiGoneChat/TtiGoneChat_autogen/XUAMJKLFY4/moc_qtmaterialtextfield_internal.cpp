/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialtextfield_internal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialtextfield_internal.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialtextfield_internal.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialTextFieldStateMachine_t {
    uint offsetsAndSizes[8];
    char stringdata0[32];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialTextFieldStateMachine_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialTextFieldStateMachine_t qt_meta_stringdata_QtMaterialTextFieldStateMachine = {
    {
        QT_MOC_LITERAL(0, 31),  // "QtMaterialTextFieldStateMachine"
        QT_MOC_LITERAL(32, 15),  // "setupProperties"
        QT_MOC_LITERAL(48, 0),  // ""
        QT_MOC_LITERAL(49, 8)   // "progress"
    },
    "QtMaterialTextFieldStateMachine",
    "setupProperties",
    "",
    "progress"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialTextFieldStateMachine[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   21, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x0a,    2 /* Public */,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QReal, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialTextFieldStateMachine::staticMetaObject = { {
    QMetaObject::SuperData::link<QStateMachine::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialTextFieldStateMachine.offsetsAndSizes,
    qt_meta_data_QtMaterialTextFieldStateMachine,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialTextFieldStateMachine_t,
        // property 'progress'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialTextFieldStateMachine, std::true_type>,
        // method 'setupProperties'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QtMaterialTextFieldStateMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtMaterialTextFieldStateMachine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setupProperties(); break;
        default: ;
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialTextFieldStateMachine *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->progress(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialTextFieldStateMachine *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setProgress(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *QtMaterialTextFieldStateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialTextFieldStateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialTextFieldStateMachine.stringdata0))
        return static_cast<void*>(this);
    return QStateMachine::qt_metacast(_clname);
}

int QtMaterialTextFieldStateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStateMachine::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_stringdata_QtMaterialTextFieldLabel_t {
    uint offsetsAndSizes[8];
    char stringdata0[25];
    char stringdata1[6];
    char stringdata2[7];
    char stringdata3[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialTextFieldLabel_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialTextFieldLabel_t qt_meta_stringdata_QtMaterialTextFieldLabel = {
    {
        QT_MOC_LITERAL(0, 24),  // "QtMaterialTextFieldLabel"
        QT_MOC_LITERAL(25, 5),  // "scale"
        QT_MOC_LITERAL(31, 6),  // "offset"
        QT_MOC_LITERAL(38, 5)   // "color"
    },
    "QtMaterialTextFieldLabel",
    "scale",
    "offset",
    "color"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialTextFieldLabel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QReal, 0x00015103, uint(-1), 0,
       2, QMetaType::QPointF, 0x00015103, uint(-1), 0,
       3, QMetaType::QColor, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialTextFieldLabel::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialTextFieldLabel.offsetsAndSizes,
    qt_meta_data_QtMaterialTextFieldLabel,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialTextFieldLabel_t,
        // property 'scale'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'offset'
        QtPrivate::TypeAndForceComplete<QPointF, std::true_type>,
        // property 'color'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialTextFieldLabel, std::true_type>
    >,
    nullptr
} };

void QtMaterialTextFieldLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialTextFieldLabel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->scale(); break;
        case 1: *reinterpret_cast< QPointF*>(_v) = _t->offset(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->color(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialTextFieldLabel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setScale(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setOffset(*reinterpret_cast< QPointF*>(_v)); break;
        case 2: _t->setColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *QtMaterialTextFieldLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialTextFieldLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialTextFieldLabel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QtMaterialTextFieldLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
