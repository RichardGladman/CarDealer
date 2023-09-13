#include "vehiclesframe.h"
#include "ui_vehiclesframe.h"

#include <QSqlQueryModel>

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


void VehiclesFrame::on_pushButtonEdit_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedIndexes();

    EditVehicleDialog *editVehicleDialog = new EditVehicleDialog(ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt(), this);
    editVehicleDialog->exec();

    loadData();
}

