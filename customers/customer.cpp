#include "customer.h"

#include <QSqlQuery>

Customer::Customer(int id, QString name, QString address, QString email, QString phone): id(id), name(name), address(address), email(email), phone(phone) {}

bool Customer::save()
{
    QString sql;

    if (id == 0) {
        sql = "INSERT INTO customers(name, address, email, phone) VALUES(?, ?, ?, ?)";
    } else {
        sql = "UPDATE customers SET name=?, address=?, email=?, phone=? WHERE id=?";
    }

    QSqlQuery updateQuery;
    updateQuery.prepare(sql);

    updateQuery.addBindValue(name);
    updateQuery.addBindValue(address);
    updateQuery.addBindValue(email);
    updateQuery.addBindValue(phone);

    if (id != 0) {
        updateQuery.addBindValue(id);
    }


     return updateQuery.exec();
}
