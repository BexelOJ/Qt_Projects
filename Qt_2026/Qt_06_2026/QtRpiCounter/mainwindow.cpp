#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lcdNumber_display->setStyleSheet(
        "QLCDNumber {"
        "    color:green;"
        "    background-color: black;"
        "}"
        );

    ui->lcdNumber_display->display(counter);

    connect(ui->pushButton_inc, &QPushButton::clicked,
            this, &MainWindow::onIncrementClicked);

    connect(ui->pushButton_dec, &QPushButton::clicked,
            this, &MainWindow::onDecrementClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onIncrementClicked()
{
    counter++;
    ui->lcdNumber_display->display(counter);
}

void MainWindow::onDecrementClicked()
{
    counter--;
    ui->lcdNumber_display->display(counter);
}


