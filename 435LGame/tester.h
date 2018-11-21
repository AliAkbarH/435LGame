#ifndef TESTER_H
#define TESTER_H
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QObject>
#include<QTimer>

class Tester : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tester(int,int);
    QPixmap *icon;
    QTimer *timer;
    int lives,souls,startingX,startingY;
    void decrementLives();
    void loseLife();

};

#endif // TESTER_H
