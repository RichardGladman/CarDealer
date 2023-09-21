#include "reportcardealerbymonthdialog.h"
#include "ui_reportcardealerbymonthdialog.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

ReportCarDealerByMonthDialog::ReportCarDealerByMonthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportCarDealerByMonthDialog)
{
    ui->setupUi(this);
}

ReportCarDealerByMonthDialog::~ReportCarDealerByMonthDialog()
{
    delete ui;
}

void ReportCarDealerByMonthDialog::on_pushButtonRun_clicked()
{
    QString year = ui->lineEditYear->text();

    static QRegularExpression re("\\d{4}");
    QRegularExpressionMatch match = re.match(year);
    if (!match.hasMatch()) {
        QMessageBox::critical(this, "Input Error", "Year must be 4 digits and numeric");
        return;
    }

    QString sql = "SELECT YEAR(s.added_date) AS y, MONTH(s.added_date) AS m, count(s.id), sum(v.price) FROM sales s";
    sql += " INNER JOIN vehicles v ON s.vehicle_id = v.id";
    sql += " GROUP BY y, m";

    QSqlQuery query;
    query.prepare(sql);

    if (query.exec()) {
        QSqlQueryModel *tableModel = new QSqlQueryModel(this);
        tableModel->setQuery(std::move(query));

        tableModel->setHeaderData(0, Qt::Horizontal, "Year");
        tableModel->setHeaderData(1, Qt::Horizontal, "Month");
        tableModel->setHeaderData(2, Qt::Horizontal, "Total Sales");
        tableModel->setHeaderData(3, Qt::Horizontal, "Total Sales Value");


        ui->tableView->setModel(tableModel);
    }

}


void ReportCarDealerByMonthDialog::on_pushButtonClose_clicked()
{
    this->close();
}

