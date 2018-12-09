/**
  \file bullet.h
  \brief QGraphicsPixmapItem representing the bullets
  \author Ali Al Akbar Haidoura
*/
#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QDebug>
#include"game2scene.h"

class Bullet :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    Bullet(int direction, int x, int y, Game2Scene *scene);//!<Bullet Constructor
    QPixmap *icon;//!<QPixmap holding the image of the bullet
    QTimer *timer;//!<QTimer that trigger s==s
    Game2Scene *scene;//!<The Scene where the Bullet is
    int step;//!<A steps counter used for deleting the bullet at a certain range
    int direction;//!<Integer holding the direction of the Bullet according to the last step the tester made

signals:

public slots:
    void move();//!<The slot that moves the Bullet on the timer's timeout
};

#endif // BULLET_H
