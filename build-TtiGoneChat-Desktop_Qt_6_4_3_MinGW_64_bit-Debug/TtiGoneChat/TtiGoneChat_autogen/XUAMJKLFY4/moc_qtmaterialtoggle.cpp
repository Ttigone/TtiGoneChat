/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialtoggle.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialtoggle.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialtoggle.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialToggle_t {
    uint offsetsAndSizes[10];
    char stringdata0[17];
    char stringdata1[14];
    char stringdata2[12];
    char stringdata3[14];
    char stringdata4[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialToggle_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialToggle_t qt_meta_stringdata_QtMaterialToggle = {
    {
        QT_MOC_LITERAL(0, 16),  // "QtMaterialToggle"
        QT_MOC_LITERAL(17, 13),  // "disabledColor"
        QT_MOC_LITERAL(31, 11),  // "activeColor"
        QT_MOC_LITERAL(43, 13),  // "inactiveColor"
        QT_MOC_LITERAL(57, 10)   // "trackColor"
    },
    "QtMaterialToggle",
    "disabledColor",
    "activeColor",
    "inactiveColor",
    "trackColor"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialToggle[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       4,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QColor, 0x00015103, uint(-1), 0,
       2, QMetaType::QColor, 0x00015103, uint(-1), 0,
       3, QMetaType::QColor, 0x00015103, uint(-1), 0,
       4, QMetaType::QColor, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialToggle::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractButton::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialToggle.offsetsAndSizes,
    qt_meta_data_QtMaterialToggle,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialToggle_t,
        // property 'disabledColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'activeColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'inactiveColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'trackColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialToggle, std::true_type>
    >,
    nullptr
} };

void QtMaterialToggle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialToggle *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->disabledColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->activeColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->inactiveColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->trackColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialToggle *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDisabledColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setActiveColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setInactiveColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setTrackColor(*reinterpret_cast< QColor*>(_v)); break;
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

const QMetaObject *QtMaterialToggle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialToggle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialToggle.stringdata0))
        return static_cast<void*>(this);
    return QAbstractButton::qt_metacast(_clname);
}

int QtMaterialToggle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
