#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = "../ukuleleFactory/output.txt";

    QFile file(filename);

    // get user input
    QString input = this->ui->inputArea->toPlainText();

    // make sure the device is opened in append mode;
    if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << input << endl;
    }

    const char * input_char = input.toStdString().c_str();
    file.write(input_char, qstrlen(input_char));

    file.flush();
    file.close();
    // empty the text widget
    this->ui->inputArea->setPlainText("");
}
