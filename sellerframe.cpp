#include "sellerframe.h"
#include "ui_sellerframe.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

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
    searchFor = ui->lineEditSearchFor->text();
    loadData();
}


void SellerFrame::on_pushButtonAdd_clicked()
{
    NewSellerDialog *newSellerDialog = new NewSellerDialog(this);
    newSellerDialog->exec();

    loadData();
}


void SellerFrame::on_pushButtonEdit_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedRows.empty()) {
        return;
    }

    EditSellerDialog *editSellerDialog = new EditSellerDialog(ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt(), this);
    editSellerDialog->exec();

    loadData();
}


void SellerFrame::on_pushButtonDelete_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedRows.empty()) {
        return;
    }


    QMessageBox *msgbox = new QMessageBox(this);
    msgbox->setWindowTitle("Question");
    msgbox->setIcon(QMessageBox::Question);
    msgbox->setWindowIcon(QIcon(":/images/team-member.png"));
    msgbox->setText("Are you sure? Do you really want to delete this seller?");

    QPushButton *buttonYes, *buttonNo;

    buttonYes = msgbox->addButton(QMessageBox::Yes);
    msgbox->addButton(QMessageBox::No);

    msgbox->exec();

    if (msgbox->clickedButton() == buttonYes) {
        QSqlQuery deleteQuery;
        deleteQuery.prepare("DELETE FROM sellers WHERE id=?");
        deleteQuery.addBindValue(ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt());

        if (deleteQuery.exec()) {
            QMessageBox::information(this, "Success", "Seller has been deleted");
            loadData();
        } else {
            QMessageBox::critical(this, "Error", "Seller has not been deleted");
        }
    }

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
