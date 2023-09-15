#include "editcustomerdialog.h"
#include "ui_editcustomerdialog.h"

#include <QSqlQuery>
#include <QMessageBox>

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

    if (name == "" || address == "" || email == "" || phone == "") {
        QMessageBox::critical(this, "Input Error", "One or more fields have been left blank");
        return;
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE customers SET name=?, address=?, email=?, phone=? WHERE id=?");
    updateQuery.addBindValue(name);
    updateQuery.addBindValue(address);
    updateQuery.addBindValue(email);
    updateQuery.addBindValue(phone);
    updateQuery.addBindValue(id);


    if (updateQuery.exec()) {
        QMessageBox::information(this, "Success", "Customer has been saved");

        ui->lineEditName->clear();
        ui->lineEditAddress->clear();
        ui->lineEditEmail->clear();
        ui->lineEditPhone->clear();
    } else {
        QMessageBox::critical(this, "Error", "Customer not saved");
    }
}


void EditCustomerDialog::on_pushButtonClose_clicked()
{
    this->close();
}

