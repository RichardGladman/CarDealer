#include "newvehicleframe.h"
#include "ui_newvehicleframe.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

NewVehicleFrame::NewVehicleFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::NewVehicleFrame)
{
    ui->setupUi(this);
}

NewVehicleFrame::~NewVehicleFrame()
{
    delete ui;
}

void NewVehicleFrame::on_pushButtonChoose_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Choose Vehicle Picture", QDir::currentPath(), "Picture Files (*.png *.jpg)");
    ui->lineEditImage->setText(path);
}


void NewVehicleFrame::on_pushButtonSave_clicked()
{
    QByteArray pictureBytes;

    if (ui->lineEditImage->text() != "") {
        QFile file(ui->lineEditImage->text());

        if (file.open(QIODevice::ReadOnly)) {
            pictureBytes = file.readAll();
            file.close();
        }
    }

    QString vehicleName = ui->lineEditVehicleName->text();
    QString manufacturer = ui->lineEditManufacturer->text();
    QString year = ui->lineEditYear->text();
    double miles = ui->lineEditMiles->text().toDouble();
    QString condition = ui->comboBoxCondition->currentText();
    QString drive = ui->comboBoxDrive->currentText();
    int quantity = ui->lineEditQuantity->text().toInt();
    double price = ui->lineEditPrice->text().toDouble();
    QString currency = ui->comboBoxCurrency->currentText();

    if (vehicleName == "" || manufacturer == "" || year == "" || miles == 0.0 || quantity == 0 || price == 0.0) {
        QMessageBox::critical(this, "Input error", "One or more fields has been left blank");
        return;
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO vehicles(name, manufacturer, year_of_manufacture, miles, vehicle_condition, drive, quantity, price, currency, picture) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    insertQuery.addBindValue(vehicleName);
    insertQuery.addBindValue(manufacturer);
    insertQuery.addBindValue(year);
    insertQuery.addBindValue(miles);
    insertQuery.addBindValue(condition);
    insertQuery.addBindValue(drive);
    insertQuery.addBindValue(quantity);
    insertQuery.addBindValue(price);
    insertQuery.addBindValue(currency);
    insertQuery.addBindValue(pictureBytes);

    if (insertQuery.exec()) {
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
        QMessageBox::critical(this, "Error", "Vehicle not saved\n\n" + insertQuery.lastError().text());

        qDebug() << insertQuery.lastQuery() << "\n";
        qDebug() << insertQuery.executedQuery();
    }
}

