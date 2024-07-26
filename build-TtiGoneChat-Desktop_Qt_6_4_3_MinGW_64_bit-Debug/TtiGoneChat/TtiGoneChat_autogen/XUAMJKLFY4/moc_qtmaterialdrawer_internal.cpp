/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialdrawer_internal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialdrawer_internal.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialdrawer_internal.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialDrawerStateMachine_t {
    uint offsetsAndSizes[10];
    char stringdata0[29];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialDrawerStateMachine_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialDrawerStateMachine_t qt_meta_stringdata_QtMaterialDrawerStateMachine = {
    {
        QT_MOC_LITERAL(0, 28),  // "QtMaterialDrawerStateMachine"
        QT_MOC_LITERAL(29, 10),  // "signalOpen"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 11),  // "signalClose"
        QT_MOC_LITERAL(53, 7)   // "opacity"
    },
    "QtMaterialDrawerStateMachine",
    "signalOpen",
    "",
    "signalClose",
    "opacity"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialDrawerStateMachine[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    2 /* Public */,
       3,    0,   27,    2, 0x06,    3 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::QReal, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialDrawerStateMachine::staticMetaObject = { {
    QMetaObject::SuperData::link<QStateMachine::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialDrawerStateMachine.offsetsAndSizes,
    qt_meta_data_QtMaterialDrawerStateMachine,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialDrawerStateMachine_t,
        // property 'opacity'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialDrawerStateMachine, std::true_type>,
        // method 'signalOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalClose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QtMaterialDrawerStateMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtMaterialDrawerStateMachine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalOpen(); break;
        case 1: _t->signalClose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtMaterialDrawerStateMachine::*)();
            if (_t _q_method = &QtMaterialDrawerStateMachine::signalOpen; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtMaterialDrawerStateMachine::*)();
            if (_t _q_method = &QtMaterialDrawerStateMachine::signalClose; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialDrawerStateMachine *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->opacity(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialDrawerStateMachine *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOpacity(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *QtMaterialDrawerStateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialDrawerStateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialDrawerStateMachine.stringdata0))
        return static_cast<void*>(this);
    return QStateMachine::qt_metacast(_clname);
}

int QtMaterialDrawerStateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void QtMaterialDrawerStateMachine::signalOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtMaterialDrawerStateMachine::signalClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {
struct qt_meta_stringdata_QtMaterialDrawerWidget_t {
    uint offsetsAndSizes[4];
    char stringdata0[23];
    char stringdata1[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialDrawerWidget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialDrawerWidget_t qt_meta_stringdata_QtMaterialDrawerWidget = {
    {
        QT_MOC_LITERAL(0, 22),  // "QtMaterialDrawerWidget"
        QT_MOC_LITERAL(23, 6)   // "offset"
    },
    "QtMaterialDrawerWidget",
    "offset"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialDrawerWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialDrawerWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QtMaterialOverlayWidget::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialDrawerWidget.offsetsAndSizes,
    qt_meta_data_QtMaterialDrawerWidget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialDrawerWidget_t,
        // property 'offset'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialDrawerWidget, std::true_type>
    >,
    nullptr
} };

void QtMaterialDrawerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialDrawerWidget *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->offset(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialDrawerWidget *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOffset(*reinterpret_cast< int*>(_v)); break;
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

const QMetaObject *QtMaterialDrawerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialDrawerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialDrawerWidget.stringdata0))
        return static_cast<void*>(this);
    return QtMaterialOverlayWidget::qt_metacast(_clname);
}

int QtMaterialDrawerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtMaterialOverlayWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
