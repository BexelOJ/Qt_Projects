#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QLabel *label = new QLabel("Hello World");
    label->setWindowTitle("My App");
    label->resize(300,300);
    label -> show();
    return app.exec();
}
