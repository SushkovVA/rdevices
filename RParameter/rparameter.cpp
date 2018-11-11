#include "rparameter.h"

#include "iostream" ///

RParameter::RParameter(QString name, QString value, TenValueType type, QString min, QString max, QObject* parent):
    QObject(parent),
    nameParameter(name),
    currentValue(value),
    maxValue(max),
    minValue(min),
    listValues(0),
    typeValue(type)

{
    readOnly = false;
}

TenValueType RParameter::getType() const
{
    return typeValue;
}

RParameter::RParameter(QString name, QString value, QStringList list, QObject* parent):
    QObject(parent),
    nameParameter(name),
    currentValue(value),
    listValues(list)

{
    maxValue = "";
    minValue = "";
    typeValue = ValueType_list;
    readOnly = true;
}

RParameter::RParameter(QString name, QString state, QObject *parent):
QObject(parent),
nameParameter(name)
{
    typeValue = ValueType_bool;
    currentValue = state;
}

bool RParameter::setValue(QString value)
{
    if (currentValue == value)
        return false;

    bool isOk = isValueValid(value);
    if (isOk)
    {
        currentValue = value;
        emit signalValueChanged(value);
    }
    else
        errorsOutput << nameParameter+"::setValue "+value+" is not valid!";
    return isOk;
}

void RParameter::setReadOnly(bool isOnlyRead)
{
    readOnly = isOnlyRead;
}

bool RParameter::isReadOnly() const
{
    return readOnly;
}

QString RParameter::getValue() const
{
    return currentValue;
}

QString RParameter::getName() const
{
    return nameParameter;
}

bool RParameter::isValueValid(QString value)
{
    if ( typeValue == ValueType_int )
    {
        int inTypeValue = value.toInt();
        if (inTypeValue <= maxValue.toInt() && inTypeValue >= minValue.toInt() )
            return true;
        else
            errorsOutput << nameParameter+"::isValueValid - "+value+
                            " : this value is not in interval ["+minValue+
                            ":"+maxValue+"]";
    }

    if ( typeValue == ValueType_double )
    {
        double inTypeValue = value.toDouble();
        if (inTypeValue <= maxValue.toDouble() && inTypeValue >= minValue.toDouble() )
            return true;
        else
            errorsOutput << nameParameter+"::isValueValid - "+value+
                            " : this value is not in interval ["+minValue+
                            ":"+maxValue+"]";
    }

    if ( typeValue == ValueType_list )
    {
        if ( listValues.contains(value) )
        {
            errorsOutput << nameParameter+"::isValueValid "+value+" Value is not in the list!";
            return true;
        }
    }

    if ( typeValue == ValueType_bool )
    {
        if ( value == "on" || value == "off" )
            return true;
    }

    return false;
}
