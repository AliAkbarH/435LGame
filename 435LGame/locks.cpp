#include "locks.h"
#include <QGraphicsPixmapItem>

/**
* \file locks.cpp
* \brief contains Lock class definition
*
*
* \author Camille Farhat
*/

locks::locks(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/Profile Images/Lock.png")).scaled(70,70));
}
