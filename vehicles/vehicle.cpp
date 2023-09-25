#include "vehicle.h"

#include <QFile>
#include <QDebug>

Vehicle Vehicle::load(int id)
{

    QSqlQuery query;
    query.prepare("SELECT * FROM vehicles WHERE id=?");
    query.addBindValue(id);

    if (query.exec()) {
        if (query.next()) {
            Vehicle vehicle {query.value(0).toInt(), query.value(10).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toDouble(),
                            query.value(4).toString(), query.value(5).toString(), query.value(6).toInt(), query.value(7).toDouble(), query.value(8).toString(),
                            QString(), query.value(9).toByteArray()};
            return vehicle;
        }
    }

    Vehicle vehicle;
    return vehicle;
}

Vehicle::Vehicle(int id, QString name, QString manufacturer, QString yearOfManufacture, double miles, QString vehicleCondition,
                 QString drive, int quantity, double price, QString currency, QString picture, QByteArray pictureBytes):
    id(id), name(name), manufacturer(manufacturer), yearOfManufacture(yearOfManufacture), miles(miles), vehicleCondition(vehicleCondition),
    drive(drive), quantity(quantity), price(price), currency(currency), picture(picture), pictureBytes(pictureBytes) {}
Vehicle::Vehicle(int id): id(id) {}
Vehicle::Vehicle() {}

bool Vehicle::save()
{
    QString sql;
    QByteArray pictureBytes;

    if (picture != "") {
        QFile file(picture);

        if (file.open(QIODevice::ReadOnly)) {
            pictureBytes = file.readAll();
            file.close();
        }
    }

    if (id == 0) {
        sql = "INSERT INTO vehicles(name, manufacturer, year_of_manufacture, miles, vehicle_condition, drive, quantity, price, currency, picture) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    } else {
        sql = "UPDATE vehicles SET name=?, manufacturer=?, year_of_manufacture=?, miles=?, vehicle_condition=?, drive=?, quantity=?, price=?, currency=?";

        if (picture != "") {
            sql += ", picture=?";
        }

        sql += " WHERE id=?";
    }

    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(name);
    query.addBindValue(manufacturer);
    query.addBindValue(yearOfManufacture);
    query.addBindValue(miles);
    query.addBindValue(vehicleCondition);
    query.addBindValue(drive);
    query.addBindValue(quantity);
    query.addBindValue(price);
    query.addBindValue(currency);

    if (picture != "" || id == 0) {
        query.addBindValue(pictureBytes);
    }

    if (id != 0) {
        query.addBindValue(id);
    }

    return query.exec();
}

bool Vehicle::deleteById()
{
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM vehicles WHERE id=?");
    deleteQuery.addBindValue(id);

    return deleteQuery.exec();

}
