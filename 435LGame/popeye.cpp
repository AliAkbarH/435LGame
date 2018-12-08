#include "popeye.h"

/**
* \file popeye.cpp
* \brief Contains Popeye class definition
*
*
* \author Camille Farhat & Ali Haidoura
*/

/*! \brief Setting Popeye's Image
*/
Popeye::Popeye(QObject *parent) : QObject(parent)
{
   setPixmap((QPixmap(":/Profile Images/Popeye.png")).scaled(75,75));
}

