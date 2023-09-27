#include "reportcardealerbymonthdialog.h"
#include "ui_reportcardealerbymonthdialog.h"

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

#include "../sales/salesmodel.h"

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

    QSqlQuery query = SalesModel::getDealerByMonth(year);
    QSqlQueryModel *tableModel = new QSqlQueryModel(this);
    tableModel->setQuery(std::move(query));

    tableModel->setHeaderData(0, Qt::Horizontal, "Year");
    tableModel->setHeaderData(1, Qt::Horizontal, "Month");
    tableModel->setHeaderData(2, Qt::Horizontal, "Total Sales");
    tableModel->setHeaderData(3, Qt::Horizontal, "Total Sales Value");


    ui->tableView->setModel(tableModel);
}


void ReportCarDealerByMonthDialog::on_pushButtonClose_clicked()
{
    this->close();
}

