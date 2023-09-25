#ifndef SALESMODEL_H
#define SALESMODEL_H

#include <QString>
#include <QSqlQuery>

class SalesModel
{
public:
    static QSqlQuery list(QString searchFor);

    SalesModel();
};

#endif // SALESMODEL_H
