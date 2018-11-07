#include "smallriver.h"
#include <QGraphicsPixmapItem>

/**
* \file smallriver.cpp
* \brief contains boat class definition
*
*
* \author
*/

smallRiver::smallRiver(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/Profile Images/smallRiver.jpg")));
}
