#include "viewcustomerdialog.h"
#include "ui_viewcustomerdialog.h"

#include <QSqlQuery>
#include <QDebug>

#include "customer.h"

ViewCustomerDialog::ViewCustomerDialog(int id, QWidget *parent) : QDialog(parent), ui(new Ui::ViewCustomerDialog)
{
    ui->setupUi(this);
    this->id = id;

    Customer customer = Customer::load(id);

    ui->labelName->setText(customer.getName());
    ui->labelAddress->setText(customer.getAddress());
    ui->labelEmail->setText(customer.getEmail());
    ui->labelPhone->setText(customer.getPhone());
}

ViewCustomerDialog::~ViewCustomerDialog()
{
    delete ui;
}

void ViewCustomerDialog::on_pushButtonClose_clicked()
{
    this->close();
}

