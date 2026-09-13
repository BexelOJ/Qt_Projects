#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject(parent)
{
}

//-------------------------------------------
// Getters
//-------------------------------------------

QString DatabaseManager::serverName() const
{
    return m_serverName;
}

QString DatabaseManager::ip() const
{
    return m_ip;
}

double DatabaseManager::cpu() const
{
    return m_cpu;
}

double DatabaseManager::ram() const
{
    return m_ram;
}

double DatabaseManager::disk() const
{
    return m_disk;
}

//-------------------------------------------
// Connect to PostgreSQL
//-------------------------------------------

bool DatabaseManager::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    db.setHostName("192.168.0.122");
    db.setPort(5432);
    db.setDatabaseName("yantraSthiti_DB");
    db.setUserName("monitor_yantrasthiti_app");

    // TEMPORARY:
    // We will move this out of the source code later.
    db.setPassword("YOUR_PASSWORD");

    if (!db.open()) {

        qDebug() << "PostgreSQL connection failed:";
        qDebug() << db.lastError().text();

        return false;
    }

    qDebug() << "PostgreSQL connected successfully.";

    return true;
}

//-------------------------------------------
// Read latest metric
//-------------------------------------------

bool DatabaseManager::readLatestMetric()
{
    QSqlDatabase db = QSqlDatabase::database();

    QSqlQuery query(db);

    query.prepare(
        "SELECT device_id, ip, cpu, ram, disk "
        "FROM system_metrics "
        "ORDER BY timestamp DESC "
        "LIMIT 1"
        );

    if (!query.exec()) {

        qDebug() << "Query failed:";
        qDebug() << query.lastError().text();

        return false;
    }

    if (!query.next()) {

        qDebug() << "No metric data found.";

        return false;
    }

    m_serverName = query.value("device_id").toString();
    m_ip         = query.value("ip").toString();

    m_cpu  = query.value("cpu").toDouble();
    m_ram  = query.value("ram").toDouble();
    m_disk = query.value("disk").toDouble();

    emit dataChanged();

    qDebug() << "Latest metric:";
    qDebug() << "Server:" << m_serverName;
    qDebug() << "IP:" << m_ip;
    qDebug() << "CPU:" << m_cpu;
    qDebug() << "RAM:" << m_ram;
    qDebug() << "DISK:" << m_disk;

    return true;
}

