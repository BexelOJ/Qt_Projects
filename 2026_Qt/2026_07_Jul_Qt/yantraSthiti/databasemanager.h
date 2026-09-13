#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QString>

class DatabaseManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString serverName READ serverName NOTIFY dataChanged)
    Q_PROPERTY(QString ip READ ip NOTIFY dataChanged)
    Q_PROPERTY(double cpu READ cpu NOTIFY dataChanged)
    Q_PROPERTY(double ram READ ram NOTIFY dataChanged)
    Q_PROPERTY(double disk READ disk NOTIFY dataChanged)

public:

    explicit DatabaseManager(QObject *parent = nullptr);

    QString serverName() const;
    QString ip() const;

    double cpu() const;
    double ram() const;
    double disk() const;

    Q_INVOKABLE bool connectToDatabase();
    Q_INVOKABLE bool readLatestMetric();

signals:

    void dataChanged();

private:

    QString m_serverName;
    QString m_ip;

    double m_cpu = 0.0;
    double m_ram = 0.0;
    double m_disk = 0.0;
};

#endif // DATABASEMANAGER_H


