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

    game1scene(QString user);                       //!< Default constructor
    QPushButton *start;
    QString user;
    
    levelsscene *scene2;                     //!< pointer to an Object of type levelsscene
    QGraphicsView *view2;                   //!< pointer to an Object of type QGraphicsView
    
    void updatePosition1();                /**< function that will update the position of popeye, placing him on top of the locks*/
    void updatePosition2();
    void updatePosition3();
    void updatePosition4();
    void updatePosition5();
    void updatePosition6();
    void updatePosition7();
    void updatePosition8();
    void hideLevelScene();
    int getLevel();
    QStringList profileParser(QString line);

public slots:
    void startLevel();

};

#endif // GAME1SCENE_H
