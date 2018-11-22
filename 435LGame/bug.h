#ifndef BUG_H
#define BUG_H
#include<QGraphicsPixmapItem>
#include <QTimer>
//#include"game2scene.h"
class Game2Scene;

class Bug : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    Bug(Game2Scene*);
    Game2Scene *scene;
    QTimer *timer, *shootingTimer;
    QPixmap *icon;
    QTransform transform;
    int lives,dir,i;
    void decrementLives();
    void pause();
    void resume();

public slots:
    void guard();
    void shoot();
};

#endif // BUG_H
