#ifndef SELLERVALIDATOR_H
#define SELLERVALIDATOR_H

#include <QString>


class SellerValidator
{
public:
    SellerValidator(QString firstName, QString lastName, QString email, QString phone);
    bool validate(QString &message);

private:
    QString firstName;
    QString lastName;
    QString email;
    QString phone;
};

#endif // SELLERVALIDATOR_H
