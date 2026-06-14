#include "stdafx.h"
#include <QtCore/QCoreApplication>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Hello from Qt!";
    return a.exec();
}
