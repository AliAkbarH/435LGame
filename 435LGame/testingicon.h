#ifndef TESTINGICON_H
#define TESTINGICON_H
#include<QGraphicsPixmapItem>

class TestingIcon : public QGraphicsPixmapItem
{
public:
    TestingIcon();
    QPixmap *icon;
};

#endif // TESTINGICON_H
