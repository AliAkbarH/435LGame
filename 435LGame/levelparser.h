#ifndef LEVELPARSER_H
#define LEVELPARSER_H
#include<QString>
#include<QDir>
#include"game2scene.h"

class LevelParser
{
public:
    LevelParser(QString filePath);
    QDir *filePath;

    void parse(Game2Scene *scene);

private:
    void addItem(Game2Scene *scene,QGraphicsItem *item, int column, int row);
};

#endif // LEVELPARSER_H
