/**
* \file shield.cpp
* \brief Contains shield Class definitions
* \author Ali Al Akbar Haidoura
  */
#include "shield.h"

Shield::Shield()
{
    icon=new QPixmap(":/game2 images/shield.png");

    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
}
