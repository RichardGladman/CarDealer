#ifndef CUSTOMERVALIDATOR_H
#define CUSTOMERVALIDATOR_H

#include "customer.h"


class CustomerValidator
{
public:
    CustomerValidator(Customer customer);
    bool validate(QString &message);

private:
    Customer customer;
};

#endif // CUSTOMERVALIDATOR_H
