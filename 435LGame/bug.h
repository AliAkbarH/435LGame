#ifndef BUG_H
#define BUG_H
#include<QGraphicsPixmapItem>

class Bug : public QGraphicsPixmapItem
{
public:
    Bug();
    QPixmap *icon;
};

#endif // BUG_H
