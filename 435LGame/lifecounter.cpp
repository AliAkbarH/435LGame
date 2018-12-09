/**
* \file lifecounter.cpp
* \brief Contains LifeCounter Class definitions
* \author Ali Al Akbar Haidoura
  */
#include "lifecounter.h"

LifeCounter::LifeCounter(int life)
{
    QString path(":/game2 images/live"+QString::number(life)+".png");
    QPixmap icon(path);
    setPixmap(icon.scaledToHeight(100));
}
