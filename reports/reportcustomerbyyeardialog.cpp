#include "reportcustomerbyyeardialog.h"
#include "ui_reportcustomerbyyeardialog.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

#include "../sales/salesmodel.h"
#include "../delegates/currencydelegate.h"

ReportCustomerByYearDialog::ReportCustomerByYearDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportCustomerByYearDialog)
{
    ui->setupUi(this);

    CurrencyDelegate *salesDelegate = new CurrencyDelegate(this);
    salesDelegate->setColumn(2);

    CurrencyDelegate *negotiatedDelegate = new CurrencyDelegate(this);
    negotiatedDelegate->setColumn(3);

    ui->comboBoxOrder->addItem("Best To Worst", "best");
    ui->comboBoxOrder->addItem("Worst To Best", "worst");

    ui->comboBoxTop->addItem("All", 0);
    ui->comboBoxTop->addItem("Top 1", 1);
    ui->comboBoxTop->addItem("Top 3", 3);
    ui->comboBoxTop->addItem("Top 5", 5);
    ui->comboBoxTop->addItem("Top 10", 10);

    ui->tableView->setItemDelegateForColumn(2, salesDelegate);
    ui->tableView->setItemDelegateForColumn(3, negotiatedDelegate);
}

ReportCustomerByYearDialog::~ReportCustomerByYearDialog()
{
    delete ui;
}

void ReportCustomerByYearDialog::on_pushButtonRun_clicked()
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

    QSqlQuery query = SalesModel::customerByYear(year, order, limit);
    QSqlQueryModel *tableModel = new QSqlQueryModel(this);
    tableModel->setQuery(std::move(query));

    tableModel->setHeaderData(0, Qt::Horizontal, "Customer Name");
    tableModel->setHeaderData(1, Qt::Horizontal, "Total Sales");
    tableModel->setHeaderData(2, Qt::Horizontal, "Total Sales Value");
    tableModel->setHeaderData(3, Qt::Horizontal, "Negotiated Sales Value");

    ui->tableView->setModel(tableModel);
}


void ReportCustomerByYearDialog::on_pushButtonClose_clicked()
{
    this->close();
}

