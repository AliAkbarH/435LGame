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

/**
* \file gameswidget.cpp
* \brief contains Game1-2 Links
*
* \author Camille Farhat & Ali Haidoura
*/


/*! \brief Setting the widget's layout.
*/
gamesWidget::gamesWidget(QString user)
{
    game1 = new QPushButton("Game 1");
    game2 = new QPushButton("Game 2");


    this->user=user;
    game1->setStyleSheet("font: bold;background-color: red;font-size: 36px;height: 48px;width: 170px;");
    game2->setStyleSheet("font: bold;background-color: red;font-size: 36px;height: 48px;width: 170px;");


    GridL = new QGridLayout();
    VerticalL = new QVBoxLayout();

    setGridLayout();
    setVerticalLayout();
    setLayout(VerticalL);


    QObject::connect(game1, SIGNAL(clicked()), this, SLOT(startGame1()));
    QObject::connect(game2, SIGNAL(clicked()), this, SLOT(startGame2()));


}

/*! \brief Slot to take the user to Game1Scene.
*/
void gamesWidget::startGame1(){

    scene1 = new game1scene(user);              //!< pointer to an Object of type game1scene
    view1 = new QGraphicsView(scene1);      //!< pointer to an Object of type QGraphicsView

    view1->setFixedSize(910,512);
    view1->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view1->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    this->hide();
    view1->setAlignment(Qt::AlignCenter);
    view1->show();


}
/*! \brief Slot to take the user to Game2Scene.
*/
void gamesWidget::startGame2(){
    scene2=new Game2Scene(user);

    view2=new QGraphicsView(scene2);
    view2->setFixedHeight(845);
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
/*! \brief Setting the Vertical Layout.
*/
void gamesWidget::setVerticalLayout(){

    VerticalL->addItem(GridL);
}
/*! \brief Setting the Grid Layout
*/
void gamesWidget::setGridLayout(){

     GridL->addWidget(game1, 0, 0);
     GridL->addWidget(game2, 1, 0);


     GridL->setSpacing(40);
}
