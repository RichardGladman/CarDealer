#include "seller.h"

Seller Seller::load(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM sellers WHERE id=?");
    query.addBindValue(id);

    if (query.exec()) {
        if (query.next()) {
            Seller seller {query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString()};
            return seller;
        }
    }

    Seller seller;
    return seller;
}

QSqlQuery Seller::list(QString searchFor)
{
    QString target = "%" + searchFor + "%";
    QString sql = "SELECT * FROM sellers";

    if (searchFor != "") {
        sql += " WHERE first_name LIKE ? OR last_name LIKE ? or email LIKE ? or phone LIKE ?";
    }

    QSqlQuery query;
    query.prepare(sql);

    if (searchFor != "") {
        query.addBindValue(target);
        query.addBindValue(target);
        query.addBindValue(target);
        query.addBindValue(target);
    }

    query.exec();

    return query;
}

Seller::Seller(int id, QString firstName, QString lastName, QString email, QString phone): id(id), firstName(firstName), lastName(lastName), email(email), phone(phone) {}
Seller::Seller(int id): id(id) {}
Seller::Seller() {}

bool Seller::save()
{
    QString sql;

    if (id == 0) {
        sql = "INSERT INTO sellers(first_name, last_name, email, phone) VALUES(?, ?, ?, ?)";
    } else {
        sql = "UPDATE sellers SET first_name=?, last_name=?, email=?, phone=? WHERE id=?";
    }

    QSqlQuery updateQuery;
    updateQuery.prepare(sql);

    updateQuery.addBindValue(firstName);
    updateQuery.addBindValue(lastName);
    updateQuery.addBindValue(email);
    updateQuery.addBindValue(phone);

    if (id != 0) {
        updateQuery.addBindValue(id);
    }

    return updateQuery.exec();
}

bool Seller::deleteSeller()
{
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM sellers WHERE id=?");
    deleteQuery.addBindValue(id);

    return deleteQuery.exec();

}

