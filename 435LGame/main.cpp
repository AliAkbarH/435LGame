/**
* \mainpage EECE435L Game
* \author Ali Al Akbar Haidoura
* \author Camille farhat
* \date 9-12-2018
* \brief A game containing two sub-games designed to help kids learn programming
  */
#include <QApplication>
#include <QtWidgets>
#include<QPushButton>
#include<signinwidget.h>
#include<logginwidget.h>
#include<gameswidget.h>
#include<logonwidget.h>

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include "game1scene.h"
#include"gameswidget.h"

int main(int argc, char **argv)
{
QApplication app (argc, argv);

LogOnWidget *LogonWidget=new LogOnWidget();
LogonWidget->show();

return app.exec();
}
