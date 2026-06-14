#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonIncrease_clicked();
    void on_buttonDecrease_clicked();
    void updateDisplay();  // ✅ Add this line if missing

private:
    Ui::MainWindow *ui;
    int counter = 0;
};

#endif // MAINWINDOW_H
