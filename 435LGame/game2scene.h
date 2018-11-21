#ifndef GAME2SCENE_H
#define GAME2SCENE_H
#include<QGraphicsScene>
#include<QGraphicsView>
#include"tester.h"

class LevelParser;

class  Game2Scene : public QGraphicsScene
{

public:
    Game2Scene(QString user);
    QGraphicsView *view;
    LevelParser *parser;
    QString user;
    Tester *tester;
    int dir;
    bool playing;
    void keyPressEvent(QKeyEvent *event);
};

#endif // GAME2SCENE_H
