#include "vehiclesframe.h"
#include "ui_vehiclesframe.h"

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>

#include "newvehicledialog.h"
#include "editvehicledialog.h"

VehiclesFrame::VehiclesFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::VehiclesFrame)
{
    ui->setupUi(this);
    loadData();
}

VehiclesFrame::~VehiclesFrame()
{
    delete ui;
}

void VehiclesFrame::on_pushButtonAdd_clicked()
{
    NewVehicleDialog *newVehicleDialog = new NewVehicleDialog(this);
    newVehicleDialog->setWindowTitle("Add New Vehicle");
    newVehicleDialog->exec();

    loadData();
}


void VehiclesFrame::on_pushButtonEdit_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedIndexes();

    EditVehicleDialog *editVehicleDialog = new EditVehicleDialog(ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt(), this);
    editVehicleDialog->exec();

    loadData();
}


void VehiclesFrame::on_pushButtonDelete_clicked()
{
    QMessageBox *msgbox = new QMessageBox(this);
    msgbox->setWindowTitle("Question");
    msgbox->setIcon(QMessageBox::Question);
    msgbox->setWindowIcon(QIcon(":/images/bentley.png"));
    msgbox->setText("Are you sure? Do you really want to delete this vehicle?");

    QPushButton *buttonYes, *buttonNo;

    buttonYes = msgbox->addButton(QMessageBox::Yes);
    msgbox->addButton(QMessageBox::No);

    msgbox->exec();

    if (msgbox->clickedButton() == buttonYes) {
        QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedIndexes();

        QSqlQuery deleteQuery;
        deleteQuery.prepare("DELETE FROM vehicles WHERE id=?");
        deleteQuery.addBindValue(ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt());

        if (deleteQuery.exec()) {
            QMessageBox::information(this, "Success", "Vehicle has been deleted");

            loadData();
        } else {
            QMessageBox::critical(this, "Error", "Vehicle has not been deleted");
        }
    }
}

void VehiclesFrame::loadData()
{
    QSqlQueryModel *tableModel = new QSqlQueryModel;
    tableModel->setQuery("SELECT id, manufacturer, name, year_of_manufacture, vehicle_condition FROM vehicles");

    tableModel->setHeaderData(0, Qt::Horizontal, "Id");
    tableModel->setHeaderData(1, Qt::Horizontal, "Manufacturer");
    tableModel->setHeaderData(2, Qt::Horizontal, "Name");
    tableModel->setHeaderData(3, Qt::Horizontal, "Year");
    tableModel->setHeaderData(4, Qt::Horizontal, "Condition");

    ui->tableView->setModel(tableModel);
}

