/*
 * Software engineering homework 2
 * Author: Natnael Getahun <n.getahun@jacobs-university.de>
 * Description: A simple GUI program that outputs what's written in the
 * text box
 * Remarks: the outputs are written to the code directory
 * March 2017
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
