#include "customersframe.h"
#include "ui_customersframe.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

#include "newcustomerdialog.h"
#include "editcustomerdialog.h"
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


void CustomersFrame::on_pushButtonEdit_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedRows.empty()) {
        return;
    }

    EditCustomerDialog *editCustomerDialog = new EditCustomerDialog(ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt(), this);
    editCustomerDialog->exec();

    loadData();
}

void CustomersFrame::on_pushButtonDelete_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedRows.empty()) {
        return;
    }


    QMessageBox *msgbox = new QMessageBox(this);
    msgbox->setWindowTitle("Question");
    msgbox->setIcon(QMessageBox::Question);
    msgbox->setWindowIcon(QIcon(":/images/woman.png"));
    msgbox->setText("Are you sure? Do you really want to delete this customer?");

    QPushButton *buttonYes, *buttonNo;

    buttonYes = msgbox->addButton(QMessageBox::Yes);
    msgbox->addButton(QMessageBox::No);

    msgbox->exec();

    if (msgbox->clickedButton() == buttonYes) {
        QSqlQuery deleteQuery;
        deleteQuery.prepare("DELETE FROM customers WHERE id=?");
        deleteQuery.addBindValue(ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt());

        if (deleteQuery.exec()) {
            QMessageBox::information(this, "Success", "Customer has been deleted");
            loadData();
        } else {
            QMessageBox::critical(this, "Error", "Customer has not been deleted");
        }
    }
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

