/****************************************************************************
** Meta object code from reading C++ file 'render.h'
**
** Created: Thu Jul 21 13:47:03 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "render.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'render.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Render[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      21,    7,    7,    7, 0x0a,
      34,    7,   29,    7, 0x0a,
      50,    7,    7,    7, 0x0a,
      58,    7,    7,    7, 0x0a,
      65,    7,    7,    7, 0x0a,
      78,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Render[] = {
    "Render\0\0setShowAvg()\0setup()\0bool\0"
    "connectEmotiv()\0Pause()\0Play()\0"
    "setKey_Kat()\0setKey_Will()\0"
};

const QMetaObject Render::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Render,
      qt_meta_data_Render, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Render::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Render::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Render::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Render))
        return static_cast<void*>(const_cast< Render*>(this));
    return QWidget::qt_metacast(_clname);
}

int Render::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setShowAvg(); break;
        case 1: setup(); break;
        case 2: { bool _r = connectEmotiv();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: Pause(); break;
        case 4: Play(); break;
        case 5: setKey_Kat(); break;
        case 6: setKey_Will(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
