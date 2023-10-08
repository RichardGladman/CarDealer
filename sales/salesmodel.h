#ifndef SALESMODEL_H
#define SALESMODEL_H

#include <QString>
#include <QSqlQuery>

class SalesModel
{
public:
    static QSqlQuery list(QString searchFor);
    static SalesModel load(int id);
    static QSqlQuery allSalesByMonth(QString year);
    static QSqlQuery allSalesByYear(int limit);
    static QSqlQuery customerByYear(QString year, QString order, int limit);
    static QSqlQuery sellerByMonth(QString year, QString month, QString order, int limit);
    static QSqlQuery sellerByYear(QString year, QString order, int limit);

    SalesModel(int id, int customerId, int vehicleId, int sellerId, QString registration, QString addedDate, double negotiatedPrice);
    SalesModel(int id);
    SalesModel();

    bool save();

    int getId() { return id; }
    int getCustomerId() { return customerId; }
    int getVehicleId() { return vehicleId; }
    int getSellerId() { return sellerId; }
    QString getRegistration() { return registration; }
    QString getAddedDate() { return addedDate; }
    double getNegotiatedPrice() { return negotiatedPrice; }

private:
    int id;
    int customerId;
    int vehicleId;
    int sellerId;
    QString registration;
    QString addedDate;
    double negotiatedPrice;
};

#endif // SALESMODEL_H
