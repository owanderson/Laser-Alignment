#include "mainwindow2.h"
#include <QApplication>
#include <QtGui>
#include <QtCore>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();



    return a.exec();
}
