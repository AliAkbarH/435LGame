#include "bullet.h"
#include"wall.h"
#include"bug.h"

Bullet::Bullet(int direction, int x, int y)
{
    icon=new QPixmap(":/game2 images/bullet.png");
    *icon=icon->scaledToWidth(40);
    this->direction=direction;
    setPixmap(*icon);
    setPos(x,y);
    step=0;
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(200);
}

void Bullet::move(){
    if(step<3){
        switch(direction){
        case 0:
            setPos(this->x()+40,this->y());
            break;
        case 1:
            setPos(this->x(),this->y()-40);
            break;
        case 2:
            setPos(this->x()-40,this->y());
            break;
        case 3:
            setPos(this->x(),this->y()+40);
            break;

        }
        step++;
        QList<QGraphicsItem*> colliding=collidingItems();
        if(!colliding.isEmpty()){
            if(dynamic_cast<Bug*>(colliding.at(0))!=NULL){
                dynamic_cast<Bug*>(colliding.at(0))->decrementLives();
            }
            delete this;
        }
    }
    else{
        delete this;
    }
}


