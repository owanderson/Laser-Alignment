#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtCore>

#include <QtWidgets>



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

    // Move Left
    action = new QAction("Move Left", this);
    connect(action, &QAction::triggered, this, &MainWindow::MoveLeft);
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



    //BUTTONS FOR GPIO4 SERVO-CONTROL
    QPushButton *gpio4right = new QPushButton(this);
    gpio4right->setText("GPIO4 Right");
    connect(gpio4right, SIGNAL (released()), this, SLOT (gpio4rightPress()));
    gpio4right->move(20, 40);
    gpio4right->show();

    QPushButton *gpio4left = new QPushButton(this);
    gpio4left->setText("GPIO4 Left");
    connect(gpio4left, SIGNAL (released()), this, SLOT (gpio4leftPress()));
    gpio4left->move(20, 80);
    gpio4left->show();


    //BUTTONS FOR GPIO5 SERVO-CONTROL
    QPushButton *gpio5right = new QPushButton(this);
    gpio5right->setText("GPIO5 Right");
    connect(gpio5right, SIGNAL (released()), this, SLOT (gpio5rightPress()));
    gpio5right->move(200, 40);
    gpio5right->show();

    QPushButton *gpio5left = new QPushButton(this);
    gpio5left->setText("GPIO5 Left");
    connect(gpio5left, SIGNAL (released()), this, SLOT (gpio5leftPress()));
    gpio5left->move(200, 80);
    gpio5left->show();


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
    std::system("./MoveRight");

}

void MainWindow::MoveLeft()
{
    statusBar()->showMessage("Moving left...");
    std::system("./MoveLeft");

}

void MainWindow::gpio4rightPress()
{
    statusBar()->showMessage("Moving GPIO4 Right...");
    std::system("./MoveRight");


}

void MainWindow::gpio4leftPress()
{
    statusBar()->showMessage("Moving GPIO4 Left...");
    std::system("./MoveLeft");


}

void MainWindow::gpio5rightPress()
{
    statusBar()->showMessage("Moving GPIO5 Right...");
    std::system("./MoveRight 5");


}

void MainWindow::gpio5leftPress()
{
    statusBar()->showMessage("Moving GPIO5 Left...");
    std::system("./MoveRight 5");


}



