#include "mainwindow2.h"

#include <QtGui>
#include <QtCore>

#include <QtWidgets>
#include <QApplication>
#include <QTextEdit>
#include <QLabel>






Window::Window(QWidget *parent) :
    QWidget(parent)

{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createFirstExclusiveGroup(), 0, 0);
    grid->addWidget(createPhotodiodeSelection(), 1, 0);
    grid->addWidget(createFlipControlGroup(), 0, 1);
    grid->addWidget(createPushButtonGroup(), 1, 1);
    setLayout(grid);



    setWindowTitle(tr("Laser Alignment"));
    resize(480, 320);



}

QGroupBox *Window::createFirstExclusiveGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Automated Alignment"));

    QRadioButton *rastercheck = new QRadioButton(tr("&Simple Raster"));
    QRadioButton *gradientcheck = new QRadioButton(tr("&Gradient Ascent"));
    QRadioButton *randomcheck = new QRadioButton(tr("Random Walk"));

    rastercheck->setChecked(true);
    QPushButton *alignbutton = new QPushButton(tr("&Align!"));
    connect(alignbutton, SIGNAL (released()), this, SLOT (alignbuttonPress()));

    QPushButton *stopButton = new QPushButton(tr("&Stop"));
    stopButton->setCheckable(true);
    stopButton->setChecked(false);
    connect(stopButton, SIGNAL (released()), this, SLOT (stopButtonPress()));

    QLabel *title = new QLabel();
    title->setText("Speed Selection");

    QSlider *speed = new QSlider(Qt::Horizontal);
    speed->setMaximum(100);
    speed->setMinimum(0);
    speed->setTickInterval(10);
    speed->setTickPosition(QSlider::TicksBothSides);
    connect(speed,SIGNAL(valueChanged(int)), SLOT(speedChange(int)));


    QLabel *title2 = new QLabel();
    title2->setText("Duration Selection");

    QSlider *duration = new QSlider(Qt::Horizontal);
    duration->setMaximum(100);
    duration->setMinimum(0);
    duration->setTickInterval(10);
    duration->setTickPosition(QSlider::TicksBothSides);
    connect(duration,SIGNAL(valueChanged(int)), SLOT(durationChange(int)));






    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(rastercheck);
    vbox->addWidget(gradientcheck);
    vbox->addWidget(randomcheck);
    vbox->addWidget(alignbutton);
    vbox->addWidget(stopButton);
    vbox->addWidget(title);
    vbox->addWidget(speed);
    vbox->addWidget(title2);
    vbox->addWidget(duration);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Window::createPhotodiodeSelection()
{
    QGroupBox *groupBox = new QGroupBox(tr("Photodiode Selection"));

    QRadioButton *photo1select = new QRadioButton(tr("&Photodiode 1"));
    QRadioButton *photo2select = new QRadioButton(tr("&Photodiode 2"));
    QPushButton *measure = new QPushButton(tr("&Measure"));
    connect(measure, SIGNAL (released()), this, SLOT (measurePress()));
    QLabel *display = new QLabel();
    display->setText("");
    photo1select->setChecked(true);

    QLabel *title3 = new QLabel();
    title3->setText("Raster Threshold");

    QSlider *threshold = new QSlider(Qt::Horizontal);
    threshold->setMaximum(256);
    threshold->setMinimum(0);
    threshold->setTickInterval(10);
    threshold->setTickPosition(QSlider::TicksBothSides);
    connect(threshold,SIGNAL(valueChanged(int)), SLOT(thresholdChange(int)));






    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(photo1select);
    vbox->addWidget(photo2select);
    vbox->addWidget(measure);
    vbox->addWidget(display);
    vbox->addWidget(title3);
    vbox->addWidget(threshold);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Window::createSecondExclusiveGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("E&xclusive Radio Buttons"));
    groupBox->setCheckable(true);
    groupBox->setChecked(false);

    QRadioButton *radio1 = new QRadioButton(tr("Rad&io button 1"));
    QRadioButton *radio2 = new QRadioButton(tr("Radi&o button 2"));
    QRadioButton *radio3 = new QRadioButton(tr("Radio &button 3"));
    radio1->setChecked(true);
    QCheckBox *checkBox = new QCheckBox(tr("Ind&ependent checkbox"));
    checkBox->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(checkBox);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Window::createNonExclusiveGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Non-Exclusive Checkboxes"));
    groupBox->setFlat(true);

    QCheckBox *checkBox1 = new QCheckBox(tr("&Checkbox 1"));
    QCheckBox *checkBox2 = new QCheckBox(tr("C&heckbox 2"));
    checkBox2->setChecked(true);
    QCheckBox *tristateBox = new QCheckBox(tr("Tri-&state button"));
    tristateBox->setTristate(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(checkBox1);
    vbox->addWidget(checkBox2);
    vbox->addWidget(tristateBox);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Window::createPushButtonGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("&Manual Servo Control"));
    groupBox->setCheckable(true);
    groupBox->setChecked(true);

    QPushButton *gpio5left = new QPushButton(tr("&Motor (5) Left"));
    QPushButton *gpio5right = new QPushButton(tr("&Motor (5) Right"));
    connect(gpio5left, SIGNAL (released()), this, SLOT (gpio5leftPress()));
    connect(gpio5right, SIGNAL (released()), this, SLOT (gpio5rightPress()));

    QPushButton *gpio6left = new QPushButton(tr("&Motor (6) Left"));
    QPushButton *gpio6right = new QPushButton(tr("&Motor (6) Right"));
    connect(gpio6left, SIGNAL (released()), this, SLOT (gpio6leftPress()));
    connect(gpio6right, SIGNAL (released()), this, SLOT (gpio6rightPress()));

    QPushButton *gpio13left = new QPushButton(tr("&Motor (13) Left"));
    QPushButton *gpio13right = new QPushButton(tr("&Motor (13) Right"));
    connect(gpio13left, SIGNAL (released()), this, SLOT (gpio13leftPress()));
    connect(gpio13right, SIGNAL (released()), this, SLOT (gpio13rightPress()));

    QPushButton *gpio19left = new QPushButton(tr("&Motor (19) Left"));
    QPushButton *gpio19right = new QPushButton(tr("&Motor (19) Right"));
    connect(gpio19left, SIGNAL (released()), this, SLOT (gpio19leftPress()));
    connect(gpio19right, SIGNAL (released()), this, SLOT (gpio19rightPress()));


    QVBoxLayout *vbox = new QVBoxLayout;

    vbox->addWidget(gpio5left);
    vbox->addWidget(gpio5right);
    vbox->addWidget(gpio6left);
    vbox->addWidget(gpio6right);
    vbox->addWidget(gpio13left);
    vbox->addWidget(gpio13right);
    vbox->addWidget(gpio19left);
    vbox->addWidget(gpio19right);

    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Window::createFlipControlGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("&Manual Photodiode Control"));
    groupBox->setCheckable(true);
    groupBox->setChecked(true);

    QPushButton *photodiode1in = new QPushButton(tr("&Flip In Photodiode 1"));
    QPushButton *photodiode1out = new QPushButton(tr("&Flip Out Photodiode 1"));
    connect(photodiode1in, SIGNAL (released()), this, SLOT (photodiode1inPress()));
    connect(photodiode1out, SIGNAL (released()), this, SLOT (photodiode1outPress()));

    QPushButton *photodiode2in = new QPushButton(tr("&Flip In Photodiode 2"));
    QPushButton *photodiode2out = new QPushButton(tr("&Flip Out Photodiode 2"));
    connect(photodiode2in, SIGNAL (released()), this, SLOT (photodiode2inPress()));
    connect(photodiode2out, SIGNAL (released()), this, SLOT (photodiode2outPress()));

    QPushButton *lensIn = new QPushButton(tr("Lens In"));
    QPushButton *lensOut = new QPushButton(tr("&Lens Out"));
    connect(lensIn, SIGNAL (released()), this, SLOT (lensInPress()));
    connect(lensOut, SIGNAL (released()), this, SLOT (lensOutPress()));


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(photodiode1in);
    vbox->addWidget(photodiode1out);
    vbox->addWidget(photodiode2in);
    vbox->addWidget(photodiode2out);
    vbox->addWidget(lensIn);
    vbox->addWidget(lensOut);

    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

// == PRIVATE SLOTS ==
void Window::photodiode1inPress()
{
   std::system("./fixedup 22");
}
void Window::photodiode1outPress()
{
   std::system("./fixeddown 22");
}
void Window::photodiode2inPress()
{
   std::system("./fixedup 17");
}
void Window::photodiode2outPress()
{
   std::system("./fixeddown 17");
}
void Window::lensInPress()
{
   std::system("./fixedup 27");
}
void Window::lensOutPress()
{
   std::system("./fixeddown 27");
}




void Window::measurePress()
{
    std::system("./gogo");
    readfile();

}



void Window::gpio5rightPress()
{

    QString a = "./MoveRight 5 " + QString::number(currentspeed) + " " + QString::number(currentduration);
    QByteArray conv = a.toLatin1();
    const char *c_str2 = conv.data();
    std::system(c_str2);

}
void Window::gpio5leftPress()
{
    QString a = "./MoveLeft 5 " + QString::number(currentspeed) + " " + QString::number(currentduration);
    QByteArray conv = a.toLatin1();
    const char *c_str2 = conv.data();
    std::system(c_str2);
}
void Window::gpio6rightPress()
{
    QString a = "./MoveRight 6 " + QString::number(currentspeed) + " " + QString::number(currentduration);
    QByteArray conv = a.toLatin1();
    const char *c_str2 = conv.data();
    std::system(c_str2);
}
void Window::gpio6leftPress()
{
    QString a = "./MoveLeft 6 " + QString::number(currentspeed) + " " + QString::number(currentduration);
    QByteArray conv = a.toLatin1();
    const char *c_str2 = conv.data();
    std::system(c_str2);
}
void Window::gpio13rightPress()
{
    QString a = "./MoveRight 13 " + QString::number(currentspeed) + " " + QString::number(currentduration);
    QByteArray conv = a.toLatin1();
    const char *c_str2 = conv.data();
    std::system(c_str2);
}
void Window::gpio13leftPress()
{
    QString a = "./MoveLeft 13 " + QString::number(currentspeed) + " " + QString::number(currentduration);
    QByteArray conv = a.toLatin1();
    const char *c_str2 = conv.data();
    std::system(c_str2);
}
void Window::gpio19rightPress()
{
    QString a = "./MoveRight 19 " + QString::number(currentspeed) + " " + QString::number(currentduration);
    QByteArray conv = a.toLatin1();
    const char *c_str2 = conv.data();
    std::system(c_str2);
}
void Window::gpio19leftPress()
{
    QString a = "./MoveLeft 19 " + QString::number(currentspeed) + " " + QString::number(currentduration);
    QByteArray conv = a.toLatin1();
    const char *c_str2 = conv.data();
    std::system(c_str2);
}



void Window::alignbuttonPress()
{
    stoppage = false;
    std::system("./fixedup 22");
    std::system("./fixedup 27");
    for(int counter = 0; counter <= 10; counter++){
        if (stoppage == false) {
            std::system("./gogo");
            readfile();
            value0 = reading;


            QString a = "./MoveLeft 13 " + QString::number(currentspeed) + " " + QString::number(currentduration);
            QByteArray conv = a.toLatin1();
            const char *c_str2 = conv.data();
            std::system(c_str2);
            std::system("./gogo");
            readfile();
            value1 = reading;

            a = "./MoveRight 13 " + QString::number(currentspeed) + " " + QString::number(currentduration);
            conv = a.toLatin1();
            c_str2 = conv.data();
            std::system(c_str2);
            a = "./MoveRight 13 " + QString::number(currentspeed) + " " + QString::number(currentduration);
            conv = a.toLatin1();
            c_str2 = conv.data();
            std::system(c_str2);
            std::system("./gogo");
            readfile();
            value2 = reading;

            a = "./MoveLeft 13 " + QString::number(currentspeed) + " " + QString::number(currentduration);
            conv = a.toLatin1();
            c_str2 = conv.data();
            std::system(c_str2);
            a = "./MoveLeft 19 " + QString::number(currentspeed) + " " + QString::number(currentduration);
            conv = a.toLatin1();
            c_str2 = conv.data();
            std::system(c_str2);
            std::system("./gogo");
            readfile();
            value3 = reading;

            a = "./MoveRight 19 " + QString::number(currentspeed) + " " + QString::number(currentduration);
            conv = a.toLatin1();
            c_str2 = conv.data();
            std::system(c_str2);
            a = "./MoveRight 19 " + QString::number(currentspeed) + " " + QString::number(currentduration);
            conv = a.toLatin1();
            c_str2 = conv.data();
            std::system(c_str2);
            std::system("./gogo");
            readfile();
            value4 = reading;
            a = "./MoveLeft 19 " + QString::number(currentspeed) + " " + QString::number(currentduration);
            conv = a.toLatin1();
            c_str2 = conv.data();
            std::system(c_str2);


            if ((value0 >= value1) && (value0 >= value2) && (value0 >= value3) && (value0 >= value4)){
                stoppage = true;
            }

            if ((value1 >= value2) && (value1 >= value3) && (value1 >= value4)){
                QString a = "./MoveLeft 13 " + QString::number(currentspeed) + " " + QString::number(currentduration);
                QByteArray conv = a.toLatin1();
                const char *c_str2 = conv.data();
                std::system(c_str2);
            }
            if ((value2 >= value3) && (value2 >= value4)){
                QString a = "./MoveRight 13 " + QString::number(currentspeed) + " " + QString::number(currentduration);
                QByteArray conv = a.toLatin1();
                const char *c_str2 = conv.data();
                std::system(c_str2);
            }
            if ((value3 >= value4)){
                QString a = "./MoveLeft 19 " + QString::number(currentspeed) + " " + QString::number(currentduration);
                QByteArray conv = a.toLatin1();
                const char *c_str2 = conv.data();
                std::system(c_str2);
            }
            if ((value4 > value3)){
                QString a = "./MoveRight 19 " + QString::number(currentspeed) + " " + QString::number(currentduration);
                QByteArray conv = a.toLatin1();
                const char *c_str2 = conv.data();
                std::system(c_str2);
            }
        }
    }



 }


void Window::readfile()
{
    QString filename="test.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "Error reading from photodiode "<<filename;
    }else{
        qDebug() << filename<<" Reading...";
    }
    QString line;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();

            qDebug() << "Line: "<<line;
        }
    }
    file.close();



    reading = line.toInt();



}

void Window::stopButtonPress(){

}
void Window::thresholdChange(int Value){

    PhotoThresh = Value;


}

void Window::speedChange(int Value){

    currentspeed = Value;



}

void Window::durationChange(int Value){

    currentduration = Value;


}







