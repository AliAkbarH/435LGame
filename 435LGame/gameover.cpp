#include "gameover.h"
#include<QLabel>
#include<QLayout>

/**
* \file gameOver.cpp
* \brief The Game1Scene's gameOver pop up
*
* Pop up window that will display that the player lost when countDown Timer reaches 0.
*
* \author Camille Farhat & Ali Haidar
*/


/*! \brief Setting the message pop up window content
*/

gameOver::gameOver(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel("Game Over! :( \n\nYour 20 mins are up! \n\nClose all the windows and Exit.");
    QVBoxLayout *layout= new QVBoxLayout();
    layout->addWidget(label);
    setLayout(layout);
}
