#include "sellervalidator.h"

SellerValidator::SellerValidator(Seller seller): seller(seller) {}

bool SellerValidator::validate(QString &message)
{
    bool valid {true};

    if (seller.getFirstName() == "") {
        valid = false;
        message += "\nFirst name cannot be left blank";
    }

    if (seller.getLastName() == "") {
        valid = false;
        message += "\nLast name cannot be left blank";
    }

    if (seller.getEmail() == "") {
        valid = false;
        message += "\nEmail cannot be left blank";
    }

    if (seller.getPhone() == "") {
        valid = false;
        message += "\nPhone number cannot be left blank";
    }

    return valid;
}
