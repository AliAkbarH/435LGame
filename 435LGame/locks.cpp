#include "locks.h"
#include <QGraphicsPixmapItem>

/**
* \file locks.cpp
* \brief Contains Lock class definition
*
*
* \author Camille Farhat & Ali Haidar
*/

/*! \brief Setting the lock Image
*/
locks::locks(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/Profile Images/Lock.png")).scaled(70,70));
}
