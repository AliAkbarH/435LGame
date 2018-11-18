#include "game2scene.h"
#include "levelparser.h"

Game2Scene::Game2Scene(QString user)
{
    this->user=user;
    setSceneRect(200,200,640,320);
    //setBackgroundBrush(QBrush(QImage("/game2 images/background.jpg").scaledToHeight(320).scaledToWidth(640)));

    view->setScene(this);
    view->setFixedWidth(645);
    view->setFixedHeight(325);
    view->show();

    parser=new LevelParser("/game2 levels/level1.txt");
    parser->parse(this);


}
