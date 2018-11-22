#include "riverobstacle.h"
#include <QGraphicsPixmapItem>

/**
* \file riverobstacle.cpp
* \brief Contains River Obstacle class definition
*
*
* \author Camille Farhat & Ali Haidar
*/

/*! \brief Setting the river obstacle's Image
*/
riverObstacle::riverObstacle(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/Profile Images/level6.jpg")));
}
