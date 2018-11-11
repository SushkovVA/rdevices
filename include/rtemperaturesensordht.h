#ifndef RTEMPERATURESENSORDHT_H
#define RTEMPERATURESENSORDHT_H

#include "rdevice.h"

class Q_DECL_EXPORT RTemperatureSensorDHT : public RDevice
{
    Q_OBJECT
public:
    explicit RTemperatureSensorDHT(QString name, int gpioOut, QObject *parent = 0);

public slots:
    void updateData(QString nameParameter = "");

signals:

protected:

private:
    int gpioOutPin;

    void updateTemperature();
    void updateHumidity();

};

#endif // RTEMPERATURESENSORDHT_H
