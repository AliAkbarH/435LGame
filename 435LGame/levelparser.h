/**
* \file levelparser.h
* \brief Parses the game2 levels from the text files
* \author Ali Al Akbar Haidoura
  */
#ifndef LEVELPARSER_H
#define LEVELPARSER_H
#include<QString>
#include<QDir>
#include"game2scene.h"

class LevelParser
{
public:
    LevelParser(QString filePath);///<Constructor
    QDir *filePath;///<Directory to the file being parsed

    void parse(Game2Scene *scene);///<Responsible of actually parsing the file and adding the elements to the scene

private:
    void addItem(Game2Scene *scene,QGraphicsItem *item, int column, int row);///<Adds an item to the scene in the specified position
};

#endif // LEVELPARSER_H
