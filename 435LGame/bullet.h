#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QDebug>

class Bullet :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    Bullet(int direction, int x, int y);
    QPixmap *icon;
    QTimer *timer;
    int step,direction;

signals:

public slots:
    void move();
};

#endif // BULLET_H
