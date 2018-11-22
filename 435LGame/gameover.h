#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>

/**
* \file gameOver.h
* \brief The Game1Scene's gameOver pop up
*
* Pop up window that will display that the player lost when countDown Timer reaches 0.
*
*/

class gameOver : public QWidget
{
    Q_OBJECT
public:
    explicit gameOver(QWidget *parent = nullptr);

signals:


public slots:
};



#endif // GAMEOVER_H
