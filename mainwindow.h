#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <list>
#include "ukuleleFactory.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ukuleleFactory *myUkulele;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
