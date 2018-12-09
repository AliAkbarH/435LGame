/**
* \file qualitycontrolicon.h
* \brief QGraphicsPixmapItem representing the quality control icon
* \author Ali Al Akbar Haidoura
  */
#ifndef QUALITYCONTROLICON_H
#define QUALITYCONTROLICON_H
#include<QGraphicsPixmapItem>

class QualityControlIcon : public QGraphicsPixmapItem
{
public:
    QualityControlIcon();///<Constructor
    QPixmap *icon;///<Pixmap holding the image of the QC icon
};

#endif // QUALITYCONTROLICON_H
