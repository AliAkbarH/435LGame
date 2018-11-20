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

//LogOnWidget *LogonWidget=new LogOnWidget();
//LogonWidget->show();

gamesWidget *window = new gamesWidget("AliAkbar");
window->show();

/*game1scene *scene1 = new game1scene();              //!< pointer to an Object of type game1scene

QGraphicsView *view1 = new QGraphicsView(scene1);   //!< pointer to an Object of type QGraphicsView

view1->setFixedSize(910,512);
view1->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
view1->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
view1->show();*/

return app.exec();
}
