#include "editsellerdialog.h"
#include "ui_editsellerdialog.h"

#include <QSqlQuery>
#include <QMessageBox>

#include "sellervalidator.h"

EditSellerDialog::EditSellerDialog(int sellerId, QWidget *parent) : QDialog(parent), ui(new Ui::EditSellerDialog)
{
    ui->setupUi(this);

    this->sellerId = sellerId;

    QSqlQuery query;
    query.prepare("SELECT * FROM sellers WHERE id=?");
    query.addBindValue(sellerId);

    if (query.exec()) {
        if (query.next()) {
            ui->lineEditFirstName->setText(query.value(1).toString());
            ui->lineEditLastName->setText(query.value(2).toString());
            ui->lineEditEmail->setText(query.value(3).toString());
            ui->lineEditPhone->setText(query.value(4).toString());
        }
    }
}

EditSellerDialog::~EditSellerDialog()
{
    delete ui;
}

void EditSellerDialog::on_pushButtonSave_clicked()
{
    QString firstName = ui->lineEditFirstName->text();
    QString lastName = ui->lineEditLastName->text();
    QString email = ui->lineEditEmail->text();
    QString phone = ui->lineEditPhone->text();

    SellerValidator validator {firstName, lastName, email, phone};
    QString message;

    if (!validator.validate(message)) {
        QMessageBox::critical(this, "Input Error", "One or more errors have occurred:" + message);
        return;
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE sellers SET first_name=?, last_name=?, email=?, phone=? WHERE id=?");
    updateQuery.addBindValue(firstName);
    updateQuery.addBindValue(lastName);
    updateQuery.addBindValue(email);
    updateQuery.addBindValue(phone);
    updateQuery.addBindValue(sellerId);

    if (updateQuery.exec()) {
        QMessageBox::information(this, "Success", "Seller saved successfully");
        this->close();
    } else {
        QMessageBox::critical(this, "Error", "Seller has not been saved");
    }
}


void EditSellerDialog::on_pushButtonClose_clicked()
{
    this->close();
}

