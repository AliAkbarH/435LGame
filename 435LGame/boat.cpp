#include "boat.h"
#include <QGraphicsPixmapItem>

/**
* \file boat.cpp
* \brief contains boat class definition
*
*
* \author
*/

boat::boat(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/Profile Images/Boat.jpg")));
}
