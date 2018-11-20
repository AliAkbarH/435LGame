#include <QtWidgets>
#include <QObject>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include<QDir>


#include "game1scene.h"
#include"gameswidget.h"
#include"levelparser.h"


gamesWidget::gamesWidget(QString user)
{
    game1 = new QPushButton("Game 1");
    game2 = new QPushButton("Game 2");
    game3 = new QPushButton("Game 3");
    score = new QPushButton("Score Log");
    this->user=user;
    game1->setStyleSheet("font: bold;background-color: red;font-size: 36px;height: 48px;width: 170px;");
    game2->setStyleSheet("font: bold;background-color: red;font-size: 36px;height: 48px;width: 170px;");
    game3->setStyleSheet("font: bold;background-color: red;font-size: 36px;height: 48px;width: 170px;");
    score->setStyleSheet("font: bold;background-color: red;font-size: 36px;height: 48px;width: 170px;");

    GridL = new QGridLayout();
    VerticalL = new QVBoxLayout();

    setGridLayout();
    setVerticalLayout();
    setLayout(VerticalL);


    QObject::connect(game1, SIGNAL(clicked()), this, SLOT(startGame1()));
    QObject::connect(game2, SIGNAL(clicked()), this, SLOT(startGame2()));
    QObject::connect(game3, SIGNAL(clicked()), this, SLOT(startGame3()));
    QObject::connect(score, SIGNAL(clicked()), this, SLOT(scoreLog()));

}

void gamesWidget::startGame1(){

    scene1 = new game1scene(user);              //!< pointer to an Object of type game1scene
    view1 = new QGraphicsView(scene1);      //!< pointer to an Object of type QGraphicsView

    view1->setFixedSize(910,512);
    view1->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view1->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    this->hide();
    view1->show();
    //view1->close();

}
void gamesWidget::startGame2(){
    scene2=new Game2Scene(user);

    view2=new QGraphicsView(scene2);
    view2->setFixedHeight(645);
    view2->setFixedWidth(1285);
    view2->show();
    scene2->tester->setFocus();
    if(scene2->tester->hasFocus()){
        qDebug()<<"focused";
    }
    else{
        qDebug()<<"not focused";
    }


}
void gamesWidget::startGame3(){

}
void gamesWidget::scoreLog(){

}

void gamesWidget::hideScene(){
    //scene1->deleteLater();
   // scene1->clear();
   // delete scene1;
   // view1->hide();
    //view1->close();
}

void gamesWidget::setVerticalLayout(){

    VerticalL->addItem(GridL);
}

void gamesWidget::setGridLayout(){

     GridL->addWidget(game1, 0, 0);
     GridL->addWidget(game2, 1, 0);
     GridL->addWidget(game3, 2, 0);
     GridL->addWidget(score, 3, 0);

     GridL->setSpacing(20);


}
