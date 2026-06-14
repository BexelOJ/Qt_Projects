#include "mainwindow.h"
#include "ui_mainwindow.h"  // IMPORTANT: include generated UI header

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect buttons signals to slots
    connect(ui->buttonIncrease, &QPushButton::clicked, this, &MainWindow::on_buttonIncrease_clicked);
    connect(ui->buttonDecrease, &QPushButton::clicked, this, &MainWindow::on_buttonDecrease_clicked);

    ui->labelTitle->setText("Powered by\nExin Innvo Labs");
    updateDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonIncrease_clicked()
{
    counter++;
    updateDisplay();
}

void MainWindow::on_buttonDecrease_clicked()
{
    counter--;
    updateDisplay();
}

void MainWindow::updateDisplay()
{
    ui->labelCount->setText(QString("Count: %1").arg(counter));
}
