#include "bullet.h"
#include"wall.h"
#include"bug.h"
#include"minibug.h"
#include<QTransform>

Bullet::Bullet(int direction, int x, int y, Game2Scene *scene)
{
    this->scene=scene;
    icon=new QPixmap(":/game2 images/bullet.png");
    *icon=icon->scaledToWidth(40);
    this->direction=direction;
    QTransform transform;
    //setPixmap(*icon);
    switch(direction){
    case 0:
        setPos(x+40,y);
        setPixmap(*icon);
        break;
    case 1:
        setPos(x,y-40);
        setPixmap(icon->transformed(transform.rotate(270)));
        break;
    case 2:
        setPos(x-40,y);
        setPixmap(icon->transformed(transform.rotate(180)));
        break;
    case 3:
        setPos(x,y+40);
        setPixmap(icon->transformed(transform.rotate(90)));
        break;
    }
    step=0;
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);
}

void Bullet::move(){
    if(step<70){
        switch(direction){
        case 0:
            setPos(this->x()+4,this->y());
            break;
        case 1:
            setPos(this->x(),this->y()-4);
            break;
        case 2:
            setPos(this->x()-4,this->y());
            break;
        case 3:
            setPos(this->x(),this->y()+4);
            break;

        }
        step++;
        QList<QGraphicsItem*> colliding=collidingItems();
        if(!colliding.isEmpty() && dynamic_cast<miniBug*>(colliding.at(0))==NULL){
            if(dynamic_cast<Bug*>(colliding.at(0))!=NULL){
                if(dynamic_cast<Bug*>(colliding.at(0))->lives==1){
                    scene->bugs--;
                }
                dynamic_cast<Bug*>(colliding.at(0))->decrementLives();

            }
            delete this;
        }
    }
    else{
        delete this;
    }
}


