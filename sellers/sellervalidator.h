#ifndef SELLERVALIDATOR_H
#define SELLERVALIDATOR_H

#include <QString>
#include "seller.h"


class SellerValidator
{
public:
    SellerValidator(Seller seller);
    bool validate(QString &message);

private:
    Seller seller;
};

#endif // SELLERVALIDATOR_H
