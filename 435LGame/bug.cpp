#include "bug.h"

Bug::Bug()
{

    icon=new QPixmap(":/game2 images/bug.png");
    *icon=icon->scaledToHeight(40);
    setPixmap(*icon);

    lives=3;
    dir=0;
    i=12;
    timer=new QTimer();
    timer->start(125);
    connect(timer,SIGNAL(timeout()),this,SLOT(guard()));
}

void Bug::decrementLives(){
    lives--;
    setPixmap(icon->scaledToHeight(icon->height()-10));
    moveBy(5,5);
    if(lives==0){
        delete this;
    }
}

void Bug::guard(){
    if(dir==0){
        moveBy(8,0);
    }
    else{
        moveBy(-8,0);
    }
    i++;
    i=i%25;
    if(i==0){
        dir++;
        dir=dir%2;
    }

}
