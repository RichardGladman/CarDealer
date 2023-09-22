#include "viewcustomerdialog.h"
#include "ui_viewcustomerdialog.h"

#include <QSqlQuery>
#include <QDebug>

ViewCustomerDialog::ViewCustomerDialog(int id, QWidget *parent) : QDialog(parent), ui(new Ui::ViewCustomerDialog)
{
    ui->setupUi(this);
    this->id = id;

    QSqlQuery query;
    query.prepare("SELECT * FROM customers WHERE id=?");
    query.addBindValue(id);

    if (query.exec()) {
        if (query.next()) {
            ui->labelName->setText(query.value(1).toString());
            ui->labelAddress->setText(query.value(2).toString());
            ui->labelEmail->setText(query.value(3).toString());
            ui->labelPhone->setText(query.value(4).toString());
        }
    }
}

ViewCustomerDialog::~ViewCustomerDialog()
{
    delete ui;
}

void ViewCustomerDialog::on_pushButtonClose_clicked()
{
    this->close();
}

