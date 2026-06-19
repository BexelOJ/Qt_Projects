#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect button click to a slot
    //connect(ui->btnIncrease, &QPushButton::clicked, this, &MainWindow::on_btnIncrease_clicked);
    //connect(ui->btnDecrease, &QPushButton::clicked, this, &MainWindow::on_btnDecrease_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ✅ Add your slot function here
void MainWindow::on_btnIncrease_clicked()
{
    counter++;
    ui->lblCount->setText(QString::number(counter));
}

void MainWindow::on_btnDecrease_clicked()
{
    counter--;;
    ui->lblCount->setText(QString::number(counter));
}

void MainWindow::on_btnReset_clicked()
{
    counter = 0;
    ui->lblCount->setText(QString::number(counter));
}
