#include "reportsellerperyeardialog.h"
#include "ui_reportsellerperyeardialog.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

#include "../sales/salesmodel.h"

ReportSellerPerYearDialog::ReportSellerPerYearDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportSellerPerYearDialog)
{
    ui->setupUi(this);

    ui->comboBoxOrder->addItem("Best To Worst", "best");
    ui->comboBoxOrder->addItem("Worst To Best", "worst");

    ui->comboBoxTop->addItem("All", 0);
    ui->comboBoxTop->addItem("Top 1", 1);
    ui->comboBoxTop->addItem("Top 3", 3);
    ui->comboBoxTop->addItem("Top 5", 5);
    ui->comboBoxTop->addItem("Top 10", 10);
}

ReportSellerPerYearDialog::~ReportSellerPerYearDialog()
{
    delete ui;
}

void ReportSellerPerYearDialog::on_pushButtonRun_clicked()
{
    QString order = ui->comboBoxOrder->currentData().toString();
    int limit = ui->comboBoxTop->currentData().toInt();
    QString year = ui->lineEditYear->text();

    static QRegularExpression re("\\d{4}");
    QRegularExpressionMatch match = re.match(year);
    if (!match.hasMatch()) {
        QMessageBox::critical(this, "Input Error", "Year must be 4 digits and numeric");
        return;
    }

    QSqlQuery query = SalesModel::sellerByYear(year, order, limit);
    QSqlQueryModel *tableModel = new QSqlQueryModel(this);
    tableModel->setQuery(std::move(query));

    tableModel->setHeaderData(0, Qt::Horizontal, "Seller First Name");
    tableModel->setHeaderData(1, Qt::Horizontal, "Seller Last Name");
    tableModel->setHeaderData(2, Qt::Horizontal, "Total Sales");
    tableModel->setHeaderData(3, Qt::Horizontal, "Total Sales Value");

    ui->tableView->setModel(tableModel);
}


void ReportSellerPerYearDialog::on_pushButtonClose_clicked()
{
    this->close();
}

