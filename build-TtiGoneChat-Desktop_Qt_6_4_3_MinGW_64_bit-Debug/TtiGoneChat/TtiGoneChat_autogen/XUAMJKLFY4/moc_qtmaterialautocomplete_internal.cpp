/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialautocomplete_internal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialautocomplete_internal.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialautocomplete_internal.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialAutoCompleteStateMachine_t {
    uint offsetsAndSizes[10];
    char stringdata0[35];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialAutoCompleteStateMachine_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialAutoCompleteStateMachine_t qt_meta_stringdata_QtMaterialAutoCompleteStateMachine = {
    {
        QT_MOC_LITERAL(0, 34),  // "QtMaterialAutoCompleteStateMa..."
        QT_MOC_LITERAL(35, 10),  // "shouldOpen"
        QT_MOC_LITERAL(46, 0),  // ""
        QT_MOC_LITERAL(47, 11),  // "shouldClose"
        QT_MOC_LITERAL(59, 10)   // "shouldFade"
    },
    "QtMaterialAutoCompleteStateMachine",
    "shouldOpen",
    "",
    "shouldClose",
    "shouldFade"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialAutoCompleteStateMachine[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    1 /* Public */,
       3,    0,   33,    2, 0x06,    2 /* Public */,
       4,    0,   34,    2, 0x06,    3 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialAutoCompleteStateMachine::staticMetaObject = { {
    QMetaObject::SuperData::link<QStateMachine::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialAutoCompleteStateMachine.offsetsAndSizes,
    qt_meta_data_QtMaterialAutoCompleteStateMachine,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialAutoCompleteStateMachine_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialAutoCompleteStateMachine, std::true_type>,
        // method 'shouldOpen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'shouldClose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'shouldFade'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QtMaterialAutoCompleteStateMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtMaterialAutoCompleteStateMachine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->shouldOpen(); break;
        case 1: _t->shouldClose(); break;
        case 2: _t->shouldFade(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtMaterialAutoCompleteStateMachine::*)();
            if (_t _q_method = &QtMaterialAutoCompleteStateMachine::shouldOpen; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtMaterialAutoCompleteStateMachine::*)();
            if (_t _q_method = &QtMaterialAutoCompleteStateMachine::shouldClose; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtMaterialAutoCompleteStateMachine::*)();
            if (_t _q_method = &QtMaterialAutoCompleteStateMachine::shouldFade; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *QtMaterialAutoCompleteStateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialAutoCompleteStateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialAutoCompleteStateMachine.stringdata0))
        return static_cast<void*>(this);
    return QStateMachine::qt_metacast(_clname);
}

int QtMaterialAutoCompleteStateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    }
    return _id;
}

// SIGNAL 0
void QtMaterialAutoCompleteStateMachine::shouldOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtMaterialAutoCompleteStateMachine::shouldClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtMaterialAutoCompleteStateMachine::shouldFade()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
