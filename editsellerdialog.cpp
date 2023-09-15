#include "editsellerdialog.h"
#include "ui_editsellerdialog.h"

#include <QSqlQuery>
#include <QMessageBox>

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

}


void EditSellerDialog::on_pushButtonClose_clicked()
{

}

