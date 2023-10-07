#ifndef SETTINGSVALIDATOR_H
#define SETTINGSVALIDATOR_H

#include <QString>

class SettingsValidator
{
public:
    SettingsValidator(QString server, QString database, QString username, QString password, QString currency);
    bool validate(QString &message);

private:
    QString server;
    QString database;
    QString username;
    QString password;
    QString currency;
};

#endif // SETTINGSVALIDATOR_H
