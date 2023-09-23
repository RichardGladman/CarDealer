#include "editcustomerdialog.h"
#include "ui_editcustomerdialog.h"

#include <QSqlQuery>
#include <QMessageBox>
#include "customervalidator.h"
#include "customer.h"

EditCustomerDialog::EditCustomerDialog(int id, QWidget *parent) : QDialog(parent), ui(new Ui::EditCustomerDialog)
{
    ui->setupUi(this);

    this->id = id;

    QSqlQuery query;
    query.prepare("SELECT * FROM customers WHERE id=?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        ui->lineEditName->setText(query.value(1).toString());
        ui->lineEditAddress->setText(query.value(2).toString());
        ui->lineEditEmail->setText(query.value(3).toString());
        ui->lineEditPhone->setText(query.value(4).toString());
    }
}

EditCustomerDialog::~EditCustomerDialog()
{
    delete ui;
}

void EditCustomerDialog::on_pushButtonSave_clicked()
{
    QString name = ui->lineEditName->text();
    QString address = ui->lineEditAddress->text();
    QString email = ui->lineEditEmail->text();
    QString phone = ui->lineEditPhone->text();

    Customer customer {id, name, address, email, phone};
    CustomerValidator validator {customer};

    QString message;

    if (!validator.validate(message)) {
        QMessageBox::critical(this, "Input Error", "One or more errors have occurred:" + message);
        return;
    }

    if (customer.save()) {
        QMessageBox::information(this, "Success", "Customer has been saved");
    } else {
        QMessageBox::critical(this, "Error", "Customer not saved");
    }
}


void EditCustomerDialog::on_pushButtonClose_clicked()
{
    this->close();
}

