#ifndef WALL_H
#define WALL_H
#include<QGraphicsPixmapItem>

class Wall : public QGraphicsPixmapItem
{
public:
    Wall();
    QPixmap *icon;
};

#endif // WALL_H
