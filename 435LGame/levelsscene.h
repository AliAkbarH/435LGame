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

#include "river.h"
#include "popeye.h"
#include "locks.h"
#include "levels.h"
#include "spinach.h"
#include "boat.h"
#include "rock.h"
#include "riverobstacle.h"
#include "smallriver.h"


/**
* \file game1scene.hB
* \brief The Game's scene
*
* This is the header file for our first game's scene. It publicly inherits from QGraphicsScene.
*/

class levelsscene : public QGraphicsScene
{
    Q_OBJECT
public:
    levelsscene(QString user);

    QString user;    


    Popeye *popeye = new Popeye();       //!< Creating the references to the Objects
    spinach *spinach1 = new spinach();
    spinach *spinach2 = new spinach();
    spinach *spinach3 = new spinach();

    river *river1 = new river();

    boat *boat1 = new boat();

    rock *rock1 = new rock();

    riverObstacle *obstacle = new riverObstacle;

    smallRiver *smallRiver1 = new smallRiver();
    smallRiver *smallRiver2 = new smallRiver();

    levels *l;

    QPushButton *run, *hint, *pause, *retry, *proceed;
    QTextEdit *text;
    QLabel *instructions;

    QTimer *timer;
    QGraphicsTextItem *timerPreview;

    void looseLife();
    void gameOver();

    void levelssceneTimer();

    void youLost();

    void youWon();
    
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
        void hideScene();


};

#endif
