#include "partexchangeframe.h"
#include "ui_partexchangeframe.h"

#include <QSqlQuery>
#include <QSqlQueryModel>

#include "partexchange.h"
#include "../delegates/currencydelegate.h"


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

}


void PartExchangeFrame::on_pushButtonAuction_clicked()
{

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

    CurrencyDelegate *priceDelegate = new CurrencyDelegate(this);
    priceDelegate->setColumn(4);

    ui->tableView->setModel(tableModel);
    ui->tableView->setItemDelegateForColumn(4, priceDelegate);

}

