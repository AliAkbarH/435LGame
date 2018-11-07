#include "riverobstacle.h"
#include <QGraphicsPixmapItem>

/**
* \file boat.cpp
* \brief contains boat class definition
*
*
* \author
*/

riverObstacle::riverObstacle(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/Profile Images/level6.jpg")));
}
