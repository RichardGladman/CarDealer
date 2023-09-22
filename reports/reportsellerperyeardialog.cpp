#include "reportsellerperyeardialog.h"
#include "ui_reportsellerperyeardialog.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

ReportSellerPerYearDialog::ReportSellerPerYearDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportSellerPerYearDialog)
{
    ui->setupUi(this);

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

    QString sql = "SELECT p.first_name, p.last_name, count(s.id), sum(v.price) FROM sales s INNER JOIN sellers p ON s.seller_id = p.id";
    sql += " INNER JOIN vehicles v ON s.vehicle_id = v.id WHERE s.added_date BETWEEN '" + startDate + "' AND '" + endDate + "'";
    sql += " GROUP BY p.id";

    if (limit != 0) {
        sql += " LIMIT " + QString::number(limit);
    }

    QSqlQuery query;
    query.prepare(sql);

    if (query.exec()) {
        QSqlQueryModel *tableModel = new QSqlQueryModel(this);
        tableModel->setQuery(std::move(query));

        tableModel->setHeaderData(0, Qt::Horizontal, "Seller First Name");
        tableModel->setHeaderData(1, Qt::Horizontal, "Seller Last Name");
        tableModel->setHeaderData(2, Qt::Horizontal, "Total Sales");
        tableModel->setHeaderData(3, Qt::Horizontal, "Total Sales Value");

        ui->tableView->setModel(tableModel);
    }
}


void ReportSellerPerYearDialog::on_pushButtonClose_clicked()
{
    this->close();
}

