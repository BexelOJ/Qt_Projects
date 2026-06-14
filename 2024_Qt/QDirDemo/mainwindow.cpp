#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    // QDir dir("D:/WorkSpace/Qt/QDirDemo");
    // if(dir.exists())
    // {
    //     QMessageBox::information(this,"title","true");
    // }
    // else{
    //     QMessageBox::information(this,"title","false");
    // }
    QDir dir;

    foreach (QFileInfo var, dir.drives()){
        ui->comboBox->addItem(var.absoluteFilePath());
    }

    QDir dir_2("D:/WorkSpace/Qt/QDirDemo");
    foreach (QFileInfo var, dir_2.entryInfoList()){
        if(var.isDir())
            ui->listWidget->addItem("Dir : " + var.absoluteFilePath());
        if(var.isFile())
            ui->listWidget->addItem("File : " + var.absoluteFilePath());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDir dir("D:/WorkSpace/Qt/QDirDemo/img");
    if(dir.exists())
    {
        QMessageBox::information(this,"", "dir exists");
    }
    else
    {
        dir.mkpath("D:/WorkSpace/Qt/QDirDemo/img");
    }

}

