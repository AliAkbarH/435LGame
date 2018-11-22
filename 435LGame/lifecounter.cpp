#include "lifecounter.h"

LifeCounter::LifeCounter(int life)
{
    QString path(":/game2 images/live"+QString::number(life)+".png");
    QPixmap icon(path);
    setPixmap(icon.scaledToHeight(100));
}
