#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->comboBox->addItem(QIcon(":/rec/img/IMG_20241005_152639591.jpg"),"Mark");
    // ui->comboBox->addItem(QIcon(":/rec/img/IMG_20241005_173805242_HDR.jpg"),"John");
    // ui->comboBox->addItem(QIcon(":/rec/img/IMG_20241006_115128556_HDR.jpg "),"Irin");

    for(int i = 0; i < 10 ; i++)
    {
        ui->comboBox->addItem(QIcon(":/rec/img/IMG_20241005_152639591.jpg"),QString::number(i) + " name");
    }

    ui->comboBox->insertItem(3,QIcon(":/rec/img/IMG_20241005_173805242_HDR.jpg"), "new text");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"Title",QString::number(ui->comboBox->currentIndex()));
}

