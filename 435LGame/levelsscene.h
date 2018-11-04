#ifndef LEVELSSCENE_H
#define LEVELSSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QtEvents>
#include <QTimer>
#include <QtWidgets>
#include <QString>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QApplication>

#include "popeye.h"
#include "locks.h"
#include "levels.h"
#include "spinach.h"

/**
* \file game1scene.h
* \brief The Game's scene
*
* This is the header file for our first game's scene. It publicly inherits from QGraphicsScene.
*/

class levelsscene : public QGraphicsScene
{
    Q_OBJECT
public:
    levelsscene(QString s);

    QString user;    

    Popeye *popeye = new Popeye();       //!< Creating the references to the Objects
    spinach *spinach1 = new spinach();
    spinach *spinach2 = new spinach();
    spinach *spinach3 = new spinach();

    levels *l;

    QPushButton *run, *hint, *pause, *retry;
    QTextEdit *text;
    QLabel *instructions;

    QTimer *timer;
    QGraphicsTextItem *timerPreview;

    void looseLife();
    void gameOver();

    void levelssceneTimer();

    void youLost();
    
    //void updatePosition();                /**< function that will update the position of popeye*/


private:
        bool fileExists(QString path);
        int getLevel();
        QStringList profileParser(QString in);

signals:

public slots:
        void checkAnswer();
        void displayHint();
        void pauseLevel();
        void retryLevel();
};

#endif // LEVELSSCENE_H
