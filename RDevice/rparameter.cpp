#include "rparameter.h"


RParameter::RParameter(QString name, QString value, TenValueType type, QString min, QString max, QObject* parent):
    QObject(parent),
    nameParameter(name),
    currentValue(value),
    maxValue(max),
    minValue(min),
    listValues(0),
    typeValue(type)

{
    readOnly = true;
}

RParameter::~RParameter()
{
    if (listValues)
        delete listValues;
}

RParameter::RParameter(QString name, QString value, QStringList* list, QObject* parent):
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

bool RParameter::setValue(QString value)
{
    bool isOk = isValueValid(value);
    if (isOk)
    {
        currentValue = value;
        emit valueChanged();
    }
    else
        errorsOutput << nameParameter+"::setValue "+value+" is not valid!";
    return isOk;

}

void RParameter::setReadOnly(bool isOnlyRead)
{
    readOnly = isOnlyRead;
}

bool RParameter::isReadOnly()
{
    return readOnly;
}

QString RParameter::getValue()
{
    return currentValue;
}

// PRIVATE:

bool RParameter::isValueValid(QString value)
{
    switch (typeValue)
    {

    case ValueType_int:
    {
        int inTypeValue = value.toInt();
        if (inTypeValue > maxValue.toInt())
        {
            errorsOutput << nameParameter+"::isValueValid "+value+" Value too BIG!";
            return false;
        }
        else if (inTypeValue < minValue.toInt())
        {
            errorsOutput << nameParameter+"::isValueValid "+value+" Value too SMALL!";
            return false;
        }
        break;
    }

    case ValueType_double:
    {
        double inTypeValue = value.toDouble();
        if (inTypeValue > maxValue.toDouble())
        {
            errorsOutput << nameParameter+"::isValueValid "+value+" Value is too BIG!";
            return false;
        }
        else if (inTypeValue < minValue.toDouble())
        {
            errorsOutput << nameParameter+"::isValueValid "+value+" Value is too SMALL!";
            return false;
        }
        break;
    }

    case ValueType_list:
    {
        if ( ! listValues->contains(value) )
        {
            errorsOutput << nameParameter+"::isValueValid "+value+" Value is not in the list!";
            return false;
        }
        break;
    }

    }

    return true;
}
