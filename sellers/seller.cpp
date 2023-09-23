#include "seller.h"

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

