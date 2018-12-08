#include"lost.h"
#include<QLabel>
#include<QVBoxLayout>

/**
* \file lost.cpp
* \brief Shows the appropriate loose message in a pop up window
*
* \author Camille Farhat & Ali Haidoura
*/


/*! \brief Setting the lost pop up window content, displaying the total number of lifes left and any syntax error when needed
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

lost::lost(int lifes, QString command, QWidget *parent) : QWidget(parent)
{
    QString life = QString::number(lifes);

        if (command== "move"){
        QLabel *label = new QLabel("Check your syntax!\nMove(# of steps) is the correct way of entering your input!\nNote that the M should be capitalized and the (number of steps should be inside the parenthesis). "
                                   "\nCheck for other syntax errors NOW! since this message only highlights the first error in the queue if any other exist!"
                                   "\nCorrect syntax shown in top right box! Check it again!"
                                   "\nYou have " + life + " lifes left! \n Close this window and click on Retry to start again!");
        QVBoxLayout *layout= new QVBoxLayout();
        layout->addWidget(label);
        setLayout(layout);
        }else if (command=="pickup"|| command=="Pickup"||command=="PickUp"){
            QLabel *label = new QLabel("Check your syntax! \npickUp() is the correct  way of entering your input!\nNote that the 'p' should be in small letters and the U should be capitalized. "
                                       "\nDo not forget the two parenthesis in the end :)"
                                       "\nCheck for other syntax errors NOW! since this message only highlights the first error in the queue if any other exist!"
                                       "\nCorrect syntax shown in top right box! Check it again!"
                                       "\nYou have " + life + " lifes left! \n Close this window and click on Retry to start again!");
            QVBoxLayout *layout= new QVBoxLayout();
            layout->addWidget(label);
            setLayout(layout);
        }else if (command=="rotate"){
            QLabel *label = new QLabel("Check your syntax! \nRotate() is the correct  way of entering your input!\nNote that the R should be capitalized. "
                                       "\nCheck for other syntax errors NOW! since this message only highlights the first error in the queue if any other exist!"
                                       "\nDo not forget the two parenthesis in the end :)"
                                       "\nCorrect syntax shown in top right box! Check it again!"
                                       "\nYou have " + life + " lifes left! \n Close this window and click on Retry to start again!");
            QVBoxLayout *layout= new QVBoxLayout();
            layout->addWidget(label);
            setLayout(layout);
        }else if(command=="boat.rotate"||command=="Boat.rotate"||command=="boat.Rotate"||command=="boat.rotate("||command=="Boat.rotate("||command=="boat.Rotate("){
            QLabel *label = new QLabel("Check your syntax! \nBoat.Rotate() is the correct  way of entering your input!\nNote that the B in Boat and the R in Rotate should be capitalized. "
                                       "\nCheck for other syntax errors NOW! since this message only highlights the first error in the queue if any other exist!"
                                       "\nDo not forget the two parenthesis in the end :)"
                                       "\nCorrect syntax shown in top right box! Check it again!"
                                       "\nYou have " + life + " lifes left! \n Close this window and click on Retry to start again!");
            QVBoxLayout *layout= new QVBoxLayout();
            layout->addWidget(label);
            setLayout(layout);
        }else if (command=="boat.move" ||command=="Boat.move"|| command=="boat.Move"){
            QLabel *label = new QLabel("Check your syntax! \nBoat.Move() is the correct  way of entering your input!\nNote that the B in Boat and the M in Move should be capitalized the (number of steps should be inside the parenthesis). "
                                       "\nCheck for other syntax errors NOW! since this message only highlights the first error in the queue if any other exist!"
                                       "\nCorrect syntax shown in top right box! Check it again!"
                                       "\nYou have " + life + " lifes left! \n Close this window and click on Retry to start again!");
            QVBoxLayout *layout= new QVBoxLayout();
            layout->addWidget(label);
            setLayout(layout);
        }else if (!command.toInt()){        //!< not checking for the in entered in the Move(#) function
            QLabel *label = new QLabel("Weird syntax you have there... Time is ticking and olive is waiting!\n We do not really know what you wrote there!"
                                       "\nSome of the words entered do not match at all the syntax proposed!"
                                       "\nQuickly correct your code by looking at the correct syntax shown in top right box! Check it again!"
                                       "\nYou have " + life + " lifes left! \n Close this window and click on Retry to start again!");
            QVBoxLayout *layout= new QVBoxLayout();
            layout->addWidget(label);
            setLayout(layout);
        }

}
