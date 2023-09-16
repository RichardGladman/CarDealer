#include "newsaledialog.h"
#include "ui_newsaledialog.h"

#include <QSqlQuery>
#include <QMessageBox>

NewSaleDialog::NewSaleDialog(QWidget *parent) : QDialog(parent), ui(new Ui::NewSaleDialog)
{
    ui->setupUi(this);

    QSqlQuery vehicleQuery;
    vehicleQuery.prepare("SELECT id, name, year_of_manufacture, drive, price, currency FROM vehicles WHERE quantity > 0 ORDER BY name");
    if (vehicleQuery.exec()) {
        while (vehicleQuery.next()) {
            QString information = vehicleQuery.value(1).toString() + " (" + vehicleQuery.value(2).toString() + " " + vehicleQuery.value(3).toString() + ") ";
            information += vehicleQuery.value(5).toString() + vehicleQuery.value(4).toString();
            ui->comboBoxVehicle->addItem(information, vehicleQuery.value(0).toInt());
        }
    }

    QSqlQuery customerQuery;
    customerQuery.prepare("SELECT id, name FROM customers ORDER BY name");
    if (customerQuery.exec()) {
        while (customerQuery.next()) {
            ui->comboBoxCustomer->addItem(customerQuery.value(1).toString(), customerQuery.value(0).toInt());
        }
    }

    QSqlQuery sellerQuery;
    sellerQuery.prepare("SELECT id, first_name, last_name FROM sellers ORDER BY last_name, first_name");
    if (sellerQuery.exec()) {
        while (sellerQuery.next()) {
            QString fullName = sellerQuery.value(1).toString() + " " + sellerQuery.value(2).toString();
            ui->comboBoxSeller->addItem(fullName, sellerQuery.value(0).toInt());
        }
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

    QString message = "Selling vehicle " + vehicleDescription;
    message += "\nwith registration " + registration;
    message += "\nto customer " + customerName;
    message += "\nby seller " + sellerName;


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
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO sales(vehicle_id, customer_id, seller_id, registration) VALUES(?, ?, ?, ?)");
        insertQuery.addBindValue(vehicleId);
        insertQuery.addBindValue(customerId);
        insertQuery.addBindValue(sellerId);
        insertQuery.addBindValue(registration);

        if (insertQuery.exec()) {
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

