#include "game2scene.h"
#include "levelparser.h"
#include"bug.h"
#include"wall.h"
#include"coffeecup.h"
#include"qualitycontrolicon.h"
#include"testingicon.h"
#include"shield.h"
#include"bullet.h"
#include <QDebug>

Game2Scene::Game2Scene(QString user)
{
    dir=0;
    this->user=user;
    setSceneRect(0,0,1280,640);
    setBackgroundBrush(QBrush(QImage(":/game2 images/background.jpg").scaledToHeight(640).scaledToWidth(1280)));

    LevelParser parser(":/game2 images/level1.txt");
    parser.parse(this);


}

void Game2Scene::keyPressEvent(QKeyEvent *event){

    int prevX=tester->x(),prevY=tester->y();
    int newX=prevX,newY=prevY;
    if(event->key()==Qt::Key_Right && tester->x()<=1240){
        newX=prevX+40;
        newY=prevY;
        dir=0;
    }
    if(event->key()==Qt::Key_Left && tester->x()>=40){
        newX=prevX-40;
        newY=prevY;
        dir=2;
    }
    if(event->key()==Qt::Key_Up && tester->y()>=40){
        newX=prevX;
        newY=prevY-40;
        dir=1;
    }
    if(event->key()==Qt::Key_Down && tester->y()<=600){
        newX=prevX;
        newY=prevY+40;
        dir=3;
    }
    if(event->key()==Qt::Key_Space){
        Bullet *bullet=new Bullet(dir,tester->x(),tester->y());
        addItem(bullet);
    }
    tester->setPos(newX,newY);
    QList<QGraphicsItem*> colliding=tester->collidingItems();
    if(!colliding.isEmpty()){
        if(dynamic_cast<Wall*>(colliding.at(0))!=NULL){
            newX=prevX;
            newY=prevY;
        }
    }

    tester->setPos(newX,newY);



}
