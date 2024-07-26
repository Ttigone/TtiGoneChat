/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialslider.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialslider.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialslider.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialSlider_t {
    uint offsetsAndSizes[8];
    char stringdata0[17];
    char stringdata1[11];
    char stringdata2[11];
    char stringdata3[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialSlider_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialSlider_t qt_meta_stringdata_QtMaterialSlider = {
    {
        QT_MOC_LITERAL(0, 16),  // "QtMaterialSlider"
        QT_MOC_LITERAL(17, 10),  // "thumbColor"
        QT_MOC_LITERAL(28, 10),  // "trackColor"
        QT_MOC_LITERAL(39, 13)   // "disabledColor"
    },
    "QtMaterialSlider",
    "thumbColor",
    "trackColor",
    "disabledColor"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialSlider[] = {

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
       1, QMetaType::QColor, 0x00015103, uint(-1), 0,
       2, QMetaType::QColor, 0x00015103, uint(-1), 0,
       3, QMetaType::QColor, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialSlider::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractSlider::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialSlider.offsetsAndSizes,
    qt_meta_data_QtMaterialSlider,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialSlider_t,
        // property 'thumbColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'trackColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'disabledColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialSlider, std::true_type>
    >,
    nullptr
} };

void QtMaterialSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialSlider *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->thumbColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->trackColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->disabledColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialSlider *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setThumbColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setTrackColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setDisabledColor(*reinterpret_cast< QColor*>(_v)); break;
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

const QMetaObject *QtMaterialSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialSlider.stringdata0))
        return static_cast<void*>(this);
    return QAbstractSlider::qt_metacast(_clname);
}

int QtMaterialSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractSlider::qt_metacall(_c, _id, _a);
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
