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
    miniBug(Game2Scene*,Bug*,int);
    QPixmap *icon;
    Game2Scene *scene;
    Bug *bug;
    QTimer *timer;
    int steps, dir;

public slots:
    void move();
};

#endif // MINIBUG_H
