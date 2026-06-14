#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);  // constructor
    ~MainWindow();     // destructor

private:
    Ui::MainWindow *ui;

//private slots:
 //   void onMyButtonClicked();
private slots:
    void on_btnIncrease_clicked();
    void on_btnDecrease_clicked();
    void on_btnReset_clicked();

private:
    int counter = 0; // Keep track of the count

};
#endif // MAINWINDOW_H
