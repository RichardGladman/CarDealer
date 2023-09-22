#include "customervalidator.h"

CustomerValidator::CustomerValidator(QString name, QString address, QString email, QString phone): name(name), address(address), email(email), phone(phone) {}

bool CustomerValidator::validate(QString &message)
{
    bool valid = true;

    if (name == "") {
        valid = false;
        message += "\nName cannot be left blank";
    }

    if (address == "") {
        valid = false;
        message += "\nAddress cannot be left blank";
    }

    if (email == "") {
        valid = false;
        message += "\nEmail cannot be left blank";
    }

    if (phone == "") {
        valid = false;
        message += "\nPhone cannot be left blank";
    }

    return valid;
}
