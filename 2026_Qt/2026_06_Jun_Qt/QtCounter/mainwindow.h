#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); // constructor
    ~MainWindow();                 // destructor, only declaration

private slots:
    void readGPIO();
    void onIncrementClicked(); // slot function declared (for Increment function)
    void onDecrementClicked(); // slot function declared (for Decrement function)

private:
    Ui::MainWindow *ui;
    int counter = 0;

    bool last23 = false;
    bool last25 = false;

    QTimer *timer;
};

#endif // MAINWINDOW_H

