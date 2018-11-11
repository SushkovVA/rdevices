/****************************************************************************
** Meta object code from reading C++ file 'rdevice.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/rdevice.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rdevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RDevice[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,    8,   69,    8, 0x0a,
     107,   93,   69,    8, 0x0a,
     130,    9,  125,    8, 0x0a,
     168,    8,  156,    8, 0x0a,
     192,    8,  188,    8, 0x0a,
     232,  225,  213,    8, 0x0a,
     255,  250,  213,    8, 0x0a,
     277,   93,    8,    8, 0x09,
     297,    8,    8,    8, 0x29,
     316,  310,    8,    8, 0x09,
     366,  342,  125,    8, 0x09,
     441,  425,  125,    8, 0x09,
     494,  483,  125,    8, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_RDevice[] = {
    "RDevice\0\0nameParameter,value\0"
    "signalParameterChanged(QString,QString)\0"
    "QString\0getNameDevice()\0nameParameter\0"
    "getValue(QString)\0bool\0setValue(QString,QString)\0"
    "QStringList\0getParametersList()\0int\0"
    "getParametersCount()\0RParameter*\0"
    "number\0getParameter(int)\0name\0"
    "getParameter(QString)\0updateData(QString)\0"
    "updateData()\0value\0parameterChanged(QString)\0"
    "name,value,type,min,max\0"
    "addParameter(QString,QString,TenValueType,QString,QString)\0"
    "name,value,list\0"
    "addParameter(QString,QString,QStringList)\0"
    "name,value\0addParameter(QString,QString)\0"
};

void RDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RDevice *_t = static_cast<RDevice *>(_o);
        switch (_id) {
        case 0: _t->signalParameterChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: { QString _r = _t->getNameDevice();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->getValue((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->setValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { QStringList _r = _t->getParametersList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->getParametersCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { RParameter* _r = _t->getParameter((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< RParameter**>(_a[0]) = _r; }  break;
        case 7: { RParameter* _r = _t->getParameter((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< RParameter**>(_a[0]) = _r; }  break;
        case 8: _t->updateData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->updateData(); break;
        case 10: _t->parameterChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: { bool _r = _t->addParameter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< TenValueType(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->addParameter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->addParameter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RDevice::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RDevice::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RDevice,
      qt_meta_data_RDevice, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RDevice::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RDevice))
        return static_cast<void*>(const_cast< RDevice*>(this));
    return QObject::qt_metacast(_clname);
}

int RDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void RDevice::signalParameterChanged(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
