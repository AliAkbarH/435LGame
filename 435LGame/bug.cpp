/**
*\file bug.cpp
*\brief contains Bug class definitions
* \author Ali Al Akbar Haidoura
*/

#include "bug.h"
#include"tester.h"
#include"minibug.h"
#include<QTransform>

Bug::Bug(Game2Scene *scene)
{

    icon=new QPixmap(":/game2 images/bug.png");
    *icon=icon->scaledToHeight(40);
    setPixmap(*icon);
    this->scene=scene;
    dir=qrand()%2;
    lives=3;
    i=20;
    timer=new QTimer();
    shootingTimer=new QTimer();
    timer->start(125);
    shootingTimer->start(800);
    connect(timer,SIGNAL(timeout()),this,SLOT(guard()));
    connect(shootingTimer,SIGNAL(timeout()),this,SLOT(shoot()));


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
        moveBy(5,0);
    }
    else{
        moveBy(-5,0);
    }
    i++;
    i=i%41;
    if(i==0){
        dir++;
        dir=dir%2;
    }


}


void Bug::shoot(){

    if(dir==0){
        moveBy(70,0);
        QList<QGraphicsItem*> colliding=collidingItems();
        if(!colliding.isEmpty() && dynamic_cast<Tester*>(colliding.at(0))!=NULL){
            miniBug *MiniBug=new miniBug(scene,this,dir);
            MiniBug->setPos(this->x()-25,this->y()+10);
            scene->addItem(MiniBug);
        }
        moveBy(70,0);
        colliding=collidingItems();
        if(!colliding.isEmpty() && dynamic_cast<Tester*>(colliding.at(0))!=NULL){
            miniBug *MiniBug=new miniBug(scene,this,dir);
            MiniBug->setPos(this->x()-95,this->y()+10);
            scene->addItem(MiniBug);
        }
        moveBy(70,0);
        colliding=collidingItems();
        if(!colliding.isEmpty() && dynamic_cast<Tester*>(colliding.at(0))!=NULL){
            miniBug *MiniBug=new miniBug(scene,this,dir);
            MiniBug->setPos(this->x()-165,this->y()+10);
            scene->addItem(MiniBug);
        }

        moveBy(-210,0);
    }
    else{
        moveBy(-70,0);
        QList<QGraphicsItem*> colliding=collidingItems();
        if(!colliding.isEmpty() && dynamic_cast<Tester*>(colliding.at(0))!=NULL){
            miniBug *MiniBug=new miniBug(scene,this,dir);
            MiniBug->setPos(this->x()+65,this->y()+10);
            scene->addItem(MiniBug);
        }
        moveBy(-70,0);
        colliding=collidingItems();
        if(!colliding.isEmpty() && dynamic_cast<Tester*>(colliding.at(0))!=NULL){
            miniBug *MiniBug=new miniBug(scene,this,dir);
            MiniBug->setPos(this->x()+135,this->y()+10);
            scene->addItem(MiniBug);
        }
        moveBy(-70,0);
        colliding=collidingItems();
        if(!colliding.isEmpty() && dynamic_cast<Tester*>(colliding.at(0))!=NULL){
            miniBug *MiniBug=new miniBug(scene,this,dir);
            MiniBug->setPos(this->x()+205,this->y()+10);
            scene->addItem(MiniBug);
        }
        moveBy(210,0);
    }
}

void Bug::pause(){

    timer->stop();
    shootingTimer->stop();
}

void Bug::resume(){
    timer->start(125);
    shootingTimer->start(800);
}
