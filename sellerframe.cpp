#include "sellerframe.h"
#include "ui_sellerframe.h"

#include <QSqlQuery>
#include <QSqlQueryModel>

#include "newsellerdialog.h"
#include "editsellerdialog.h"

SellerFrame::SellerFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SellerFrame)
{
    ui->setupUi(this);

    loadData();
}

SellerFrame::~SellerFrame()
{
    delete ui;
}

void SellerFrame::on_pushButtonSearch_clicked()
{
}


void SellerFrame::on_pushButtonAdd_clicked()
{
    NewSellerDialog *newSellerDialog = new NewSellerDialog(this);
    newSellerDialog->exec();

    loadData();
}


void SellerFrame::on_pushButtonEdit_clicked()
{
    EditSellerDialog *editSellerDialog = new EditSellerDialog(this);
    editSellerDialog->exec();

    loadData();
}


void SellerFrame::on_pushButtonDelete_clicked()
{

}

void SellerFrame::loadData()
{
    QString target = "%" + searchFor + "%";
    QString sql = "SELECT * FROM sellers";

    if (searchFor != "") {
        sql += " WHERE first_name LIKE ? OR last_name LIKE ? or email LIKE ? or phone LIKE ?";
    }

    QSqlQuery query;
    query.prepare(sql);

    if (searchFor != "") {
        query.addBindValue(target);
        query.addBindValue(target);
        query.addBindValue(target);
        query.addBindValue(target);
    }

    query.exec();

    QSqlQueryModel *tableModel = new QSqlQueryModel(this);
    tableModel->setQuery(std::move(query));

    tableModel->setHeaderData(0, Qt::Horizontal, "Id");
    tableModel->setHeaderData(1, Qt::Horizontal, "First Name");
    tableModel->setHeaderData(2, Qt::Horizontal, "Last Name");
    tableModel->setHeaderData(3, Qt::Horizontal, "Email");
    tableModel->setHeaderData(4, Qt::Horizontal, "Phone");

    ui->tableView->setModel(tableModel);
}
