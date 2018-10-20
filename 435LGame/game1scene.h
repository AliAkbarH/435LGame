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

    game1scene();                       //!< Default constructor
    QPushButton *start;

    void updatePosition();                /**< function that will update the position of popeye, placing him on top of the locks*/

public slots:
    void starLevel();
};

#endif // GAME1SCENE_H