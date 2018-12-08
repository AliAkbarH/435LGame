#include "boat.h"

/**
* \file boat.cpp
* \brief Contains Popeye class definition
*
*
* \author Camille Farhat & Ali Haidoura
*/

/*! \brief Setting Popeye's Image
*/
boat::boat(QObject *parent) : QObject(parent)
{
   setPixmap((QPixmap(":/Profile Images/Boat.jpg")));
}
