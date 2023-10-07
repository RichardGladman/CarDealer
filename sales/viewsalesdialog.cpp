#include "viewsalesdialog.h"
#include "ui_viewsalesdialog.h"

#include <QSqlQuery>
#include <QDebug>

#include "salesmodel.h"
#include "../customers/customer.h"
#include "../vehicles/vehicle.h"
#include "../sellers/seller.h"

#include "../settings/settings.h"

ViewSalesDialog::ViewSalesDialog(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewSalesDialog)
{
    extern Settings *settings;

    ui->setupUi(this);

    SalesModel salesModel = SalesModel::load(id);
    Customer customer = Customer::load(salesModel.getCustomerId());
    Vehicle vehicle = Vehicle::load(salesModel.getVehicleId());
    Seller seller = Seller::load(salesModel.getSellerId());

    ui->labelCustomerName->setText(customer.getName());
    ui->labelCustomerEmail->setText(customer.getEmail());
    ui->labelCustomerPhone->setText(customer.getPhone());
    ui->labelVehicleName->setText(vehicle.getName());
    ui->labelVehicleManafacturer->setText(vehicle.getManufacturer());
    ui->labelVehicleMiles->setText(QString::number(vehicle.getMiles(), 'f', 2));
    ui->labelVehicleCondition->setText(vehicle.getVehicleCondition());
    ui->labelVehiclePrice->setText(settings->getCurrency() + " " + QString::number(vehicle.getPrice(), 'f', 2));
    ui->labelNegotiatedPrice->setText(settings->getCurrency() + " " + QString::number(salesModel.getNegotiatedPrice(), 'f', 2));
    ui->labelSaleDate->setText(salesModel.getAddedDate());
    ui->labelSellerName->setText(seller.getFirstName() + " " + seller.getLastName());
    ui->labelSellerEmail->setText(seller.getEmail());
    ui->labelSellerPhone->setText(seller.getPhone());
}

ViewSalesDialog::~ViewSalesDialog()
{
    delete ui;
}

void ViewSalesDialog::on_pushButtonClose_clicked()
{
    this->close();
}

