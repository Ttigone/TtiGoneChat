/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialcircularprogress.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialcircularprogress.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialcircularprogress.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialCircularProgress_t {
    uint offsetsAndSizes[8];
    char stringdata0[27];
    char stringdata1[10];
    char stringdata2[5];
    char stringdata3[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialCircularProgress_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialCircularProgress_t qt_meta_stringdata_QtMaterialCircularProgress = {
    {
        QT_MOC_LITERAL(0, 26),  // "QtMaterialCircularProgress"
        QT_MOC_LITERAL(27, 9),  // "lineWidth"
        QT_MOC_LITERAL(37, 4),  // "size"
        QT_MOC_LITERAL(42, 5)   // "color"
    },
    "QtMaterialCircularProgress",
    "lineWidth",
    "size",
    "color"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialCircularProgress[] = {

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
       3, QMetaType::QColor, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialCircularProgress::staticMetaObject = { {
    QMetaObject::SuperData::link<QProgressBar::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialCircularProgress.offsetsAndSizes,
    qt_meta_data_QtMaterialCircularProgress,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialCircularProgress_t,
        // property 'lineWidth'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'size'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'color'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialCircularProgress, std::true_type>
    >,
    nullptr
} };

void QtMaterialCircularProgress::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialCircularProgress *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->lineWidth(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->size(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->color(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialCircularProgress *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLineWidth(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setSize(*reinterpret_cast< qreal*>(_v)); break;
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

const QMetaObject *QtMaterialCircularProgress::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialCircularProgress::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialCircularProgress.stringdata0))
        return static_cast<void*>(this);
    return QProgressBar::qt_metacast(_clname);
}

int QtMaterialCircularProgress::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QProgressBar::qt_metacall(_c, _id, _a);
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
