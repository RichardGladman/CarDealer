#include "newcustomerdialog.h"
#include "ui_newcustomerdialog.h"

#include <QSqlQuery>
#include <QMessageBox>

#include "customervalidator.h"
#include "customer.h"

NewCustomerDialog::NewCustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCustomerDialog)
{
    ui->setupUi(this);
}

NewCustomerDialog::~NewCustomerDialog()
{
    delete ui;
}

void NewCustomerDialog::on_pushButtonSave_clicked()
{
    QString name = ui->lineEditName->text();
    QString address = ui->lineEditAddress->text();
    QString email = ui->lineEditEmail->text();
    QString phone = ui->lineEditPhone->text();

    Customer customer {0, name, address, email, phone};
    CustomerValidator validator {customer};
    QString message;

    if (!validator.validate(message)) {
        QMessageBox::critical(this, "Input Error", "One or more errors have occurred:" + message);
        return;
    }

    if (customer.save()) {
        QMessageBox::information(this, "Success", "Customer has been saved");

        ui->lineEditName->clear();
        ui->lineEditAddress->clear();
        ui->lineEditEmail->clear();
        ui->lineEditPhone->clear();
    } else {
        QMessageBox::critical(this, "Error", "Customer not saved");
    }
}


void NewCustomerDialog::on_pushButtonClose_clicked()
{
    this->close();
}

