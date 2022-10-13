#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>

class DataBaseManager
{

public:
    DataBaseManager();
    ~DataBaseManager();

    QSqlDatabase *getDatabase();

    QSqlQuery sqlRequest(QString request);
    QSqlQuery sqlRequest(QSqlQuery &query);

private:
    QSqlDatabase *db;

    void configureDataBase(QString hostName, QString dataBaseName, QString userName, QString password, int port);
};

#endif // DATABASEMANAGER_H
