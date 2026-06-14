#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QString>
#include <QStack>

class Calculator : public QWidget {
public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void onButtonClicked();
    void onClearClicked();
    void onEqualsClicked();

private:
    QLineEdit *display;
    QStack<QString> history; // Stack for calculation history
};

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Calculator");

    // Create the display
    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);

    // Create the number and operator buttons
    QStringList buttons = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "C", "0", "=", "+"
    };

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(display, 0, 0, 1, 4); // display spans across 4 columns

    int row = 1, col = 0;
    for (const QString &buttonText : buttons) {
        QPushButton *button = new QPushButton(buttonText, this);
        layout->addWidget(button, row, col);
        
        connect(button, &QPushButton::clicked, this, &Calculator::onButtonClicked);
        
        col++;
        if (col > 3) {
            col = 0;
            row++;
        }
    }

    // Set layout
    setLayout(layout);
}

void Calculator::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString buttonText = button->text();

    if (buttonText == "C") {
        onClearClicked();
    } else if (buttonText == "=") {
        onEqualsClicked();
    } else {
        display->setText(display->text() + buttonText);
    }
}

void Calculator::onClearClicked() {
    display->clear();
}

void Calculator::onEqualsClicked() {
    QString expression = display->text();
    // Here you can add code to evaluate the expression (basic parsing or use eval libraries)
    display->setText(expression); // For now, just return the same expression
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Calculator calculator;
    calculator.show();
    return app.exec();
}

