#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>
#include <QSqlQuery>


class Vehicle
{
public:
    Vehicle(int id, QString name, QString manufacturer, QString yearOfManufacture, double miles, QString vehicleCondition,
            QString drive, int quantity, double price, QString currency, QString picture);
    Vehicle(int id);
    Vehicle();

    bool save();

    int getId() { return id; }
    QString getName() { return name; }
    QString getManufacturer() { return manufacturer; }
    double getMiles() { return miles; }
    QString getVehicleCondition() { return vehicleCondition; }
    QString getDrive() { return drive; }
    int getQuantity() { return quantity; }
    double getPrice() { return price; }
    QString getCurrency() { return currency; }
    QString getPicture() { return picture; }

private:
    int id;
    QString name;
    QString manufacturer;
    QString yearOfManufacture;
    double miles;
    QString vehicleCondition;
    QString drive;
    int quantity;
    double price;
    QString currency;
    QString picture;
};

#endif // VEHICLE_H
