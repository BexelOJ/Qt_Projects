#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QProcess>

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

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, &MainWindow::readGPIO);

    timer->start(100); // 100 ms polling


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


void MainWindow::readGPIO()
{
    QProcess p23;
    p23.start("gpioget", {"gpiochip0", "23"});
    p23.waitForFinished();
    bool v23 = (p23.readAllStandardOutput().trimmed() == "1");

    QProcess p25;
    p25.start("gpioget", {"gpiochip0", "25"});
    p25.waitForFinished();
    bool v25 = (p25.readAllStandardOutput().trimmed() == "1");

    // Rising edge detection (0 → 1)
    if (v23 && !last23) {
        counter++;
        ui->lcdNumber_display->display(counter);
    }

    if (v25 && !last25) {
        counter--;
        ui->lcdNumber_display->display(counter);
    }

    last23 = v23;
    last25 = v25;
}

