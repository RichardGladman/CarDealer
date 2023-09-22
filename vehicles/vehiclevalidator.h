#ifndef VEHICLEVALIDATOR_H
#define VEHICLEVALIDATOR_H

#include <QString>


class VehicleValidator
{
public:
    VehicleValidator(QString vehicleName, QString manufacturer, QString year, double miles, int quantity, double price);

    bool validate(QString &message);

private:
    QString vehicleName;
    QString manufacturer;
    QString year;
    double miles;
    int quantity;
    double price;
};

#endif // VEHICLEVALIDATOR_H
