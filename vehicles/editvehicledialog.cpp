#include "editvehicledialog.h"
#include "ui_editvehicledialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

#include "vehiclevalidator.h"
#include "vehicle.h"

EditVehicleDialog::EditVehicleDialog(int vehicleId, QWidget *parent) : QDialog(parent), ui(new Ui::EditVehicleDialog)
{
    ui->setupUi(this);

    this->vehicleId = vehicleId;

    QSqlQuery query;
    query.prepare("SELECT * FROM vehicles WHERE id=?");
    query.addBindValue(vehicleId);

    if (query.exec()) {
        if (query.next()) {
            ui->lineEditVehicleName->setText(query.value(9).toString());
            ui->lineEditManufacturer->setText(query.value(1).toString());
            ui->lineEditYear->setText(query.value(2).toString());
            ui->lineEditMiles->setText(query.value(3).toString());
            ui->comboBoxCondition->setCurrentText(query.value(4).toString());
            ui->comboBoxDrive->setCurrentText(query.value(5).toString());
            ui->lineEditQuantity->setText(query.value(6).toString());
            ui->lineEditPrice->setText(query.value(7).toString());
        }
    }
}

EditVehicleDialog::~EditVehicleDialog()
{
    delete ui;
}

void EditVehicleDialog::on_pushButtonSave_clicked()
{
    QString vehicleName = ui->lineEditVehicleName->text();
    QString manufacturer = ui->lineEditManufacturer->text();
    QString year = ui->lineEditYear->text();
    double miles = ui->lineEditMiles->text().toDouble();
    QString condition = ui->comboBoxCondition->currentText();
    QString drive = ui->comboBoxDrive->currentText();
    int quantity = ui->lineEditQuantity->text().toInt();
    double price = ui->lineEditPrice->text().toDouble();
    QString picture = ui->lineEditImage->text();

    Vehicle vehicle {vehicleId, vehicleName, manufacturer, year, miles, condition, drive, quantity, price, picture};
    VehicleValidator validator {vehicle};
    QString message;

    if (!validator.validate(message)) {
        QMessageBox::critical(this, "Input Error", "One or more errors have occurred:" + message);
        return;
    }

    if (vehicle.save()) {
        QMessageBox::information(this, "Success", "Vehicle saved successfully");
    } else {
        QMessageBox::critical(this, "Error", "Vehicle not saved\n\n");
    }
}


void EditVehicleDialog::on_pushButtonClose_clicked()
{
    this->close();
}


void EditVehicleDialog::on_pushButtonChoose_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Choose Vehicle Picture", QDir::currentPath(), "Picture Files (*.png *.jpg)");
    ui->lineEditImage->setText(path);
}

