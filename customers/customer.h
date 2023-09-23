#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include <QSqlQuery>

class Customer
{
public:
    static Customer load(int id);
    static QSqlQuery list(QString searchFor);

    Customer(int id, QString name, QString address, QString email, QString phone);
    Customer(int id);
    Customer();

     bool save();
    bool deleteCustomer();

    QString getName() { return name; }
    QString getAddress() { return address; }
    QString getEmail() { return email; }
    QString getPhone() { return phone; }

private:
    int id;
    QString name;
    QString address;
    QString email;
    QString phone;
};

#endif // CUSTOMER_H
