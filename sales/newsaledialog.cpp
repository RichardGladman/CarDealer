#include "newsaledialog.h"
#include "ui_newsaledialog.h"

#include <QSqlQuery>
#include <QMessageBox>

#include "../vehicles/vehicle.h"
#include "../customers/customer.h"
#include "../sellers/seller.h"
#include "salesmodel.h"
#include "../settings/settings.h"

NewSaleDialog::NewSaleDialog(QWidget *parent) : QDialog(parent), ui(new Ui::NewSaleDialog)
{
    extern Settings *settings;

    ui->setupUi(this);

    QVector<Vehicle> vehicles = Vehicle::list();
    for (Vehicle vehicle: vehicles) {
        QString information = vehicle.getName() + " (" + vehicle.getYearOfManufacture() + " " + vehicle.getDrive() + ") " + settings->getCurrency() + QString::number(vehicle.getPrice(), 'f', 2);
        ui->comboBoxVehicle->addItem(information, vehicle.getId());
    }

    QVector<Customer> customers = Customer::list();
    for (Customer customer: customers) {
        ui->comboBoxCustomer->addItem(customer.getName(), customer.getId());
    }

    QVector<Seller> sellers = Seller::list();
    for (Seller seller: sellers) {
        ui->comboBoxSeller->addItem(seller.getFirstName() + " " + seller.getLastName(), seller.getId());
    }
}

NewSaleDialog::~NewSaleDialog()
{
    delete ui;
}

void NewSaleDialog::on_pushButtonSubmit_clicked()
{
    int vehicleId = ui->comboBoxVehicle->currentData().toInt();
    QString vehicleDescription = ui->comboBoxVehicle->currentText();

    int customerId = ui->comboBoxCustomer->currentData().toInt();
    QString customerName = ui->comboBoxCustomer->currentText();

    int sellerId = ui->comboBoxSeller->currentData().toInt();
    QString sellerName = ui->comboBoxSeller->currentText();

    QString registration = ui->lineEditRegistration->text();
    double negotiatedPrice = ui->lineEditNegotiatedPrice->text().toDouble();

    if (registration == "" || negotiatedPrice == 0.0) {
        QMessageBox::critical(this, "Input Error", "One or more fields has been left blank");
        return;
    }

    QString message = "Selling vehicle " + vehicleDescription;
    message += "\nwith registration " + registration;
    message += "\nto customer " + customerName;
    message += "\nby seller " + sellerName;
    message += "\nnegotiated price " + QString::number(negotiatedPrice, 'f', 2);

    QMessageBox *msgbox = new QMessageBox(this);
    msgbox->setWindowTitle("Question");
    msgbox->setIcon(QMessageBox::Question);
    msgbox->setWindowIcon(QIcon(":/images/deal.png"));
    msgbox->setText("Are you sure?\n\n" + message + "\n\nConfirm Sale?");

    QPushButton *buttonYes, *buttonNo;

    buttonYes = msgbox->addButton(QMessageBox::Yes);
    msgbox->addButton(QMessageBox::No);

    msgbox->exec();

    if (msgbox->clickedButton() == buttonYes) {
        SalesModel sale = SalesModel {0, customerId, vehicleId, sellerId, registration, "", negotiatedPrice};

        if (sale.save()) {
            QMessageBox::information(this, "Sale completed", "Sale completed successfully");
        } else {
            QMessageBox::critical(this, "Error", "Sale not completed");
        }
    }
}


void NewSaleDialog::on_pushButtonClose_clicked()
{
    this->close();
}

