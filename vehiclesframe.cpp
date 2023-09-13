#include "vehiclesframe.h"
#include "ui_vehiclesframe.h"

#include <QSqlQueryModel>

#include "newvehicledialog.h"

VehiclesFrame::VehiclesFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::VehiclesFrame)
{
    ui->setupUi(this);

    QSqlQueryModel *tableModel = new QSqlQueryModel;
    tableModel->setQuery("SELECT id, manufacturer, name, year_of_manufacture, vehicle_condition FROM vehicles");

    tableModel->setHeaderData(0, Qt::Horizontal, "Id");
    tableModel->setHeaderData(1, Qt::Horizontal, "Manufacturer");
    tableModel->setHeaderData(2, Qt::Horizontal, "Name");
    tableModel->setHeaderData(3, Qt::Horizontal, "Year");
    tableModel->setHeaderData(4, Qt::Horizontal, "Condition");

    ui->tableView->setModel(tableModel);
}

VehiclesFrame::~VehiclesFrame()
{
    delete ui;
}

void VehiclesFrame::on_pushButtonAdd_clicked()
{
    NewVehicleDialog *newVehicleDialog = new NewVehicleDialog;
    newVehicleDialog->setWindowTitle("Add New Vehicle");
    newVehicleDialog->exec();
}

