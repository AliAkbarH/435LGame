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

    Bullet(int direction, int x, int y, Game2Scene *scene);
    QPixmap *icon;
    QTimer *timer;
    Game2Scene *scene;
    int step,direction;

signals:

public slots:
    void move();
};

#endif // BULLET_H
