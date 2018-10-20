#ifndef LEVELSSCENE_H
#define LEVELSSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QtEvents>
#include <QTimer>
#include <QtWidgets>
#include "popeye.h"
#include "locks.h"
#include "spinach.h"
#include "levels.h"

/**
* \file game1scene.h
* \brief The Game's scene
*
* This is the header file for our first game's scene. It publicly inherits from QGraphicsScene.
*/

class levelsScene : public QGraphicsScene
{
    Q_OBJECT

public:

    Popeye *popeye = new Popeye();      //!< Creating the references to the Objects that we want to place on the scene
    spinach *foodCan = new spinach();

    levelsScene(levels level);                      //!< Default constructor
    QPushButton *run, *hint;
    QTimer *timer1;                     //!< Pointer to QTimer

    QTextEdit *text;
    QLabel *instructionBox, *levelNumber;



public slots:

};

#endif // LEVELSSCENE_H
