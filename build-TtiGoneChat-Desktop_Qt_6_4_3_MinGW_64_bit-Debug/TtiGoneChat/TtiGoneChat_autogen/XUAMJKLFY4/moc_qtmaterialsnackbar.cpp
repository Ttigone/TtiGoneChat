/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialsnackbar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../TtiGoneChat/3rdparty/qt-material/components/qtmaterialsnackbar.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialsnackbar.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_QtMaterialSnackbar_t {
    uint offsetsAndSizes[12];
    char stringdata0[19];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[18];
    char stringdata5[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_QtMaterialSnackbar_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_QtMaterialSnackbar_t qt_meta_stringdata_QtMaterialSnackbar = {
    {
        QT_MOC_LITERAL(0, 18),  // "QtMaterialSnackbar"
        QT_MOC_LITERAL(19, 10),  // "addMessage"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 7),  // "message"
        QT_MOC_LITERAL(39, 17),  // "addInstantMessage"
        QT_MOC_LITERAL(57, 7)   // "dequeue"
    },
    "QtMaterialSnackbar",
    "addMessage",
    "",
    "message",
    "addInstantMessage",
    "dequeue"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_QtMaterialSnackbar[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x0a,    1 /* Public */,
       4,    1,   35,    2, 0x0a,    3 /* Public */,
       5,    0,   38,    2, 0x09,    5 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtMaterialSnackbar::staticMetaObject = { {
    QMetaObject::SuperData::link<QtMaterialOverlayWidget::staticMetaObject>(),
    qt_meta_stringdata_QtMaterialSnackbar.offsetsAndSizes,
    qt_meta_data_QtMaterialSnackbar,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_QtMaterialSnackbar_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtMaterialSnackbar, std::true_type>,
        // method 'addMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addInstantMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'dequeue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QtMaterialSnackbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtMaterialSnackbar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->addInstantMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->dequeue(); break;
        default: ;
        }
    }
}

const QMetaObject *QtMaterialSnackbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialSnackbar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialSnackbar.stringdata0))
        return static_cast<void*>(this);
    return QtMaterialOverlayWidget::qt_metacast(_clname);
}

int QtMaterialSnackbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtMaterialOverlayWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
