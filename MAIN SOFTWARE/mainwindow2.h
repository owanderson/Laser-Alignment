/*
 * How to create an application with Qt and C++
 *
 * example code of blog post: http://blog.davidecoppola.com/2016/10/how-to-create-an-application-with-qt-and-cpp/
 *
*/

#pragma once

#include <QMainWindow>
#include <QGroupBox>
#include <QTextEdit>
#include <QString>
#include <QLabel>
#include <QSlider>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget * parent = 0);
    int reading;
    int PhotoThresh;
    int value0;
    int value1;
    int value2;
    int value3;
    int value4;
    int currentspeed;
    int currentduration;
    bool stoppage;
    QLabel *display;
    QSlider *threshold;



private:
    QGroupBox *createFirstExclusiveGroup();
    QGroupBox *createSecondExclusiveGroup();
    QGroupBox *createNonExclusiveGroup();
    QGroupBox *createPushButtonGroup();
    QGroupBox *createFlipControlGroup();
    QGroupBox *createPhotodiodeSelection();



private slots:
    void photodiode1inPress();
    void photodiode1outPress();
    void photodiode2inPress();
    void photodiode2outPress();

    void measurePress();

    void gpio5rightPress();
    void gpio5leftPress();
    void gpio6rightPress();
    void gpio6leftPress();
    void gpio13rightPress();
    void gpio13leftPress();
    void gpio19rightPress();
    void gpio19leftPress();

    void readfile();

    void alignbuttonPress();
    void stopButtonPress();

    void lensInPress();
    void lensOutPress();

    void thresholdChange(int);
    void durationChange(int);
    void speedChange(int);








};
