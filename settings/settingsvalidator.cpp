#include "settingsvalidator.h"

SettingsValidator::SettingsValidator(QString server, QString database, QString username, QString password): server(server), database(database), username(username), password(password) {}

bool SettingsValidator::validate(QString &message)
{
    bool valid = true;

    if (server == "") {
        valid = false;
        message += "\nServer name cannot be left blank";
    }

    if (database == "") {
        valid = false;
        message += "\nDatabase name cannot be left blank";
    }

    if (username == "") {
        valid = false;
        message += "\nUser name cannot be left blank";
    }

    if (password == "") {
        valid = false;
        message += "\nPassword cannot be left blank";
    }

    return valid;
}
