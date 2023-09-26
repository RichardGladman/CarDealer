#include "customer.h"

#include <QSqlQuery>

Customer Customer::load(int id)
{

    QSqlQuery query;
    query.prepare("SELECT * FROM customers WHERE id=?");
    query.addBindValue(id);

    if (query.exec()) {
        if (query.next()) {
            Customer customer {query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString()};
            return customer;
        }
    }

    Customer customer;
    return customer;
}

QSqlQuery Customer::list(QString searchFor)
{
    QString target = "%" + searchFor + "%";
    QString sql = "SELECT id, name, email, phone FROM customers";

    if (searchFor != "") {
        sql += " WHERE name LIKE ? OR email LIKE ? OR phone LIKE ?";
    }

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

QVector<Customer> Customer::list()
{
    QVector<Customer> customers;
    QSqlQuery query;

    query.prepare("SELECT * FROM customers ORDER BY name");
    if (query.exec()) {
        while (query.next()) {
            customers.push_back(Customer {query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString()});
        }
    }

    return customers;
}


Customer::Customer(int id, QString name, QString address, QString email, QString phone): id(id), name(name), address(address), email(email), phone(phone) {}
Customer::Customer(int id): id(id) {}
Customer::Customer() {}

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

bool Customer::deleteCustomer()
{
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM customers WHERE id=?");
    deleteQuery.addBindValue(id);

    return deleteQuery.exec();
}
