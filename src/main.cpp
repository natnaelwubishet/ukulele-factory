/*
 * Ukulele software
 * Author: Natnael Getahun <n.getahun@jacobs-university.de>
 * Description: A simple GUI program that outputs what's written in the
 * text box
 * March 2017
 */

#include "../includes/mainwindow.h"
#include <QApplication>
#include <cstdio>
#include "../includes/ukuleleFactoryConfig.h"

int main(int argc, char *argv[])
{
    fprintf(stdout, argv[0],
            "%s Version %d.%d\n",
            ukuleleFactory_VERSION_MAJOR,
            ukuleleFactory_VERSION_MINOR);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
