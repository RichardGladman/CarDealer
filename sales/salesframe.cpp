    #include "salesframe.h"
#include "ui_salesframe.h"

#include <QSqlQuery>
#include <QSqlQueryModel>

#include "newsaledialog.h"
#include "viewsalesdialog.h"
#include "salesmodel.h"

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
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedRows.empty()) {
        return;
    }

    ViewSalesDialog *viewSalesDialog = new ViewSalesDialog(ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt(), this);
    viewSalesDialog->exec();
}

void SalesFrame::on_pushButtonSearch_clicked()
{
    searchFor = ui->lineEditSearchFor->text();
    loadData();
}


void SalesFrame::loadData()
{
    QSqlQuery query = SalesModel::list(searchFor);
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
