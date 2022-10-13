#include "databasemanager.h"

DataBaseManager::DataBaseManager()
{
    db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QOCI");

    configureDataBase("DESKTOP-L2IVCIR", "XE", "SYSTEM", "lonep", 1521);
    db->open();
}

DataBaseManager::~DataBaseManager()
{
    delete db;
}

QSqlDatabase *DataBaseManager::getDatabase()
{
    return db;
}

QSqlQuery DataBaseManager::sqlRequest(QString request)
{
    QSqlQuery query(request);
    return query;
}

QSqlQuery DataBaseManager::sqlRequest(QSqlQuery &query)
{
    qDebug() << query.exec();
}

void DataBaseManager::configureDataBase(QString hostName, QString dataBaseName, QString userName, QString password, int port)
{
    db->setHostName(hostName);
    db->setDatabaseName(dataBaseName);
    db->setUserName(userName);
    db->setPassword(password);
    db->setPort(port);
}

