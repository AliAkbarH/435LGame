#include "bug.h"

Bug::Bug()
{

    icon=new QPixmap(":/game2 images/bug.png");
    *icon=icon->scaledToHeight(40);
    setPixmap(*icon);

    lives=3;
    dir=0;
    i=2;
    timer->start(500);
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
        moveBy(40,0);
    }
    else{
        moveBy(-40,0);
    }
    i++;
    i=i%5;
    if(i==0){
        dir++;
        dir=dir%2;
    }

}
