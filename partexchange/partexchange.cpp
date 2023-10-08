#include "partexchange.h"

PartExchange PartExchange::load(int id)
{

    QSqlQuery query;
    query.prepare("SELECT * FROM part_exchanges WHERE id=?");
    query.addBindValue(id);

    if (query.exec()) {
        if (query.next()) {
            PartExchange partEx {query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toDouble(),
                            query.value(5).toDouble(), query.value(6).toInt()};
            return partEx;
        }
    }

    PartExchange partEx;
    return partEx;
}

QSqlQuery PartExchange::list(QString searchFor)
{
    QString target = "%" + searchFor + "%";

    QString sql = "SELECT pe.*, v.make AS vmake, v.model AS vmodel FROM part_exchanges pe INNER JOIN vehicles v ON pe.sales_id = v.id";
    if (searchFor != "") {
        sql += " WHERE make LIKE ? OR model like ? or registration LIKE ?";
    }

    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(target);
    query.addBindValue(target);
    query.addBindValue(target);

    query.exec();

    return query;

}

PartExchange::PartExchange(int id, QString make, QString model, QString registration, double miles, double price, int salesId):
    id(id), make(make), model(model), registration(registration), miles(miles), price(price), salesId(salesId)
{

}

PartExchange::PartExchange(int id): id(id) {}

PartExchange::PartExchange()
{

}

int PartExchange::getId() const
{
    return id;
}

QString PartExchange::getMake() const
{
    return make;
}

QString PartExchange::getModel() const
{
    return model;
}

QString PartExchange::getRegistration() const
{
    return registration;
}

double PartExchange::getMiles() const
{
    return miles;
}

double PartExchange::getPrice() const
{
    return price;
}

int PartExchange::getSalesId() const
{
    return salesId;
}

bool PartExchange::save()
{
    QString sql;

    if (id == 0) {
        sql = "INSERT INTO part_exchanges(make, model, registration, miles, price, sales_id) VALUES(?, ?, ?, ?, ?, ?)";
    } else {
        sql = "UPDATE part_exchanges SET make=?, model=?, registration=?, miles=?, price=?, sales_id=? WHERE id=?";
    }

    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(make);
    query.addBindValue(model);
    query.addBindValue(registration);
    query.addBindValue(miles);
    query.addBindValue(price);
    query.addBindValue(salesId);

    if (id != 0) {
        query.addBindValue(id);
    }

    return query.exec();
}
