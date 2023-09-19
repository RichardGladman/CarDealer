#include "reportcustomerbyyeardialog.h"
#include "ui_reportcustomerbyyeardialog.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

ReportCustomerByYearDialog::ReportCustomerByYearDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportCustomerByYearDialog)
{
    ui->setupUi(this);

    ui->comboBoxTop->addItem("All", 0);
    ui->comboBoxTop->addItem("Top 1", 1);
    ui->comboBoxTop->addItem("Top 3", 3);
    ui->comboBoxTop->addItem("Top 5", 5);
    ui->comboBoxTop->addItem("Top 10", 10);
}

ReportCustomerByYearDialog::~ReportCustomerByYearDialog()
{
    delete ui;
}

void ReportCustomerByYearDialog::on_pushButtonRun_clicked()
{
    int limit = ui->comboBoxTop->currentData().toInt();
    QString year = ui->lineEditYear->text();

    static QRegularExpression re("\\d{4}");
    QRegularExpressionMatch match = re.match(year);
    if (!match.hasMatch()) {
        QMessageBox::critical(this, "Input Error", "Year must be 4 digits and numeric");
        return;
    }

    QString startDate = year + "-01-01 00:00:00";
    QString endDate = year + "-12-31 23:59:59";

    QString sql = "SELECT c.name, count(s.id), sum(v.price) FROM sales s INNER JOIN customers c ON s.customer_id = c.id";
    sql += " INNER JOIN vehicles v ON s.vehicle_id = v.id WHERE s.added_date BETWEEN '" + startDate + "' AND '" + endDate + "'";
    sql += " GROUP BY c.id";

    if (limit != 0) {
        sql += " LIMIT " + QString::number(limit);
    }

    QSqlQuery query;
    query.prepare(sql);

    if (query.exec()) {
        QSqlQueryModel *tableModel = new QSqlQueryModel(this);
        tableModel->setQuery(std::move(query));

        tableModel->setHeaderData(0, Qt::Horizontal, "Customer Name");
        tableModel->setHeaderData(1, Qt::Horizontal, "Total Sales");
        tableModel->setHeaderData(2, Qt::Horizontal, "Total Sales Value");

        ui->tableView->setModel(tableModel);
    }

}


void ReportCustomerByYearDialog::on_pushButtonClose_clicked()
{
    this->close();
}

