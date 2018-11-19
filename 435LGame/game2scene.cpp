#include "game2scene.h"
#include "levelparser.h"
#include <QDebug>

Game2Scene::Game2Scene(QString user)
{
    QDir dir;
    this->user=user;
    setSceneRect(200,200,640,320);
    setBackgroundBrush(QBrush(QImage(dir.absolutePath()+"/game2 images/background.jpg").scaledToHeight(320).scaledToWidth(640)));


    qDebug()<<dir.absolutePath();
    parser=new LevelParser(dir.absolutePath()+"/game2 images/level1.txt");
    parser->parse(this);


}
