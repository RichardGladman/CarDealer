#include "viewvehicledialog.h"
#include "ui_viewvehicledialog.h"

#include <QSqlQuery>

ViewVehicleDialog::ViewVehicleDialog(int vehicleId, QWidget *parent) : QDialog(parent), ui(new Ui::ViewVehicleDialog)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("SELECT * FROM vehicles WHERE id=?");
    query.addBindValue(vehicleId);

    if (query.exec()) {
        if (query.next()) {
            ui->labelManufacturer->setText(query.value(1).toString());
            ui->labelName->setText(query.value(10).toString());
            ui->labelYear->setText(query.value(2).toString());
            ui->labelMiles->setText(query.value(3).toString());
            ui->labelCondition->setText(query.value(4).toString());
            ui->labelDrive->setText(query.value(5).toString());
            ui->labelQuantity->setText(query.value(6).toString());
            ui->labelPrice->setText(query.value(8).toString() + " " + QString::number(query.value(7).toDouble(), 'f', 2));

            QByteArray pictureBytes = query.value(9).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(pictureBytes);

            ui->labelPicture->setPixmap(pixmap.scaledToHeight(300).scaledToWidth(300));
        }
    }
}

ViewVehicleDialog::~ViewVehicleDialog()
{
    delete ui;
}

void ViewVehicleDialog::on_pushButtonClose_clicked()
{
    this->close();
}

