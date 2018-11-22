#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QtEvents>
#include <QTimer>
#include <QtWidgets>
#include "popeye.h"
#include "locks.h"
#include "levelsscene.h"

/**
* \file game1scene.h
* \brief The Game's scene
*
* This is the header file for our first game's scene. It publicly inherits from QGraphicsScene.
*/

class game1scene : public QGraphicsScene
{
    Q_OBJECT

public:

    Popeye *popeye = new Popeye();       //!< Creating the references to the Objects
    locks *lock1 = new locks();
    locks *lock2 = new locks();
    locks *lock3 = new locks();
    locks *lock4 = new locks();
    locks *lock5 = new locks();
    locks *lock6 = new locks();
    locks *lock7 = new locks();
    locks *lock8 = new locks();

    game1scene(QString user);              //!< Default constructor
    QPushButton *start;
    QString user;
    
    levelsscene *scene2;                   //!< pointer to an Object of type levelsscene
    QGraphicsView *view2;                  //!< pointer to an Object of type QGraphicsView
    
    void updatePosition1();                //!< update the position of popeye, placing him on top of the locks for level 1
    void updatePosition2();                //!< update the position of popeye, placing him on top of the locks for level 2
    void updatePosition3();                //!< update the position of popeye, placing him on top of the locks for level 3
    void updatePosition4();                //!< update the position of popeye, placing him on top of the locks for level 4
    void updatePosition5();                //!< update the position of popeye, placing him on top of the locks for level 5
    void updatePosition6();                //!< update the position of popeye, placing him on top of the locks for level 6
    void updatePosition7();                //!< update the position of popeye, placing him on top of the locks for level 7
    void updatePosition8();                //!< update the position of popeye, placing him on top of the locks for level 8
    void hideLevelScene();                 //!< update the position of popeye, placing him on top of the locks for level 1

    int getLevel();                             //!< get the user's level from the text file
    QStringList profileParser(QString line);    //!< get a list of string when parsing from text file the attributes that are seprated by spaces

    QGraphicsTextItem *countDownText;
    int countdown = 12000;                //! < value of the countdown at the start of the game that is = to 120 i.e. 20 mins to reach Olive
    QTimer *countdownTimer;             //! < Timer controlling the countdown
    void setUpCountdownTimer();         //!< Setting up the timer

public slots:
    void startLevel();                          //!<start the appropriate level
    void updateCountdownTimer();//!<Function that will update the timer and then display it


};

#endif // GAME1SCENE_H
