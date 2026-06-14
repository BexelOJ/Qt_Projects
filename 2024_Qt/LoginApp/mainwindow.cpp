#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/EIL_Cr.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->statusbar->addPermanentWidget(ui->label_3,1);
//    ui->progressBar->
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_Password->text();

    if(username == "test" && password == "test"){
        // QMessageBox::information(this, "Login", "Username and Password is Correct");
        // hide();
        secDialog = new SecDialog(this);

        ui->statusbar->showMessage("Username and Password is Correct",2000);
        secDialog->show();
    }
    else
    {
        // QMessageBox::warning(this, "Login", "Username and Password is InCorrect");
        ui->statusbar->showMessage("Username and Password is InCorrect",2000);
    }
}

