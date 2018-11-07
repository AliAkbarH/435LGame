#include "spinach.h"
#include <QObject>

/**
* \file spinach.cpp
* \brief contains spinach class definition
*
*
* \author
*/

spinach::spinach(QObject *parent) : QObject(parent)
{
   setPixmap((QPixmap(":/Profile Images/popeye_s_spinach_by_can.png")).scaled(65,65));
}
