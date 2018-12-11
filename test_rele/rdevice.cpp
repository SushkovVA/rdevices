#include "rdevice.h"

RDevice::RDevice(QString name):
    name(name)
{

}

RDevice::~RDevice()
{
    for (int i = 0; i < parameters.size(); i++)
    if (parameters.at(i) != 0)
        delete parameters[i];
}

QString RDevice::getName()
{
    return name;
}

bool RDevice::isParameterExist(QString name)
{
    for (int i = 0; i < parameters.size(); i++)
    {
        if (parameters[i]->getName() == name)
            return true;
    }
    return false;
}

RParameter* RDevice::getParameter(QString name)
{
    for (int i = 0; i < parameters.size(); i++)
    {
        if (parameters[i]->getName() == name)
            return parameters[0];
    }
    return 0;
}

bool RDevice::addParameter(QString name, QString value, TenValueType type, QString min, QString max)
{
    if ( isParameterExist(name) )
    {
        errorsOutput << "RDevice::addParameter "+name+ " UNsuccess, parameter name alreary exist.";
        return false;
    }
    RParameter* newParameter = new RParameter(name, value, type, min, max, this);
    parameters << newParameter;
    return true;
}

bool RDevice::addParameter(QString name, QString value, QStringList* list)
{
    if ( isParameterExist(name) )
    {
        errorsOutput << "RDevice::addParameter "+name+ " UNsuccess, parameter name alreary exist.";
        return false;
    }
    RParameter* newParameter = new RParameter(name, value, list, this);
    parameters << newParameter;
    return true;
}
