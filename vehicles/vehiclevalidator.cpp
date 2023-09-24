#include "vehiclevalidator.h"

VehicleValidator::VehicleValidator(Vehicle vehicle): vehicle(vehicle) {}

bool VehicleValidator::validate(QString &message)
{
    bool valid = true;

    if (vehicle.getName() == "") {
        valid = false;
        message += "\nVehicle name cannot be blank";
    }

    if (vehicle.getManufacturer() == "") {
        valid = false;
        message += "\nManufacturer cannot be blank";
    }

    if (vehicle.getYearOfManufacture() == "") {
        valid = false;
        message += "\nPlease enter the year of manufacture";
    }

    if (vehicle.getMiles() == 0.0) {
        valid = false;
        message += "\nPlease enter the current odometer reading";
    }

    if (vehicle.getQuantity() == 0) {
        valid = false;
        message += "\nPlease enter the quantity";
    }

    if (vehicle.getPrice() == 0.0) {
        valid = false;
        message += "\nPlease enter the selling price";
    }

    return valid;
}
