#include "mainwindow.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":/icons/Qt_Counter_Logo_01.png"));

    MainWindow w;
    w.show();

    return a.exec();
}


