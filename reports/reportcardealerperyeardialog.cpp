#include "reportcardealerperyeardialog.h"
#include "ui_reportcardealerperyeardialog.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

ReportCarDealerPerYearDialog::ReportCarDealerPerYearDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportCarDealerPerYearDialog)
{
    ui->setupUi(this);

    ui->comboBoxTop->addItem("All", 0);
    ui->comboBoxTop->addItem("Latest 1", 1);
    ui->comboBoxTop->addItem("Latest 3", 3);
    ui->comboBoxTop->addItem("Latest 5", 5);
    ui->comboBoxTop->addItem("Latest 10", 10);
}

ReportCarDealerPerYearDialog::~ReportCarDealerPerYearDialog()
{
    delete ui;
}

void ReportCarDealerPerYearDialog::on_pushButtonRun_clicked()
{
    int limit = ui->comboBoxTop->currentData().toInt();

    QString sql = "SELECT YEAR(s.added_date) AS y, count(s.id), sum(v.price) FROM sales s";
    sql += " INNER JOIN vehicles v ON s.vehicle_id = v.id";
    sql += " GROUP BY y";

    if (limit != 0) {
        sql += " LIMIT " + QString::number(limit);
    }

    QSqlQuery query;
    query.prepare(sql);

    if (query.exec()) {
        QSqlQueryModel *tableModel = new QSqlQueryModel(this);
        tableModel->setQuery(std::move(query));

        tableModel->setHeaderData(0, Qt::Horizontal, "Year");
        tableModel->setHeaderData(1, Qt::Horizontal, "Total Sales");
        tableModel->setHeaderData(2, Qt::Horizontal, "Total Sales Value");

        ui->tableView->setModel(tableModel);
    }
}


void ReportCarDealerPerYearDialog::on_pushButtonClose_clicked()
{
    this->close();
}

