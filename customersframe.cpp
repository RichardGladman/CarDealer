#include "customersframe.h"
#include "ui_customersframe.h"

#include <QSqlQuery>
#include <QSqlQueryModel>

#include "newcustomerdialog.h"
#include "viewcustomerdialog.h"

CustomersFrame::CustomersFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CustomersFrame)
{
    ui->setupUi(this);

    loadData();
}

CustomersFrame::~CustomersFrame()
{
    delete ui;
}

void CustomersFrame::on_pushButtonAdd_clicked()
{
    NewCustomerDialog *newCustomerDialog = new NewCustomerDialog(this);
    newCustomerDialog->exec();

    loadData();
}

void CustomersFrame::on_pushButtonSearch_clicked()
{
    searchFor = ui->lineEditSearchFor->text();
    loadData();
}


void CustomersFrame::on_pushButtonView_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedRows.empty()) {
        return;
    }

    ViewCustomerDialog *viewCustomerDialog = new ViewCustomerDialog(ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt(), this);
    viewCustomerDialog->exec();
}

void CustomersFrame::loadData()
{
    QString target = "%" + searchFor + "%";
    QString sql = "SELECT id, name, email, phone FROM customers";

    if (searchFor != "") {
        sql += " WHERE name LIKE ? OR email LIKE ? OR phone LIKE ?";
    }

    QSqlQuery query;
    query.prepare(sql);

    if (searchFor != "") {
        query.addBindValue(target);
        query.addBindValue(target);
        query.addBindValue(target);
    }

    query.exec();

    QSqlQueryModel *tableModel = new QSqlQueryModel(this);
    tableModel->setQuery(std::move(query));

    tableModel->setHeaderData(0, Qt::Horizontal, "Id");
    tableModel->setHeaderData(1, Qt::Horizontal, "Name");
    tableModel->setHeaderData(2, Qt::Horizontal, "E-Mail");
    tableModel->setHeaderData(3, Qt::Horizontal, "Phone");

    ui->tableView->setModel(tableModel);
}


