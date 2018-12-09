/**
* \file shield.h
* \brief QGraphicsPixmapItem representing the shield icon
* \author Ali Al Akbar Haidoura
  */
#ifndef SHIELD_H
#define SHIELD_H
#include<QGraphicsPixmapItem>

class Shield : public QGraphicsPixmapItem
{
public:
    Shield();///<Constructor
    QPixmap *icon;///<Pixmap holding the image of the shield
};

#endif // SHIELD_H
