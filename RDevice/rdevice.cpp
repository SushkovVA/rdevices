#include "rdevice.h"

RDevice::RDevice(QString name, QObject* parent):
    QObject(parent),
    nameDevice(name)
{

}

RDevice::~RDevice()
{

}

QString RDevice::getNameDevice()
{
    return nameDevice;
}

QString RDevice::getValue(QString nameParameter)
{
    if ( isParameterExist(nameParameter) )
    {
        //Без указания имени параметра в updateData() обновляются все параметры устройства
        updateData(/*nameParameter*/);
        return getParameter(nameParameter)->getValue();
    }
    return "";
}

bool RDevice::setValue(QString nameParameter, QString value)
{
    if ( isParameterExist(nameParameter) )
    {
        RParameter* parameter = getParameter(nameParameter);

        if ( parameter->isReadOnly() )
            return false;

        return parameter->setValue(value);
    }

    return false;
}

QStringList RDevice::getParametersList()
{
    QStringList parametersList;
    for (int i = 0; i < parameters.size(); i++)
        parametersList << parameters[i]->getName();

    return parametersList;
}

int RDevice::getParametersCount()
{
    return parameters.size();
}

RParameter* RDevice::getParameter(int number)
{
    if ( number < getParametersCount() )
        return parameters[number];
    else
        return NULL;
}

bool RDevice::isParameterExist(QString name)
{
    // Если имя параметра "все", то сообщаем что такой параметр
    // существует если есть хотя бы один параметр у устройства
    if (name.toLower() == "all")
        return ( parameters.size() > 0 );

    for (int i = 0; i < parameters.size(); i++)
    {
        if (parameters[i]->getName() == name)
            return true;
    }
    errorsOutput << nameDevice+": someone looking for "+name+" but this parameter not exist.";
    return false;
}

RParameter* RDevice::getParameter(QString name)
{
    for (int i = 0; i < parameters.size(); i++)
    {
        if (parameters[i]->getName() == name)
            return parameters[i];
    }
    return NULL;
}

bool RDevice::addParameter(QString name, QString value, TenValueType type, QString min, QString max)
{
    if ( isParameterExist(name) )
    {
        errorsOutput << nameDevice+": addParameter "+name+ " is usuccess, parameter name alreary exist.";
        return false;
    }
    RParameter* newParameter = new RParameter(name, value, type, min, max, this);
    connect(newParameter, SIGNAL(signalValueChanged(QString)), SLOT(parameterChanged(QString)));
    parameters << newParameter;
    return true;
}

bool RDevice::addParameter(QString name, QString value, QStringList list)
{
    if ( isParameterExist(name) )
    {
        errorsOutput << nameDevice+": addParameter "+name+ " is usuccess, parameter name alreary exist.";
        return false;
    }
    RParameter* newParameter = new RParameter(name, value, list, this);
    connect(newParameter, SIGNAL(signalValueChanged(QString)), SLOT(parameterChanged(QString)));
    parameters << newParameter;
    return true;
}

bool RDevice::addParameter(QString name, QString value)
{
    if ( isParameterExist(name) )
    {
        errorsOutput << nameDevice+": addParameter "+name+ " is usuccess, parameter name alreary exist.";
        return false;
    }
    RParameter* newParameter = new RParameter(name, value, this);
    connect(newParameter, SIGNAL(signalValueChanged(QString)), SLOT(parameterChanged(QString)));
    parameters << newParameter;
    return true;
}

void RDevice::parameterChanged(QString value)
{
    RParameter* changedParameter = (RParameter*)sender();
    emit signalParameterChanged(changedParameter->getName(), value);
}
