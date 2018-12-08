#include "river.h"
#include <QGraphicsPixmapItem>

/**
* \file river.cpp
* \brief Contains river class definition
*
*
* \author Camille Farhat & Ali Haidoura
*/

/*! \brief Setting the river's Image
*/
river::river(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/Profile Images/River.jpg")));
}
