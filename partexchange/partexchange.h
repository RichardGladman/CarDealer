#ifndef PARTEXCHANGE_H
#define PARTEXCHANGE_H

#include <QString>
#include <QSqlQuery>

class PartExchange
{
public:
    static PartExchange load(int id);
    static QSqlQuery list(QString searchFor);

    PartExchange(int id, QString make, QString model, QString registration, double miles, double price, int salesId);
    PartExchange(int id);
    PartExchange();

    bool auction(int auctioned);
    bool addToStock(int stocked, int &vehicle_id);

    int getId() const;
    QString getMake() const;
    QString getModel() const;
    QString getRegistration() const;
    double getMiles() const;
    double getPrice() const;

    bool save();

    int getSalesId() const;

private:
    int id;
    QString make;
    QString model;
    QString registration;
    double miles;
    double price;
    int salesId;
};

#endif // PARTEXCHANGE_H
