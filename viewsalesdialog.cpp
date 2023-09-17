#include "viewsalesdialog.h"
#include "ui_viewsalesdialog.h"

#include <QSqlQuery>
#include <QDebug>

ViewSalesDialog::ViewSalesDialog(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewSalesDialog)
{
    ui->setupUi(this);

    QString sql = "SELECT c.name, c.email, c.phone, ";
    sql += "v.name, v.manufacturer, v.miles, v.vehicle_condition, v.price, v.currency, s.added_date, ";
    sql += "p.first_name, p.last_name, p.email, p.phone ";
    sql += "FROM sales s ";
    sql += "INNER JOIN vehicles v ON s.vehicle_id = v.id ";
    sql += "INNER JOIN customers c ON s.customer_id  = c.id ";
    sql += "INNER JOIN sellers p ON s.seller_id = p.id ";
    sql += "WHERE s.id = ?";

    QSqlQuery query;
    query.prepare(sql);
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        ui->labelCustomerName->setText(query.value(0).toString());
        ui->labelCustomerEmail->setText(query.value(1).toString());
        ui->labelCustomerPhone->setText(query.value(2).toString());
        ui->labelVehicleName->setText(query.value(3).toString());
        ui->labelVehicleManafacturer->setText(query.value(4).toString());
        ui->labelVehicleMiles->setText(query.value(5).toString());
        ui->labelVehicleCondition->setText(query.value(6).toString());
        ui->labelVehiclePrice->setText(query.value(8).toString() + " " + query.value(7).toString());
        ui->labelSaleDate->setText(query.value(9).toString());
        ui->labelSellerName->setText(query.value(10).toString() + " " + query.value(11).toString());
        ui->labelSellerEmail->setText(query.value(12).toString());
        ui->labelSellerPhone->setText(query.value(13).toString());
    }
}

ViewSalesDialog::~ViewSalesDialog()
{
    delete ui;
}

void ViewSalesDialog::on_pushButtonClose_clicked()
{
    this->close();
}

