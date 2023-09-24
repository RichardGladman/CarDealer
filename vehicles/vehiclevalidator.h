#ifndef VEHICLEVALIDATOR_H
#define VEHICLEVALIDATOR_H

#include <QString>

#include "vehicle.h"


class VehicleValidator
{
public:
    VehicleValidator(Vehicle vehicle);

    bool validate(QString &message);

private:
    Vehicle vehicle;
};

#endif // VEHICLEVALIDATOR_H
