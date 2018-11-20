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
    Tester();
    QPixmap *icon;
    QTimer *timer;

};

#endif // TESTER_H
