#include "vehiclevalidator.h"

VehicleValidator::VehicleValidator(QString vehicleName, QString manufacturer, QString year, double miles, int quantity, double price):
    vehicleName(vehicleName), manufacturer(manufacturer), year(year), miles(miles), quantity(quantity), price(price) {}

bool VehicleValidator::validate(QString &message)
{
    bool valid = true;

    if (vehicleName == "") {
        valid = false;
        message += "\nVehicle name cannot be blank";
    }

    if (manufacturer == "") {
        valid = false;
        message += "\nManufacturer cannot be blank";
    }

    if (year == "") {
        valid = false;
        message += "\nPlease enter the year of manufacture";
    }

    if (miles == 0.0) {
        valid = false;
        message += "\nPlease enter the current odometer reading";
    }

    if (quantity == 0) {
        valid = false;
        message += "\nPlease enter the quantity";
    }

    if (price == 0.0) {
        valid = false;
        message += "\nPlease enter the selling price";
    }

    return valid;
}
