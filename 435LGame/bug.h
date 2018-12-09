/**
*\file bug.h
*\brief QGraphicsPixmapItem representing the bugs
*
* Bug objects move horizentally, shoot at the player when in sight
* also contains collision logic
*
* \author Ali Al Akbar Haidoura
*/
#ifndef BUG_H
#define BUG_H
#include<QGraphicsPixmapItem>
#include <QTimer>
class Game2Scene;

class Bug : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    Bug(Game2Scene*);//!<Bug constructor
    Game2Scene *scene;//!<The scene where the bug is added
    QTimer *timer;//!< QTimer for moving the Bug periodically
    QTimer *shootingTimer;//!<QTimer for shooting miniBugs
    QPixmap *icon;//!<QPixmap holding the image of the Bug
    QTransform transform;
    int lives;//!<Integer holding the number of Bug's lives left
    int dir;//!<Integer holding the direction of movement of the Bug
    int i;
    void decrementLives();//!<Responsible for collision logic with bullet
    void pause();//!<Responsible for keeping the bug in place when pausing the game
    void resume();//!<responsible for resuming after pausing

public slots:
    void guard();//!<The slot that moves the bug on each timer timeout
    void shoot();//!<Responsible for the shooting logic of the Bug
};

#endif // BUG_H
