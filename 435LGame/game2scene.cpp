#include "game2scene.h"
#include "levelparser.h"
#include <QDebug>

Game2Scene::Game2Scene(QString user)
{
    QDir dir;
    this->user=user;
    setSceneRect(0,0,1280,640);
    setBackgroundBrush(QBrush(QImage(dir.absolutePath()+"/game2 images/background.jpg").scaledToHeight(640).scaledToWidth(1280)));

    LevelParser parser(dir.absolutePath()+"/game2 images/level1.txt");
    parser.parse(this);
//    tester->setFlag(QGraphicsItem::ItemIsFocusable);
//    tester->setFocus();
//    if(tester->hasFocus()){
//        qDebug()<<"focused";
//    }
//    else{
//        qDebug()<<"not focused";

//    }

}

void Game2Scene::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Right && tester->x()<=1240){
        tester->setPos(tester->x()+40,tester->y());
    }
    if(event->key()==Qt::Key_Left && tester->x()>=40){
        tester->setPos(tester->x()-40,tester->y());
    }
    if(event->key()==Qt::Key_Up && tester->y()>=40){
        tester->setPos(tester->x(),tester->y()-40);
    }
    if(event->key()==Qt::Key_Down && tester->y()<=600){
        tester->setPos(tester->x(),tester->y()+40);
    }
}
