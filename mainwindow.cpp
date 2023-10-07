#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSettings>

#include "settings/settingsframe.h"
#include "vehicles/vehiclesframe.h"
#include "sellers/sellerframe.h"
#include "customers/customersframe.h"
#include "sales/salesframe.h"
#include "reports/reportsellerpermonthdialog.h"
#include "reports/reportsellerperyeardialog.h"
#include "reports/reportcustomerbyyeardialog.h"
#include "reports/reportcardealerperyeardialog.h"
#include "reports/reportcardealerbymonthdialog.h"

#include "settings/settings.h"

Settings *settings;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QSettings qSettings("TheFifthContinent", "CarDealer");

    qSettings.beginGroup("Database");
    QString server = qSettings.value("server").toString();
    QString database = qSettings.value("database").toString();
    QString username = qSettings.value("username").toString();
    QString password = qSettings.value("password").toString();
    qSettings.endGroup();

    qSettings.beginGroup("General");
    QString currency = qSettings.value("currency").toString();
    qSettings.endGroup();

    settings = new Settings {server, database, username, password, currency};

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(server);
    db.setDatabaseName(database);
    db.setUserName(username);
    db.setPassword(password);


    if (!db.open()) {
        on_actionSettings_triggered();
        QMessageBox::information(this, "Action required", "Please enter database details and restart");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionSettings_triggered()
{
    SettingsFrame *settingsFrame = new SettingsFrame(this);
    setCentralWidget(settingsFrame);
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About Car Dealer", "Car Dealer by Richard Gladman\n\nCopyright © 2023");
}


void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}


void MainWindow::on_actionExit_triggered()
{
    int ret = QMessageBox::question(this, "Are you sure?", "Are you sure you want to exit the program?", QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        QApplication::exit();
    }
}


void MainWindow::on_actionVehicles_triggered()
{
    VehiclesFrame *vehiclesFrame = new VehiclesFrame(this);
    setCentralWidget(vehiclesFrame);
}


void MainWindow::on_actionSellers_triggered()
{
    SellerFrame *sellerFrame = new SellerFrame(this);
    setCentralWidget(sellerFrame);
}


void MainWindow::on_actionCustomers_triggered()
{
    CustomersFrame *customersFrame = new CustomersFrame(this);
    setCentralWidget(customersFrame);
}


void MainWindow::on_actionSell_Vehicle_triggered()
{
    SalesFrame *salesFrame = new SalesFrame(this);
    setCentralWidget(salesFrame);
}


void MainWindow::on_actionSeller_By_Month_triggered()
{
    ReportSellerPerMonthDialog *reportSellerPerMonth = new ReportSellerPerMonthDialog(this);
    reportSellerPerMonth->exec();
}


void MainWindow::on_actionSeller_By_Year_triggered()
{
    ReportSellerPerYearDialog *reportSellerPerYear = new ReportSellerPerYearDialog(this);
    reportSellerPerYear->exec();
}


void MainWindow::on_actionCustomer_By_Year_triggered()
{
    ReportCustomerByYearDialog *reportCustomerByYear = new ReportCustomerByYearDialog(this);
    reportCustomerByYear->exec();
}


void MainWindow::on_actionDealer_By_Year_triggered()
{
    ReportCarDealerPerYearDialog *carDealerDialog = new ReportCarDealerPerYearDialog(this);
    carDealerDialog->exec();
}


void MainWindow::on_actionDealer_By_Month_triggered()
{
    ReportCarDealerByMonthDialog *carDealerDialog = new ReportCarDealerByMonthDialog(this);
    carDealerDialog->exec();
}
