#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "DatabaseManager.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);

    DatabaseManager database;

    database.connectToDatabase();
    database.readLatestMetric();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty(
        "database",
        &database
        );

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("yantraSthiti", "Main");

    return QGuiApplication::exec();
}





