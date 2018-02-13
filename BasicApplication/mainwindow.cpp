#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtCore>


#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <home/pi/wiringPi/wiringPi/wiringPi.h>
#include <home/pi/wiringPi/wiringPi/softServo.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    // == WINDOW SETTINGS ==
    setWindowTitle("Laser Alignment");

    setMinimumSize(800, 450);




    // == MENU BAR ==
    QMenuBar * menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // -- File menu --
    QMenu * menu = menuBar->addMenu("&File");

    // -- Align menu --
    QMenu * menu2 = menuBar->addMenu("Alignment");

    // New
    QAction * action = new QAction("&New", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnFileNew);
    menu->addAction(action);

    // Move Right
    action = new QAction("Move Right", this);
    connect(action, &QAction::triggered, this, &MainWindow::MoveRight);
    menu2->addAction(action);


    // Open
    action = new QAction("&Open", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnFileOpen);
    menu->addAction(action);

    // Save
    action = new QAction("&Save", this);
    connect(action, &QAction::triggered, this, &MainWindow::OnFileSave);
    menu->addAction(action);

    // separator
    menu->addSeparator();

    // Exit
    action = new QAction("&Exit", this);
    connect(action, &QAction::triggered, this, &MainWindow::close);
    menu->addAction(action);


    // == STATUS BAR ==
    QStatusBar * statusBar = new QStatusBar(this);
    setStatusBar(statusBar);



}

// == PRIVATE SLOTS ==
void MainWindow::OnFileNew()
{
    statusBar()->showMessage("File -> New");
}

void MainWindow::OnFileOpen()
{
    statusBar()->showMessage("File -> Open");
}

void MainWindow::OnFileSave()
{
    statusBar()->showMessage("File -> Save");
}

void MainWindow::MoveRight()
{
    statusBar()->showMessage("Moving right...");

    if (wiringPiSetup () == -1)
    {
    fprintf (stdout, "oops: %s\n", strerror (errno)) ;
    return 1 ;
    }

    softServoSetup (0, 1, 2, 3, 4, 5, 6, 7) ;

    softServoWrite (0,  500) ;
/*
    softServoWrite (1, 1000) ;
    softServoWrite (2, 1100) ;
    softServoWrite (3, 1200) ;
    softServoWrite (4, 1300) ;
    softServoWrite (5, 1400) ;
    softServoWrite (6, 1500) ;
    softServoWrite (7, 2200) ;
*/

    for (;;)
    delay (10) ;

}



