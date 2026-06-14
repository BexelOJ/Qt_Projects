#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QListWidgetItem item = new QListWidgetItem(QIcon(":/rec/img/IMG_20241005_152639591.jpg"));
    ui->listWidget->addItem("Mark");
    ui->listWidget->addItem("John");
    ui->listWidget->addItem("Irin");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   // QMessageBox::information(this, "title",ui->listWidget->currentItem()->text());
    ui->listWidget->currentItem()->setBackground(Qt::red);
    ui->listWidget->currentItem()->setForeground(Qt::yellow);
}

