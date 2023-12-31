#include "partexchangeframe.h"
#include "ui_partexchangeframe.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

#include "partexchange.h"
#include "../delegates/currencydelegate.h"
#include "../delegates//booleandelegate.h"
#include "../vehicles/editvehicledialog.h"


PartExchangeFrame::PartExchangeFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PartExchangeFrame)
{
    ui->setupUi(this);

    loadData();
}

PartExchangeFrame::~PartExchangeFrame()
{
    delete ui;
}

void PartExchangeFrame::on_pushButtonSearch_clicked()
{
    searchFor = ui->lineEditSearchFor->text();
    loadData();
}


void PartExchangeFrame::on_pushButtonView_clicked()
{

}


void PartExchangeFrame::on_pushButtonStock_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedRows.empty()) {
        return;
    }

    PartExchange pe = PartExchange(
                ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt(),
                ui->tableView->model()->index(selectedRows.at(0).row(), 1).data().toString(),
                ui->tableView->model()->index(selectedRows.at(0).row(), 2).data().toString(),
                "",
                0.0,
                0,
                0
    );
    int vehicle_id {};
    if (pe.addToStock(ui->tableView->model()->index(selectedRows.at(0).row(), 5).data().toInt(), vehicle_id)) {
        EditVehicleDialog *evd = new EditVehicleDialog(vehicle_id, this);
        evd->exec();
        loadData();
        on_tableView_clicked(ui->tableView->model()->index(selectedRows.at(0).row(), 0));
    } else {
        QMessageBox::critical(this, "Error", "Vehicle not updated");
    }
}


void PartExchangeFrame::on_pushButtonAuction_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedRows.empty()) {
        return;
    }

    PartExchange pe = PartExchange(ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt());
    if (pe.auction(ui->tableView->model()->index(selectedRows.at(0).row(), 5).data().toInt())) {
        loadData();
        on_tableView_clicked(ui->tableView->model()->index(selectedRows.at(0).row(), 0));
    } else {
        QMessageBox::critical(this, "Error", "Vehicle not updated");
    }
}

void PartExchangeFrame::loadData()
{
    QSqlQuery query = PartExchange::list(searchFor);
    QSqlQueryModel *tableModel = new QSqlQueryModel(this);
    tableModel->setQuery(std::move(query));

    tableModel->setHeaderData(0, Qt::Horizontal, "Id");
    tableModel->setHeaderData(1, Qt::Horizontal, "Make");
    tableModel->setHeaderData(2, Qt::Horizontal, "Model");
    tableModel->setHeaderData(3, Qt::Horizontal, "Registration");
    tableModel->setHeaderData(4, Qt::Horizontal, "Price");
    tableModel->setHeaderData(5, Qt::Horizontal, "Autioned");
    tableModel->setHeaderData(6, Qt::Horizontal, "Stocked");

    CurrencyDelegate *priceDelegate = new CurrencyDelegate(this);
    priceDelegate->setColumn(4);

    ui->tableView->setModel(tableModel);
    ui->tableView->setItemDelegateForColumn(4, priceDelegate);
    ui->tableView->setItemDelegateForColumn(5, new BooleanDelegate(5, this));
    ui->tableView->setItemDelegateForColumn(6, new BooleanDelegate(6, this));


}


void PartExchangeFrame::on_tableView_clicked(const QModelIndex &index)
{
    if (index.siblingAtColumn(5).data().toInt() == 1) {
        ui->pushButtonAuction->setText("Pull From Auction");
        ui->pushButtonStock->setDisabled(true);
    } else {
        ui->pushButtonAuction->setText("Send To Auction");
        ui->pushButtonStock->setDisabled(false);
    }

    if (index.siblingAtColumn(6).data().toInt() == 1) {
        ui->pushButtonStock->setDisabled(true);
        ui->pushButtonAuction->setDisabled(true);
    } else {
        ui->pushButtonStock->setDisabled(false);
        ui->pushButtonAuction->setDisabled(false);
    }
}

