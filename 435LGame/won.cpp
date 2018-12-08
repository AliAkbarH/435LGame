#include "won.h"
#include<QLabel>
#include<QLayout>


/**
* \file won.cpp
* \brief Shows the appropriate win message in a pop up window
*
* \author Camille Farhat & Ali Haidoura
*/


/*! \brief Setting the win pop up window content
*/
Won::Won(QWidget *parent) : QWidget(parent)
{

}

Won::Won(int level, int lives){

    if (level<8){
        QLabel *label = new QLabel("You have successfully passed level "+QString::number(level)+". You may now proceed to the next level. You had "+QString::number(lives)+" lives remaining.");
        QVBoxLayout *layout= new QVBoxLayout();
        layout->addWidget(label);
        setLayout(layout);
    }else{                      //!<If level is 8 and user won therefore he would have the entire game.
        QLabel *label = new QLabel("ALRIGHT! Nice Job! Olive is now Safe!\n Your score has been recorded in The score log! \n Go Check it our and see how you did compared to other player!!! :D");
        QVBoxLayout *layout= new QVBoxLayout();
        layout->addWidget(label);
        setLayout(layout);
    }
}
