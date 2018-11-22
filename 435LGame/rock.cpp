#include "rock.h"
#include <QGraphicsPixmapItem>

/**
* \file rock.cpp
* \brief contains rock class definition
* \author Camille Farhat & Ali Haidar
*/

/*! \brief Setting the rock's Image
*/
rock::rock(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/Profile Images/rubble-md.png")).scaled(150,150));
}
