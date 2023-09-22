#include "sellervalidator.h"

SellerValidator::SellerValidator(QString firstName, QString lastName, QString email, QString phone): firstName(firstName), lastName(lastName), email(email), phone(phone) {}

bool SellerValidator::validate(QString &message)
{
    bool valid {true};

    if (firstName == "") {
        valid = false;
        message += "\nFirst name cannot be left blank";
    }

    if (lastName == "") {
        valid = false;
        message += "\nLast name cannot be left blank";
    }

    if (email == "") {
        valid = false;
        message += "\nEmail cannot be left blank";
    }

    if (phone == "") {
        valid = false;
        message += "\nPhone number cannot be left blank";
    }

    return valid;
}
