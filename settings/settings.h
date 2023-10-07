#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>


class Settings
{
public:
    Settings(QString server, QString database, QString username, QString password, QString currency);
    Settings();

    QString getServer() const;
    QString getDatabase() const;
    QString getUsername() const;
    QString getPassword() const;
    QString getCurrency() const;

private:
    QString server;
    QString database;
    QString username;
    QString password;
    QString currency;
};

#endif // SETTINGS_H
