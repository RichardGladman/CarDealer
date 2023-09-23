#include "newsellerdialog.h"
#include "ui_newsellerdialog.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

#include "seller.h"
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

    Seller seller {0, firstName, lastName, email, phone};
    SellerValidator validator {seller};

    QString message;

    if (!validator.validate(message)) {
        QMessageBox::critical(this, "Input Error", "One or more errors have occurred:" + message);
        return;
    }

    if (seller.save()) {
        QMessageBox::information(this, "Success", "Seller information saved successfully");

        ui->lineEditFirstName->clear();
        ui->lineEditLastName->clear();
        ui->lineEditEmail->clear();
        ui->lineEditPhone->clear();
    } else {
        QMessageBox::critical(this, "Error", "Seller information not saved");
    }
}

