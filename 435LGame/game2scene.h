#ifndef GAME2SCENE_H
#define GAME2SCENE_H
#include<QGraphicsScene>
#include<QGraphicsView>

class LevelParser;

class  Game2Scene : public QGraphicsScene
{
public:
    Game2Scene(QString user);
    QGraphicsView *view;
    LevelParser *parser;
    QString user;
};

#endif // GAME2SCENE_H
