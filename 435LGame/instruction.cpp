#include "instruction.h"
#include<QLabel>
#include<QLayout>

/**
* \file instruction.cpp
* \brief Shows the initial instructions to start the game in a pop up window
*
* \author Camille Farhat & Ali Haidar
*/


/*! \brief Setting the instruction pop up window content
*/

instruction::instruction(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel("Welcome to Our Game! \n The rules are simple and we are trying to make this game as fun and as educational as possible! :)\n\n"
                               "The Goal of the game is to write a code to pickUp all spinach cans.\n"
                               "The code you will write is NOT case sensitive like some really powerfull high level language programing languages like Fortran, SQL and Pascal :)\n"
                               "However, each time you press on the RUN Button, if your code is not correct or incomplete your score and life counts will be both decremented :(\n"
                               "You will see the final position of popeye and therefore, you should recalculate your code and try again\n"
                               "You have 5 lifes per level, and there are 8 levels. You also have an initial score of 100. The faster you finish the higher your score.\n"
                               "Each time you loose a life your score will be decremented\n"
                               "Each time you press on a hint, your score will be decremented. However, you have three hints per level that you can loop through.\n"
                               "Popeye Automatically enters the Boat When they collide\n"
                               "Instructions at the top right of each level in the level scene will show you the functions that you can use in this level and how\n"
                               "You Have 20 mins to finish the entire game and 2 mins to finish each level\n"
                               "Remeber to seperate each line of code by returning back to the line\n\n"
                               "Try to get it Right and most importantly HAVE FUN!");
    QVBoxLayout *layout= new QVBoxLayout();
    layout->addWidget(label);
    setLayout(layout);
}

