#include "mainwindow.h"
#include "ui_ukulele_main.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // myUkulele = new ukuleleFactory();
}

MainWindow::~MainWindow()
{
    delete ui;
    // delete myUkuelele;
}

