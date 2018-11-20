#ifndef TESTER_H
#define TESTER_H
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QObject>

class Tester : public QGraphicsPixmapItem
{
    //Q_OBJECT
public:
    Tester();
    QPixmap *icon;
    void keyPressEvent(QKeyEvent *event);

};

#endif // TESTER_H
