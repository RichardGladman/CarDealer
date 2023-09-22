#ifndef CUSTOMERVALIDATOR_H
#define CUSTOMERVALIDATOR_H

#include <QString>


class CustomerValidator
{
public:
    CustomerValidator(QString name, QString address, QString email, QString phone);
    bool validate(QString &message);

private:
    QString name;
    QString address;
    QString email;
    QString phone;
};

#endif // CUSTOMERVALIDATOR_H
