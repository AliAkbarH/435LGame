#ifndef TESTER_H
#define TESTER_H
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QObject>
#include<QTimer>

class Tester : public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tester();
    QPixmap *icon;
    QTimer timer;
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:
    void step(int i);

};

#endif // TESTER_H
