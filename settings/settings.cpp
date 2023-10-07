#include "settings.h"

Settings::Settings(QString server, QString database, QString username, QString password, QString currency):
    server(server), database(database), username(username), password(password), currency(currency)
{

}

Settings::Settings()
{

}

QString Settings::getServer() const
{
    return server;
}

QString Settings::getDatabase() const
{
    return database;
}

QString Settings::getUsername() const
{
    return username;
}

QString Settings::getPassword() const
{
    return password;
}

QString Settings::getCurrency() const
{
    return currency;
}
