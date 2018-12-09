/**
* \file testingicon.cpp
* \brief Contains testingIcon Class definitions
* \author Ali Al Akbar Haidoura
  */
#include "testingicon.h"

TestingIcon::TestingIcon()
{
    icon=new QPixmap(":/game2 images/test.png");

    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
    isHidden=false;
    timer =new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(reActivate()));
}

void TestingIcon::deActivate(){
    isHidden=true;
    hide();
    timer->start(10000);
}

void TestingIcon::reActivate(){
    isHidden=false;
    show();
    timer->stop();
}
