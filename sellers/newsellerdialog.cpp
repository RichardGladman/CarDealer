#include "newsellerdialog.h"
#include "ui_newsellerdialog.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

#include "sellervalidator.h"

NewSellerDialog::NewSellerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSellerDialog)
{
    ui->setupUi(this);
}

NewSellerDialog::~NewSellerDialog()
{
    delete ui;
}

void NewSellerDialog::on_pushButtonClose_clicked()
{
    this->close();
}


void NewSellerDialog::on_pushButtonSave_clicked()
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

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO sellers(first_name, last_name, email, phone) VALUES(?, ?, ?, ?)");
    insertQuery.addBindValue(firstName);
    insertQuery.addBindValue(lastName);
    insertQuery.addBindValue(email);
    insertQuery.addBindValue(phone);

    if (insertQuery.exec()) {
        QMessageBox::information(this, "Success", "Seller information saved successfully");

        ui->lineEditFirstName->clear();
        ui->lineEditLastName->clear();
        ui->lineEditEmail->clear();
        ui->lineEditPhone->clear();
    } else {
        QMessageBox::critical(this, "Error", "Seller information not saved");
    }
}

