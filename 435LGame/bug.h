#ifndef BUG_H
#define BUG_H
#include<QGraphicsPixmapItem>
#include <QTimer>

class Bug : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bug();
    QTimer *timer;
    QPixmap *icon;
    int lives,dir,i;
    void decrementLives();

public slots:
    void guard();
};

#endif // BUG_H
