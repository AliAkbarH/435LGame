#include "logginwidget.h"
#include <QtWidgets>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QMainWindow>
#include <QLabel>
#include"gameswidget.h"

loggInWidget::loggInWidget(QString user)
{
    games = new QPushButton("Let's PLay!");

    games->setStyleSheet("font: bold;background-color: blue;font-size: 36px;height: 48px;width: 190px;");
    this->user=user;
    userName = new QLabel("Username: "+this->user);
    userName->setStyleSheet("font: bold;font-size: 36px;height: 38px;width: 90px;");


    GridL = new QGridLayout();
    VerticalL = new QVBoxLayout();

    setGridLayout();
    setVerticalLayout();
    setLayout(VerticalL);


    QObject::connect(games, SIGNAL(clicked()), this, SLOT(startGames()));

}

void loggInWidget::startGames(){

    gamesWidget *games = new gamesWidget();
    this->close();
    games->show();

}

void loggInWidget::setVerticalLayout(){

    VerticalL->addItem(GridL);
    VerticalL->addWidget(games);
    VerticalL->setSpacing(20);
}

void loggInWidget::setGridLayout(){

    QPixmap m_logo_pic;
    QLabel *displayPic = new QLabel();
    m_logo_pic.load(":/Profile Images/bucket.png");
    displayPic->setPixmap(m_logo_pic);

    GridL->addWidget(userName, 0, 0);
    GridL->addWidget(displayPic,2,0,40,40,Qt::AlignCenter);


}
