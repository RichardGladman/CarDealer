#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>
#include <QSqlQuery>


class Vehicle
{
public:
    static Vehicle load(int id);
    static QSqlQuery list(QString searchFor);

    Vehicle(int id, QString name, QString manufacturer, QString yearOfManufacture, double miles, QString vehicleCondition,
            QString drive, int quantity, double price, QString currency, QString picture, QByteArray pictureBytes = QByteArray());
    Vehicle(int id);
    Vehicle();

    bool save();
    bool deleteById();

    int getId() { return id; }
    QString getName() { return name; }
    QString getManufacturer() { return manufacturer; }
    QString getYearOfManufacture() { return yearOfManufacture; }
    double getMiles() { return miles; }
    QString getVehicleCondition() { return vehicleCondition; }
    QString getDrive() { return drive; }
    int getQuantity() { return quantity; }
    double getPrice() { return price; }
    QString getCurrency() { return currency; }
    QString getPicture() { return picture; }
    QByteArray getPictureBytes() { return pictureBytes; }

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
    QByteArray pictureBytes;
};

#endif // VEHICLE_H
