#include "salesframe.h"
#include "ui_salesframe.h"

#include <QSqlQuery>
#include <QSqlQueryModel>

#include "newsaledialog.h"

SalesFrame::SalesFrame( QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SalesFrame)
{
    ui->setupUi(this);

    loadData();
}

SalesFrame::~SalesFrame()
{
    delete ui;
}

void SalesFrame::on_pushButtonAdd_clicked()
{
    NewSaleDialog *newSaleDialog = new NewSaleDialog(this);
    newSaleDialog->exec();

    loadData();
}


void SalesFrame::on_pushButtonView_clicked()
{

}

void SalesFrame::loadData()
{
    QString target = "%" + searchFor + "%";

    QString sql = "SELECT s.id, c.name, v.name, v.manufacturer, v.year_of_manufacture, v.vehicle_condition ";
    sql += "FROM sales s ";
    sql += "INNER JOIN vehicles v on s.vehicle_id = v.id ";
    sql += "INNER JOIN customers c on s.customer_id  = c.id ";

    if (searchFor != "") {
        sql += "WHERE c.name LIKE ?";
    }

    sql += "ORDER BY c.name, v.name ";

    QSqlQuery query;
    query.prepare(sql);

    if (searchFor != "") {
        query.addBindValue(target);
    }

    if (query.exec()) {
        QSqlQueryModel *tableModel = new QSqlQueryModel(this);
        tableModel->setQuery(std::move(query));

        tableModel->setHeaderData(0, Qt::Horizontal, "Sales Id");
        tableModel->setHeaderData(1, Qt::Horizontal, "Customer Name");
        tableModel->setHeaderData(2, Qt::Horizontal, "Vehicle Name");
        tableModel->setHeaderData(3, Qt::Horizontal, "Manufacturer");
        tableModel->setHeaderData(4, Qt::Horizontal, "Year");
        tableModel->setHeaderData(5, Qt::Horizontal, "Condition");

        ui->tableView->setModel(tableModel);
    }

}
