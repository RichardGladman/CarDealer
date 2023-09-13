#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSettings>

#include "settingsframe.h"
#include "newvehicleframe.h"
#include "vehiclesframe.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QSettings settings("TheFifthContinent", "CarDealer");

    settings.beginGroup("Database");
    QString server = settings.value("server").toString();
    QString database = settings.value("database").toString();
    QString username = settings.value("username").toString();
    QString password = settings.value("password").toString();
    settings.endGroup();


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
    QMessageBox::about(this, "About Car Dealer", "Car Dealer by The Fifth Continent\n\nCopyright © 2023");
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


void MainWindow::on_actionAdd_New_Vehicle_triggered()
{
    NewVehicleFrame *newVehicleFrame = new NewVehicleFrame(this);
    setCentralWidget(newVehicleFrame);
}


void MainWindow::on_actionVehicles_triggered()
{
    VehiclesFrame *vehiclesFrame = new VehiclesFrame;
    setCentralWidget(vehiclesFrame);
}

