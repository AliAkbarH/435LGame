/**
* \file minibug
* \brief QGraphicsPixmapItem representing the miniBug that the Bug shoots
* \author Ali Al Akbar Haidoura
  */
#ifndef MINIBUG_H
#define MINIBUG_H
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>
#include"game2scene.h"


class miniBug : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    miniBug(Game2Scene*,Bug*,int);///<Constructor
    QPixmap *icon;///<Pixmap holding the image
    Game2Scene *scene;///<The scene where the miniBug is located
    Bug *bug;///<The parent Bug
    QTimer *timer;///<QTimer used to move the miniBug periodically
    int steps;///<Number of steps taken already used in determining the range
    int dir;///<Integer holding the direction of the miniBug

public slots:
    void move();///<responsible of moving the miniBug on each timer timeout
};

#endif // MINIBUG_H
