#include "river.h"
#include <QGraphicsPixmapItem>

/**
* \file river.cpp
* \brief contains river class definition
*
*
* \author
*/

river::river(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/Profile Images/River.jpg")));
}
