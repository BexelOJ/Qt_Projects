#include "mainwindowrpimonitor.h"
#include "./ui_mainwindowrpimonitor.h"

MainWindowRpiMonitor::MainWindowRpiMonitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowRpiMonitor)
{
    ui->setupUi(this);
}

MainWindowRpiMonitor::~MainWindowRpiMonitor()
{
    delete ui;
}
