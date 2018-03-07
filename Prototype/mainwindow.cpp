#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtCore>

#include <QtWidgets>
#include <QApplication>
#include <QTextEdit>





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


    //BUTTONS FOR GPIO6 SERVO-CONTROL
    QPushButton *gpio6right = new QPushButton(this);
    gpio6right->setText("GPIO6 Right");
    connect(gpio6right, SIGNAL (released()), this, SLOT (gpio6rightPress()));
    gpio6right->move(380, 40);
    gpio6right->show();

    QPushButton *gpio6left = new QPushButton(this);
    gpio6left->setText("GPIO6 Left");
    connect(gpio6left, SIGNAL (released()), this, SLOT (gpio6leftPress()));
    gpio6left->move(380, 80);
    gpio6left->show();

    //BUTTONS FOR GPIO13 SERVO-CONTROL
    QPushButton *gpio13right = new QPushButton(this);
    gpio13right->setText("GPIO13 Right");
    connect(gpio13right, SIGNAL (released()), this, SLOT (gpio13rightPress()));
    gpio13right->move(560, 40);
    gpio13right->show();

    QPushButton *gpio13left = new QPushButton(this);
    gpio13left->setText("GPIO13 Left");
    connect(gpio13left, SIGNAL (released()), this, SLOT (gpio13leftPress()));
    gpio13left->move(560, 80);
    gpio13left->show();

    //BUTTONS FOR RASTER COMMAND
    QPushButton *rasterButton = new QPushButton(this);
    rasterButton->setText("Raster Scan");
    connect(rasterButton, SIGNAL (released()), this, SLOT (rasterPress()));
    rasterButton->move(20, 200);
    rasterButton->setFixedSize(200,200);
    rasterButton->show();



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
    std::system("./MoveRight 5");


}

void MainWindow::gpio4leftPress()
{
    statusBar()->showMessage("Moving GPIO4 Left...");
    std::system("./MoveLeft 5");


}

void MainWindow::gpio5rightPress()
{
    statusBar()->showMessage("Moving GPIO5 Right...");
    std::system("./MoveRight 27");


}

void MainWindow::gpio5leftPress()
{
    statusBar()->showMessage("Moving GPIO5 Left...");
    std::system("./MoveLeft 27");

}

void MainWindow::gpio6rightPress()
{
    statusBar()->showMessage("Moving GPIO6 Right...");
    std::system("./MoveRight 6");

}

void MainWindow::gpio6leftPress()
{
    statusBar()->showMessage("Moving GPIO6 Left...");
    std::system("./MoveLeft 6");

}

void MainWindow::gpio13rightPress()
{
    statusBar()->showMessage("Moving GPIO13 Right...");
    std::system("./MoveRight 13");

}

void MainWindow::gpio13leftPress()
{
    statusBar()->showMessage("Moving GPIO13 Left...");
    std::system("./MoveLeft 13");

}

void MainWindow::rasterPress()
{
    statusBar()->showMessage("Rastering...");
    //insert code here for a raster scan of servo motors
    std::system("./gogo");
    readfile();


}





void MainWindow::readfile(){
    QString filename="E:\\Prototype\\test.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "NO existe el archivo "<<filename;
    }else{
        qDebug() << filename<<" encontrado...";
    }
    QString line;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();

            qDebug() << "linea: "<<line;
        }
    }
    file.close();

    QTextEdit *txt = new QTextEdit();
    txt->setText(line);
    txt->show();
}





