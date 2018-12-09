/**
*\file coffeecup.h
* \brief QGraphicsPixmapItem representing the Coffee Cup
* \author Ali Al Akbar Haidoura
  */
#ifndef COFFEECUP_H
#define COFFEECUP_H
#include<QGraphicsPixmapItem>

class CoffeeCup : public QGraphicsPixmapItem
{
public:
    CoffeeCup();//!<CoffeeCup Constructor
    QPixmap *icon;//!<QPixmap holding the image of the CoffeeCup
};

#endif // COFFEECUP_H
