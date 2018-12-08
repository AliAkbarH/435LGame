#include "smallriver.h"
#include <QGraphicsPixmapItem>

/**
* \file smallriver.cpp
* \brief contains Small River class definition
* \author Camille Farhat & Ali Haidoura
*/

/*! \brief Setting the small river's Image
*/
smallRiver::smallRiver(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/Profile Images/smallRiver.jpg")));
}
