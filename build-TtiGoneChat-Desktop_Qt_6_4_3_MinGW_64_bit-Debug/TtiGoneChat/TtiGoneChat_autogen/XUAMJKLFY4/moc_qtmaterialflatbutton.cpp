/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialflatbutton.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialflatbutton.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialflatbutton.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialFlatButton_t {
    uint offsetsAndSizes[14];
    char stringdata0[21];
    char stringdata1[16];
    char stringdata2[16];
    char stringdata3[13];
    char stringdata4[24];
    char stringdata5[24];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialFlatButton_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialFlatButton_t qt_meta_stringdata_QtMaterialFlatButton = {
    {
        QT_MOC_LITERAL(0, 20),  // "QtMaterialFlatButton"
        QT_MOC_LITERAL(21, 15),  // "foregroundColor"
        QT_MOC_LITERAL(37, 15),  // "backgroundColor"
        QT_MOC_LITERAL(53, 12),  // "overlayColor"
        QT_MOC_LITERAL(66, 23),  // "disabledForegroundColor"
        QT_MOC_LITERAL(90, 23),  // "disabledBackgroundColor"
        QT_MOC_LITERAL(114, 8)   // "fontSize"
    },
    "QtMaterialFlatButton",
    "foregroundColor",
    "backgroundColor",
    "overlayColor",
    "disabledForegroundColor",
    "disabledBackgroundColor",
    "fontSize"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialFlatButton[] = {

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
       1, QMetaType::QColor, 0x00015103, uint(-1), 0,
       2, QMetaType::QColor, 0x00015103, uint(-1), 0,
       3, QMetaType::QColor, 0x00015103, uint(-1), 0,
       4, QMetaType::QColor, 0x00015103, uint(-1), 0,
       5, QMetaType::QColor, 0x00015103, uint(-1), 0,
       6, QMetaType::QReal, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialFlatButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialFlatButton.offsetsAndSizes,
    qt_meta_data_QtMaterialFlatButton,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialFlatButton_t,
        // property 'foregroundColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'backgroundColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'overlayColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'disabledForegroundColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'disabledBackgroundColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'fontSize'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialFlatButton, std::true_type>
    >,
    nullptr
} };

void QtMaterialFlatButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QtMaterialFlatButton *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->foregroundColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->backgroundColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->overlayColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->disabledForegroundColor(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->disabledBackgroundColor(); break;
        case 5: *reinterpret_cast< qreal*>(_v) = _t->fontSize(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QtMaterialFlatButton *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setForegroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setBackgroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setOverlayColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setDisabledForegroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setDisabledBackgroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->setFontSize(*reinterpret_cast< qreal*>(_v)); break;
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

const QMetaObject *QtMaterialFlatButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialFlatButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialFlatButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int QtMaterialFlatButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
