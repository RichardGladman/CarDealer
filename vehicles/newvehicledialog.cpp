#include "newvehicledialog.h"
#include "ui_newvehicledialog.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "vehiclevalidator.h"
#include "vehicle.h"

NewVehicleDialog::NewVehicleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewVehicleDialog)
{
    ui->setupUi(this);
}

NewVehicleDialog::~NewVehicleDialog()
{
    delete ui;
}

void NewVehicleDialog::on_pushButtonSave_clicked()
{
    QString vehicleName = ui->lineEditVehicleName->text();
    QString manufacturer = ui->lineEditManufacturer->text();
    QString year = ui->lineEditYear->text();
    double miles = ui->lineEditMiles->text().toDouble();
    QString condition = ui->comboBoxCondition->currentText();
    QString drive = ui->comboBoxDrive->currentText();
    int quantity = ui->lineEditQuantity->text().toInt();
    double price = ui->lineEditPrice->text().toDouble();
    QString currency = ui->comboBoxCurrency->currentText();
    QString picture = ui->lineEditImage->text();

    Vehicle vehicle {0, vehicleName, manufacturer, year, miles, condition, drive, quantity, price, currency, picture};
    VehicleValidator validator {vehicleName, manufacturer, year, miles, quantity, price};
    QString message;

    if (!validator.validate(message)) {
        QMessageBox::critical(this, "Input Error", "One or more errors have occurred:" + message);
        return;
    }

    if (vehicle.save()) {
        QMessageBox::information(this, "Success", "Vehicle added successfully");

        ui->lineEditVehicleName->clear();
        ui->lineEditManufacturer->clear();
        ui->lineEditYear->clear();
        ui->lineEditMiles->clear();
        ui->lineEditQuantity->clear();
        ui->lineEditPrice->clear();
        ui->lineEditImage->clear();
        ui->comboBoxCondition->setCurrentIndex(0);
        ui->comboBoxDrive->setCurrentIndex(0);
        ui->comboBoxCurrency->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Error", "Vehicle not saved\n\n");
    }
}


void NewVehicleDialog::on_pushButtonClose_clicked()
{
    this->close();
}


void NewVehicleDialog::on_pushButtonChoose_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Choose Vehicle Picture", QDir::currentPath(), "Picture Files (*.png *.jpg)");
    ui->lineEditImage->setText(path);
}

