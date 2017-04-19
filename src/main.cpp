/*
 * Ukulele software
 * Author: Natnael Getahun <n.getahun@jacobs-university.de>
 * Description: A simple GUI program that outputs what's written in the
 * text box
 * March 2017
 */

#include "ui/mainwindow.h"
#include <QApplication>
#include <cstdio>
#include "../includes/ukuleleFactoryConfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
