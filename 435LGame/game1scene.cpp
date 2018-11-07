#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QtEvents>
#include <QTimer>

#include "popeye.h"
#include "locks.h"
#include "game1scene.h"
#include "gameswidget.h"

/**
* \file game1scene.cpp
* \brief contains Game1's class definition
*
* \author
*/

/*! \brief
*/

game1scene::game1scene(QString user)
{
    this->user=user;
    start = new QPushButton("Let's GO!");
    start->setStyleSheet("font: bold;background-color: orange;font-size: 36px;height: 48px;width: 170px;");

    this->addWidget(start);

    addItem(popeye);
    addItem(lock1);
    addItem(lock2);
    addItem(lock3);
    addItem(lock4);
    addItem(lock5);
    addItem(lock6);
    addItem(lock7);
    addItem(lock8);

   popeye->setPos(60,365);
   lock1->setPos(720,380);
   lock2->setPos(530,280);
   lock3->setPos(370,250);
   lock4->setPos(300,190);
   lock5->setPos(140,200);

   lock6->setScale(0.8);
   lock6->setPos(160,90);

   lock7->setScale(0.75);
   lock7->setRotation(90);
   lock7->setPos(600,100);

   lock8->setRotation(80);
   lock8->setPos(830,90);

   setBackgroundBrush(QBrush(QImage(":/Profile Images/Game1.png").scaledToHeight(512).scaledToWidth(910)));
   setSceneRect(0,0,908,510);


   popeye->setFlag(QGraphicsItem::ItemIsFocusable);
   popeye->setFocus();
   lock1->setFlag(QGraphicsItem::ItemIsFocusable);
   lock1->setFocus();
   lock2->setFlag(QGraphicsItem::ItemIsFocusable);
   lock2->setFocus();
   lock3->setFlag(QGraphicsItem::ItemIsFocusable);
   lock3->setFocus();
   lock4->setFlag(QGraphicsItem::ItemIsFocusable);
   lock4->setFocus();
   lock5->setFlag(QGraphicsItem::ItemIsFocusable);
   lock5->setFocus();
   lock6->setFlag(QGraphicsItem::ItemIsFocusable);
   lock6->setFocus();
   lock7->setFlag(QGraphicsItem::ItemIsFocusable);
   lock7->setFocus();
   lock8->setFlag(QGraphicsItem::ItemIsFocusable);
   lock8->setFocus();

   QObject::connect(start, SIGNAL(clicked()), this, SLOT(startLevel()));


}

void game1scene::startLevel(){

    scene2 = new levelsscene(user);               //!< pointer to an Object of type levelsscene
    view2 = new QGraphicsView(scene2);            //!< pointer to an Object of type QGraphicsView

    view2->setFixedSize(910,512);
    view2->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view2->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    int levelNum = getLevel();

    if (levelNum==1){
       updatePosition1();
    }else if (levelNum==2){
        updatePosition2();
     }else if (levelNum==3){
        updatePosition3();
     }else if (levelNum==4){
        updatePosition4();
     }else if (levelNum==5){
        updatePosition5();
     }else if (levelNum==6){
        updatePosition6();
     }else if (levelNum==7){
        updatePosition7();
     }else if (levelNum==8){
        updatePosition8();
     }

    view2->show();

}

void game1scene::hideLevelScene(){

    qDebug()<<view2->close();
    delete scene2;
    delete view2;
}

int game1scene::getLevel(){             //!<To get the level number from the text file (stored as the 10th entry)
    QDir dir;
    dir.setPath(dir.path()+"/profiles");
    QString profilePicDir;
    int levelNum=1;

    QFile inputFile(dir.path()+"/"+user+".txt");

    if (inputFile.open(QIODevice::ReadOnly))                // to check if it is entering the file, and it is
    {
       QTextStream in(&inputFile);
       QString s=in.readLine();
       profilePicDir=profileParser(s)[9];
       levelNum = profilePicDir.toInt();

       inputFile.close();
    }
    return levelNum;

}


QStringList game1scene::profileParser(QString line){       //parse the line and return a list.

    QRegExp rx("[\t]");
    QStringList list = line.split(rx, QString::SkipEmptyParts);
    return list;
}

void game1scene::updatePosition1(){
    popeye->setPos(lock1->x(),lock1->y());
    lock1->hide();
}
void game1scene::updatePosition2(){
    popeye->setPos(lock2->x(),lock2->y());
    lock2->hide();
    lock1->hide();
}
void game1scene::updatePosition3(){
    popeye->setPos(lock3->x(),lock3->y());
    lock3->hide();
    lock2->hide();
    lock1->hide();
}
void game1scene::updatePosition4(){
    popeye->setPos(lock4->x(),lock4->y());
    lock4->hide();
    lock3->hide();
    lock2->hide();
    lock1->hide();
}
void game1scene::updatePosition5(){
    popeye->setPos(lock5->x(),lock5->y());
    lock5->hide();
    lock4->hide();
    lock3->hide();
    lock2->hide();
    lock1->hide();
}
void game1scene::updatePosition6(){
    popeye->setPos(lock6->x(),lock6->y());
    lock6->hide();
    lock5->hide();
    lock4->hide();
    lock3->hide();
    lock2->hide();
    lock1->hide();
}
void game1scene::updatePosition7(){
    popeye->setPos(lock7->x(),lock7->y());
    lock7->hide();
    lock6->hide();
    lock5->hide();
    lock4->hide();
    lock3->hide();
    lock2->hide();
    lock1->hide();
}
void game1scene::updatePosition8(){
    popeye->setPos(lock8->x(),lock8->y());
    lock8->hide();
    lock7->hide();
    lock6->hide();
    lock5->hide();
    lock4->hide();
    lock3->hide();
    lock2->hide();
    lock1->hide();
}
