#include <QtWidgets>
#include <QObject>
#include <QPixmap>
#include"gameswidget.h"


gamesWidget::gamesWidget(QWidget *parent) : QWidget(parent)
{
    game1 = new QPushButton("Game 1");
    game2 = new QPushButton("Game 2");
    game3 = new QPushButton("Game 3");
    score = new QPushButton("Score Log");

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
    QObject::connect(game2, SIGNAL(clicked()), this, SLOT(startGame1()));
    QObject::connect(game3, SIGNAL(clicked()), this, SLOT(startGame1()));
    QObject::connect(score, SIGNAL(clicked()), this, SLOT(scoreLog()));

}

void gamesWidget::startGame1(){

}
void gamesWidget::startGame2(){

}
void gamesWidget::startGame3(){

}
void gamesWidget::scoreLog(){

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
