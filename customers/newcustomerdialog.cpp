#include "newcustomerdialog.h"
#include "ui_newcustomerdialog.h"

#include <QSqlQuery>
#include <QMessageBox>

#include "customervalidator.h"

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

    CustomerValidator validator {name, address, email, phone};
    QString message;

    if (!validator.validate(message)) {
        QMessageBox::critical(this, "Input Error", "One or more errors have occurred:" + message);
        return;
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO customers(name, address, email, phone) VALUES(?, ?, ?, ?)");
    insertQuery.addBindValue(name);
    insertQuery.addBindValue(address);
    insertQuery.addBindValue(email);
    insertQuery.addBindValue(phone);

    if (insertQuery.exec()) {
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

