#include "viewvehicledialog.h"
#include "ui_viewvehicledialog.h"

#include <QSqlQuery>

#include "vehicle.h"
#include "../settings/settings.h"

ViewVehicleDialog::ViewVehicleDialog(int vehicleId, QWidget *parent) : QDialog(parent), ui(new Ui::ViewVehicleDialog)
{
    extern Settings *settings;

    ui->setupUi(this);

    Vehicle vehicle = Vehicle::load(vehicleId);

    ui->labelManufacturer->setText(vehicle.getManufacturer());
    ui->labelName->setText(vehicle.getName());
    ui->labelYear->setText(vehicle.getYearOfManufacture());
    ui->labelMiles->setText(QString::number(vehicle.getMiles(), 'f', 2));
    ui->labelCondition->setText(vehicle.getVehicleCondition());
    ui->labelDrive->setText(vehicle.getDrive());
    ui->labelQuantity->setText(QString::number(vehicle.getQuantity()));
    ui->labelPrice->setText(settings->getCurrency() + " " + QString::number(vehicle.getPrice(), 'f', 2));

    QPixmap pixmap = QPixmap();
    pixmap.loadFromData(vehicle.getPictureBytes());

        ui->labelPicture->setPixmap(pixmap.scaledToHeight(300).scaledToWidth(300));
}

ViewVehicleDialog::~ViewVehicleDialog()
{
    delete ui;
}

void ViewVehicleDialog::on_pushButtonClose_clicked()
{
    this->close();
}

