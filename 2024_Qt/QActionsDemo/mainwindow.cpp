#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Mark");
    ui->comboBox->addItem("John");
    ui->comboBox->addItem("Irin");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    QMessageBox::information(this, "Title", "New");
}


void MainWindow::on_actionopen_triggered()
{
    QMessageBox::information(this, "Title", "Open");
}


void MainWindow::on_actionexit_triggered()
{
    QApplication::quit();
}

