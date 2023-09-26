#include "salesmodel.h"

QSqlQuery SalesModel::list(QString searchFor)
{
    QString target = "%" + searchFor + "%";

    QString sql = "SELECT s.id, c.name, v.name, v.manufacturer, v.year_of_manufacture, v.vehicle_condition ";
    sql += "FROM sales s ";
    sql += "INNER JOIN vehicles v on s.vehicle_id = v.id ";
    sql += "INNER JOIN customers c on s.customer_id  = c.id ";

    if (searchFor != "") {
        sql += "WHERE c.name LIKE ? OR v.name LIKE ? or v.manufacturer LIKE ?";
    }

    sql += "ORDER BY c.name, v.name ";

    QSqlQuery query;
    query.prepare(sql);

    if (searchFor != "") {
        query.addBindValue(target);
        query.addBindValue(target);
        query.addBindValue(target);
    }

    query.exec();

    return query;
}

SalesModel SalesModel::load(int id)
{
    QString sql = "SELECT * FROM sales WHERE id = ?";

    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        SalesModel salesModel {id, query.value(1).toInt(), query.value(2).toInt(), query.value(3).toInt(), query.value(4).toString(), query.value(5).toString()};
        return salesModel;
    }

    SalesModel salesModel;
    return salesModel;
}

SalesModel::SalesModel(int id, int customerId, int vehicleId, int sellerId, QString registration, QString addedDate):
    id(id), customerId(customerId), vehicleId(vehicleId), sellerId(sellerId), registration(registration), addedDate(addedDate) {}

SalesModel::SalesModel(int id): id(id){}

SalesModel::SalesModel() {}

bool SalesModel::save()
{
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO sales(vehicle_id, customer_id, seller_id, registration) VALUES(?, ?, ?, ?)");
    insertQuery.addBindValue(vehicleId);
    insertQuery.addBindValue(customerId);
    insertQuery.addBindValue(sellerId);
    insertQuery.addBindValue(registration);

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE vehicles SET quantity = quantity - 1 WHERE id=?");
    updateQuery.addBindValue(vehicleId);

    return insertQuery.exec() && updateQuery.exec();
}
