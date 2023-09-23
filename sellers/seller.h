#ifndef SELLER_H
#define SELLER_H

#include <QString>
#include <QSqlQuery>


class Seller
{
public:
    Seller(int id, QString firstName, QString lastName, QString email, QString phone);
    Seller(int id);
    Seller();

    bool save();

    QString getFirstName() { return firstName; }
    QString getLastName() { return lastName; }
    QString getEmail() { return email; }
    QString getPhone() { return phone; }

private:
    int id;
    QString firstName;
    QString lastName;
    QString email;
    QString phone;
};

#endif // SELLER_H
