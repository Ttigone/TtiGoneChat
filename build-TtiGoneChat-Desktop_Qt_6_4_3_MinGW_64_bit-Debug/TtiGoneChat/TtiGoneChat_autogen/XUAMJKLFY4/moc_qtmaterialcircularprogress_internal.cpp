/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialcircularprogress_internal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialcircularprogress_internal.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialcircularprogress_internal.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialCircularProgressDelegate_t {
    uint offsetsAndSizes[8];
    char stringdata0[35];
    char stringdata1[11];
    char stringdata2[11];
    char stringdata3[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialCircularProgressDelegate_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialCircularProgressDelegate_t qt_meta_stringdata_QtMaterialCircularProgressDelegate = {
    {
        QT_MOC_LITERAL(0, 34),  // "QtMaterialCircularProgressDel..."
        QT_MOC_LITERAL(35, 10),  // "dashOffset"
        QT_MOC_LITERAL(46, 10),  // "dashLength"
        QT_MOC_LITERAL(57, 5)   // "angle"
    },
    "QtMaterialCircularProgressDelegate",
    "dashOffset",
    "dashLength",
    "angle"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialCircularProgressDelegate[] = {

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
       2, QMetaType::QReal, 0x00015103, uint(-1), 0,
       3, QMetaType::Int, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialCircularProgressDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialCircularProgressDelegate.offsetsAndSizes,
    qt_meta_data_QtMaterialCircularProgressDelegate,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialCircularProgressDelegate_t,
        // property 'dashOffset'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'dashLength'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'angle'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialCircularProgressDelegate, std::true_type>
    >,
    nullptr
} };

void QtMaterialCircularProgressDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialCircularProgressDelegate *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->dashOffset(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->dashLength(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->angle(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialCircularProgressDelegate *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDashOffset(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setDashLength(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->setAngle(*reinterpret_cast< int*>(_v)); break;
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

const QMetaObject *QtMaterialCircularProgressDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialCircularProgressDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialCircularProgressDelegate.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtMaterialCircularProgressDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
