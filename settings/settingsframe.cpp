#include "settingsframe.h"
#include "ui_settingsframe.h"

#include <QSettings>
#include <QMessageBox>

#include "settingsvalidator.h"

SettingsFrame::SettingsFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingsFrame)
{
    ui->setupUi(this);

    QSettings settings("TheFifthContinent", "CarDealer");

    settings.beginGroup("Database");
    ui->lineEditServer->setText(settings.value("server").toString());
    ui->lineEditDatabase->setText(settings.value("database").toString());
    ui->lineEditUser->setText(settings.value("username").toString());
    ui->lineEditPassword->setText(settings.value("password").toString());
    settings.endGroup();

    settings.beginGroup("General");
    ui->lineEditCurrency->setText(settings.value("currency").toString());
    settings.endGroup();
}

SettingsFrame::~SettingsFrame()
{
    delete ui;
}

void SettingsFrame::on_pushButtonSave_clicked()
{
    QString server = ui->lineEditServer->text();
    QString database = ui->lineEditDatabase->text();
    QString username = ui->lineEditUser->text();
    QString password = ui->lineEditPassword->text();
    QString currency = ui->lineEditCurrency->text();

    SettingsValidator validator {server, database,username, password, currency};
    QString message;

    if (!validator.validate(message)) {
        QMessageBox::critical(this, "Input Error", "One or more errors have occurred:" + message);
        return;
    }

    QSettings settings("TheFifthContinent", "CarDealer");

    settings.beginGroup("Database");
    settings.setValue("server", server);
    settings.setValue("database", database);
    settings.setValue("username", username);
    settings.setValue("password", password);
    settings.endGroup();

    settings.beginGroup("General");
    settings.setValue("currency", currency);
    settings.endGroup();
}

