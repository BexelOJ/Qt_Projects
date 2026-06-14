#ifndef MAINWINDOWRPIMONITOR_H
#define MAINWINDOWRPIMONITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowRpiMonitor;
}
QT_END_NAMESPACE

class MainWindowRpiMonitor : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowRpiMonitor(QWidget *parent = nullptr);
    ~MainWindowRpiMonitor();

private:
    Ui::MainWindowRpiMonitor *ui;
};
#endif // MAINWINDOWRPIMONITOR_H
