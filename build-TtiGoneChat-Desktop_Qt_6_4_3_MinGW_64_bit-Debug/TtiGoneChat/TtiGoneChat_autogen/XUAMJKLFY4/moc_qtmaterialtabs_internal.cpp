/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialtabs_internal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialtabs_internal.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialtabs_internal.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialTabsInkBar_t {
    uint offsetsAndSizes[4];
    char stringdata0[21];
    char stringdata1[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialTabsInkBar_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialTabsInkBar_t qt_meta_stringdata_QtMaterialTabsInkBar = {
    {
        QT_MOC_LITERAL(0, 20),  // "QtMaterialTabsInkBar"
        QT_MOC_LITERAL(21, 10)   // "tweenValue"
    },
    "QtMaterialTabsInkBar",
    "tweenValue"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialTabsInkBar[] = {

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
       1, QMetaType::QReal, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialTabsInkBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QtMaterialOverlayWidget::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialTabsInkBar.offsetsAndSizes,
    qt_meta_data_QtMaterialTabsInkBar,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialTabsInkBar_t,
        // property 'tweenValue'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialTabsInkBar, std::true_type>
    >,
    nullptr
} };

void QtMaterialTabsInkBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialTabsInkBar *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->tweenValue(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialTabsInkBar *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTweenValue(*reinterpret_cast< qreal*>(_v)); break;
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

const QMetaObject *QtMaterialTabsInkBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialTabsInkBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialTabsInkBar.stringdata0))
        return static_cast<void*>(this);
    return QtMaterialOverlayWidget::qt_metacast(_clname);
}

int QtMaterialTabsInkBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
namespace {
struct qt_meta_stringdata_QtMaterialTab_t {
    uint offsetsAndSizes[6];
    char stringdata0[14];
    char stringdata1[12];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialTab_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialTab_t qt_meta_stringdata_QtMaterialTab = {
    {
        QT_MOC_LITERAL(0, 13),  // "QtMaterialTab"
        QT_MOC_LITERAL(14, 11),  // "activateTab"
        QT_MOC_LITERAL(26, 0)   // ""
    },
    "QtMaterialTab",
    "activateTab",
    ""
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialTab[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x09,    1 /* Protected */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialTab::staticMetaObject = { {
    QMetaObject::SuperData::link<QtMaterialFlatButton::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialTab.offsetsAndSizes,
    qt_meta_data_QtMaterialTab,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialTab_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialTab, std::true_type>,
        // method 'activateTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QtMaterialTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtMaterialTab *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->activateTab(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *QtMaterialTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialTab.stringdata0))
        return static_cast<void*>(this);
    return QtMaterialFlatButton::qt_metacast(_clname);
}

int QtMaterialTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtMaterialFlatButton::qt_metacall(_c, _id, _a);
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
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
