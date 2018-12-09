/**
* \file qualitycontrolicon.cpp
* \brief Contains QualityControlIcon Class definitions
* \author Ali Al Akbar Haidoura
  */
#include "qualitycontrolicon.h"

QualityControlIcon::QualityControlIcon()
{
    icon=new QPixmap(":/game2 images/quality.png");
    setPixmap((*icon).scaledToHeight(80));
}
