#ifndef RDEVICE_H
#define RDEVICE_H

#include <QObject>
#include <QList>
#include "rparameter.h"

class Q_DECL_EXPORT RDevice: public QObject
{
Q_OBJECT

public:
    RDevice(QString name, QObject* parent = 0);
    ~RDevice();

    QStringList errorsOutput; //debug
    bool isParameterExist(QString name);

public slots:
    QString getNameDevice();
    virtual QString getValue(QString nameParameter);
    virtual bool setValue(QString nameParameter, QString value);
    QStringList getParametersList();
    int getParametersCount();

signals:
    void signalParameterChanged(QString nameParameter, QString value);

protected:
    QString nameDevice;


protected slots:
    // осторожно, вернет NULL, если нет такого параметра
    RParameter* getParameter(int number);
    RParameter* getParameter(QString name);
    // переопределяется реальным устройством
    virtual void updateData(QString nameParameter = "") = 0;
    void parameterChanged(QString value);
    bool addParameter(QString name, QString value, TenValueType type, QString min, QString max);
    bool addParameter(QString name, QString value, QStringList list);
    bool addParameter(QString name, QString value);

private:
    QList<RParameter*> parameters;

};

#endif // RDEVICE_H
