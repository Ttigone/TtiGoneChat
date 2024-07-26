/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialslider_internal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialslider_internal.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialslider_internal.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialSliderStateMachine_t {
    uint offsetsAndSizes[2];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialSliderStateMachine_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialSliderStateMachine_t qt_meta_stringdata_QtMaterialSliderStateMachine = {
    {
        QT_MOC_LITERAL(0, 28)   // "QtMaterialSliderStateMachine"
    },
    "QtMaterialSliderStateMachine"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialSliderStateMachine[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialSliderStateMachine::staticMetaObject = { {
    QMetaObject::SuperData::link<QStateMachine::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialSliderStateMachine.offsetsAndSizes,
    qt_meta_data_QtMaterialSliderStateMachine,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialSliderStateMachine_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialSliderStateMachine, std::true_type>
    >,
    nullptr
} };

void QtMaterialSliderStateMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *QtMaterialSliderStateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialSliderStateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialSliderStateMachine.stringdata0))
        return static_cast<void*>(this);
    return QStateMachine::qt_metacast(_clname);
}

int QtMaterialSliderStateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStateMachine::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_stringdata_QtMaterialSliderThumb_t {
    uint offsetsAndSizes[14];
    char stringdata0[22];
    char stringdata1[9];
    char stringdata2[12];
    char stringdata3[12];
    char stringdata4[10];
    char stringdata5[9];
    char stringdata6[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialSliderThumb_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialSliderThumb_t qt_meta_stringdata_QtMaterialSliderThumb = {
    {
        QT_MOC_LITERAL(0, 21),  // "QtMaterialSliderThumb"
        QT_MOC_LITERAL(22, 8),  // "diameter"
        QT_MOC_LITERAL(31, 11),  // "borderWidth"
        QT_MOC_LITERAL(43, 11),  // "borderColor"
        QT_MOC_LITERAL(55, 9),  // "fillColor"
        QT_MOC_LITERAL(65, 8),  // "haloSize"
        QT_MOC_LITERAL(74, 9)   // "haloColor"
    },
    "QtMaterialSliderThumb",
    "diameter",
    "borderWidth",
    "borderColor",
    "fillColor",
    "haloSize",
    "haloColor"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialSliderThumb[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       6,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QReal, 0x00015103, uint(-1), 0,
       2, QMetaType::QReal, 0x00015103, uint(-1), 0,
       3, QMetaType::QColor, 0x00015103, uint(-1), 0,
       4, QMetaType::QColor, 0x00015103, uint(-1), 0,
       5, QMetaType::QReal, 0x00015103, uint(-1), 0,
       6, QMetaType::QColor, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialSliderThumb::staticMetaObject = { {
    QMetaObject::SuperData::link<QtMaterialOverlayWidget::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialSliderThumb.offsetsAndSizes,
    qt_meta_data_QtMaterialSliderThumb,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialSliderThumb_t,
        // property 'diameter'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'borderWidth'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'borderColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'fillColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'haloSize'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'haloColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialSliderThumb, std::true_type>
    >,
    nullptr
} };

void QtMaterialSliderThumb::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialSliderThumb *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->diameter(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->borderWidth(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->borderColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->fillColor(); break;
        case 4: *reinterpret_cast< qreal*>(_v) = _t->haloSize(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->haloColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialSliderThumb *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDiameter(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setBorderWidth(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->setBorderColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setFillColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setHaloSize(*reinterpret_cast< qreal*>(_v)); break;
        case 5: _t->setHaloColor(*reinterpret_cast< QColor*>(_v)); break;
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

const QMetaObject *QtMaterialSliderThumb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialSliderThumb::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialSliderThumb.stringdata0))
        return static_cast<void*>(this);
    return QtMaterialOverlayWidget::qt_metacast(_clname);
}

int QtMaterialSliderThumb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtMaterialOverlayWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
namespace {
struct qt_meta_stringdata_QtMaterialSliderTrack_t {
    uint offsetsAndSizes[4];
    char stringdata0[22];
    char stringdata1[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialSliderTrack_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialSliderTrack_t qt_meta_stringdata_QtMaterialSliderTrack = {
    {
        QT_MOC_LITERAL(0, 21),  // "QtMaterialSliderTrack"
        QT_MOC_LITERAL(22, 9)   // "fillColor"
    },
    "QtMaterialSliderTrack",
    "fillColor"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialSliderTrack[] = {

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
       1, QMetaType::QColor, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialSliderTrack::staticMetaObject = { {
    QMetaObject::SuperData::link<QtMaterialOverlayWidget::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialSliderTrack.offsetsAndSizes,
    qt_meta_data_QtMaterialSliderTrack,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialSliderTrack_t,
        // property 'fillColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialSliderTrack, std::true_type>
    >,
    nullptr
} };

void QtMaterialSliderTrack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialSliderTrack *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->fillColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialSliderTrack *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFillColor(*reinterpret_cast< QColor*>(_v)); break;
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

const QMetaObject *QtMaterialSliderTrack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialSliderTrack::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialSliderTrack.stringdata0))
        return static_cast<void*>(this);
    return QtMaterialOverlayWidget::qt_metacast(_clname);
}

int QtMaterialSliderTrack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
