#ifndef SALESMODEL_H
#define SALESMODEL_H

#include <QString>
#include <QSqlQuery>

class SalesModel
{
public:
    static QSqlQuery list(QString searchFor);
    static SalesModel load(int id);

    SalesModel(int id, int customerId, int vehicleId, int sellerId, QString registration, QString addedDate);
    SalesModel(int id);
    SalesModel();

    bool save();

    int getCustomerId() { return customerId; }
    int getVehicleId() { return vehicleId; }
    int getSellerId() { return sellerId; }
    QString getRegistration() { return registration; }
    QString getAddedDate() { return addedDate; }

private:
    int id;
    int customerId;
    int vehicleId;
    int sellerId;
    QString registration;
    QString addedDate;
};

#endif // SALESMODEL_H
