#include "minibug.h"
#include "bullet.h"

miniBug::miniBug(Game2Scene *scene, Bug *bug, int dir)
{
    this->scene=scene;
    this->bug=bug;
    icon=new QPixmap(":/game2 images/bug.png");
    *icon=icon->scaledToHeight(20);
    setPixmap(*icon);
    timer=new QTimer();
    timer->start(50);
    steps=0;
    this->dir=dir;

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
}

void miniBug::move(){
    if(steps<40){


    if(dir==1){
        moveBy(-5,0);
    }
    else{
        moveBy(5,0);
    }
    steps++;
    QList<QGraphicsItem*> colliding=collidingItems();
    if(!colliding.isEmpty() && dynamic_cast<Bullet*>(colliding.at(0))==NULL && dynamic_cast<Bug*>(colliding.at(0))==NULL){
        if(dynamic_cast<Tester*>(colliding.at(0))!=NULL && !scene->hasShield){
            dynamic_cast<Tester*>(colliding.at(0))->decrementLives();
            scene->updateLifeScore();
        }
        delete this;
    }
    }
    else{
        delete this;
    }
}
