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

   QObject::connect(start, SIGNAL(clicked()), this, SLOT(starLevel()));

   //updatePosition();

}
void game1scene::updatePosition(){
    popeye->setPos(lock1->x(),lock1->y());      //for now
    lock1->hide();
}

void game1scene::starLevel(){

}

