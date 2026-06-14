#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // void about
    // void aboutQt
    // StandardButton critical  (x)
    // StandardButton information (i)
    // StandardButton question  (?)
    // StandardButton warning  (I)

    // QMessageBox::about(this, "My Title", "This is my Custom Message");
    // QMessageBox::aboutQt(this, "My Title");
    // QMessageBox::critical(this, "My Title", "This is my CRITICAL Message");
    // QMessageBox::information(this, "My Title", "This is my INFORMATION Message");
     QMessageBox::StandardButton reply = QMessageBox::question(this, "My Title", "Close Application ?", QMessageBox::Yes | QMessageBox::No);
    // QMessageBox::warning(this, "My Title", "This is my WARNING Message");

     if(reply == QMessageBox::Yes){
         QApplication::quit();
     }
     else{
         qDebug() << "No is Clicked";
     }
}

