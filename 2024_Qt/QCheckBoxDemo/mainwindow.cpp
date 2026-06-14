#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox->setChecked(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked())
    {
        QMessageBox::information(this,"Title","Yes, User Likes Apple");
    }
    else
    {
        // QMessageBox::critical(this,"Title","No, User Does Not likes Apple");
        QMessageBox::information(this,"Title","No, User Does Not likes Apple");
    }
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked())
    {
        QMessageBox::information(this,"Title","Yes, User Likes Apple");
    }
    else
    {
        // QMessageBox::critical(this,"Title","No, User Does Not likes Apple");
        QMessageBox::information(this,"Title","No, User Does Not likes Apple");
    }
}

