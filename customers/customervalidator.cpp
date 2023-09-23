#include "customervalidator.h"

CustomerValidator::CustomerValidator(Customer customer): customer(customer) {}

bool CustomerValidator::validate(QString &message)
{
    bool valid = true;

    if (customer.getName() == "") {
        valid = false;
        message += "\nName cannot be left blank";
    }

    if (customer.getAddress() == "") {
        valid = false;
        message += "\nAddress cannot be left blank";
    }

    if (customer.getEmail() == "") {
        valid = false;
        message += "\nEmail cannot be left blank";
    }

    if (customer.getPhone() == "") {
        valid = false;
        message += "\nPhone cannot be left blank";
    }

    return valid;
}
