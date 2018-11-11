#ifndef RPARAMETER_H
#define RPARAMETER_H

#include <QString>
#include <QStringList>
#include <QObject>

enum TenValueType
{
    ValueType_bool,
    ValueType_int,
    ValueType_double,
    ValueType_list
};

const QString DEFAULT_VALUE = "default";

class Q_DECL_EXPORT RParameter: public QObject
{
Q_OBJECT

public:
    RParameter(QString name, QString value, TenValueType type, QString min, QString max, QObject* parent = 0);
    RParameter(QString name, QString value, QStringList list, QObject* parent = 0);
    RParameter(QString name, QString state, QObject* parent = 0);

    TenValueType getType() const;
    QString getValue() const;
    QString getName() const;

    bool setValue(QString value);
    void setReadOnly(bool isOnlyRead);
    bool isReadOnly() const;

    QStringList errorsOutput; //debug

private:
    QString nameParameter; //имя параметра
    QString currentValue; //текущее значение
    QString maxValue; //максимальное значение (для типов ValueType_int, ValueType_double)
    QString minValue; //минимальное значение (для типов ValueType_int, ValueType_double)
    QStringList listValues; //список значений (для типа ValueType_list)
    TenValueType typeValue; //тип значения
    QString nameMeasure; //unused // наименование измеряемой величины
    bool readOnly;

    bool isValueValid(QString value);

signals:
    void signalValueChanged(QString value);


};

#endif // RPARAMETER_H
