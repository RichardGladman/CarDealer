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

QSqlQuery SalesModel::allSalesByMonth(QString year)
{
    QString sql = "SELECT YEAR(s.added_date) AS y, MONTH(s.added_date) AS m, count(s.id), sum(v.price) FROM sales s";
    sql += " INNER JOIN vehicles v ON s.vehicle_id = v.id";
    sql += " WHERE YEAR(s.added_date) = ?";
    sql += " GROUP BY y, m";

    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(year);
    query.exec();

    return query;
}

QSqlQuery SalesModel::allSalesByYear(int limit)
{
    QString sql = "SELECT YEAR(s.added_date) AS y, count(s.id), sum(v.price) FROM sales s";
    sql += " INNER JOIN vehicles v ON s.vehicle_id = v.id";
    sql += " GROUP BY y";

    if (limit != 0) {
        sql += " LIMIT " + QString::number(limit);
    }

    QSqlQuery query;
    query.prepare(sql);
    query.exec();

    return query;
}

QSqlQuery SalesModel::customerByYear(QString year, QString order, int limit)
{
    QString startDate = year + "-01-01 00:00:00";
    QString endDate = year + "-12-31 23:59:59";

    QString sql = "SELECT c.name, count(s.id), sum(v.price) AS total FROM sales s INNER JOIN customers c ON s.customer_id = c.id";
    sql += " INNER JOIN vehicles v ON s.vehicle_id = v.id WHERE s.added_date BETWEEN '" + startDate + "' AND '" + endDate + "'";
    sql += " GROUP BY c.id";
    sql += " ORDER BY total";

    if (order == "best") {
        sql += " DESC";
    }

    if (limit != 0) {
        sql += " LIMIT " + QString::number(limit);
    }

    QSqlQuery query;
    query.prepare(sql);
    query.exec();

    return query;
}

QSqlQuery SalesModel::sellerByMonth(QString year, QString month, QString order, int limit)
{
    QString startDate = year + "-" + month + "-01 00:00:00";
    QString endDate = year + "-" + month + "-31 23:59:59";

    QString sql = "SELECT p.first_name, p.last_name, count(s.id), sum(v.price) AS total FROM sales s INNER JOIN sellers p ON s.seller_id = p.id";
    sql += " INNER JOIN vehicles v ON s.vehicle_id = v.id WHERE s.added_date BETWEEN '" + startDate + "' AND '" + endDate + "'";
    sql += " GROUP BY p.id";
    sql += " ORDER BY total";

    if (order == "best") {
        sql += " DESC";
    }

    if (limit != 0) {
        sql += " LIMIT " + QString::number(limit);
    }

    QSqlQuery query;
    query.prepare(sql);
    query.exec();

    return query;
}

QSqlQuery SalesModel::sellerByYear(QString year, QString order, int limit)
{
    QString startDate = year + "-01-01 00:00:00";
    QString endDate = year + "-12-31 23:59:59";

    QString sql = "SELECT p.first_name, p.last_name, count(s.id), sum(v.price) as total FROM sales s INNER JOIN sellers p ON s.seller_id = p.id";
    sql += " INNER JOIN vehicles v ON s.vehicle_id = v.id WHERE s.added_date BETWEEN '" + startDate + "' AND '" + endDate + "'";
    sql += " GROUP BY p.id";

    sql += " ORDER BY total";

    if (order == "best") {
        sql += " DESC";
    }

    if (limit != 0) {
        sql += " LIMIT " + QString::number(limit);
    }

    QSqlQuery query;
    query.prepare(sql);
    query.exec();

    return query;
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
