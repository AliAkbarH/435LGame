#include "popeye.h"

/**
* \file popeye.cpp
* \brief contains Popeye class definition
*
*
* \author Camille Farhat
*/

Popeye::Popeye(QObject *parent) : QObject(parent)
{
   setPixmap((QPixmap(":/Profile Images/Popeye.png")).scaled(75,75));
}

