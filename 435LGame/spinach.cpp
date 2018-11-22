#include "spinach.h"
#include <QObject>

/**
* \file spinach.cpp
* \brief Contains Spinach class definition
* \author Camille Farhat & Ali Haidar
*/

/*! \brief Setting the spinach can's Image
*/
spinach::spinach(QObject *parent) : QObject(parent)
{
   setPixmap((QPixmap(":/Profile Images/popeye_s_spinach_by_can.png")).scaled(65,65));
}
