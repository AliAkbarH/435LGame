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
    tester->setFlag(QGraphicsItem::ItemIsFocusable);
    tester->setFocus();


}
