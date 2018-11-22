#include"lost.h"
#include<QLabel>
#include<QVBoxLayout>

/**
* \file lost.cpp
* \brief Shows the appropriate loose message in a pop up window
*
* \author Camille Farhat & Ali Haidar
*/


/*! \brief Setting the lost pop up window content
*/

lost::lost(QWidget *parent) : QWidget(parent)
{

}
lost::lost(int lifes, QWidget *parent) : QWidget(parent)
{
    if (lifes>0){
        QString life = QString::number(lifes);
        QLabel *label = new QLabel("You have " + life + " lifes left! \n Close this window and click on Retry to start again!");
        QVBoxLayout *layout= new QVBoxLayout();
        layout->addWidget(label);
        setLayout(layout);
    }else {                                                 //!<If the lives count is less than 0 the user would have lost completely and therefore would have to restart the game
        QString life = QString::number(lifes);
        QLabel *label = new QLabel("Game OVER :(\nClose this Window AND Close your Game Scene. \nClick Again on the Let's Go! button to ReStart From Level 1 :(");
        QVBoxLayout *layout= new QVBoxLayout();
        layout->addWidget(label);
        setLayout(layout);
    }
}
