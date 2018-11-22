#include "levels.h"

/**
* \file levels.cpp
* \brief Setting up the different specs for each level to load them dynamically everytime a user starts a level.
*
* \author Camille Farhat & Ali Haidar
*/


/*! \brief Setting the specs for each level
*/

levels::levels(int x,QString user)
{
    this->levelNumb = x;
    //score = getScore(user);
    score = 100;

    switch(levelNumb){
    case 1:
        hintNumber = 0;
        hint[0]="First hint";
        hint[1]="Second hint";
        hint[2]="Third hint";
        instructions = "Move Popeye Forward \n\nFunctions: \nMove(number of steps) \npickUp()";
        popeyeX1 = 100;
        popeyeY1 = 350;
        spinachX1 = 700;
        spinachY1 = 350;

        spinachX2 = 0;
        spinachX3 = 0;
        boat1X = 0;

        lifes = 5;

        break;
    case 2:
        hintNumber = 0;
        hint[0]="First hint";
        hint[1]="Second hint";
        hint[2]="Third hint";
        instructions = "Move Popeye Forwards and Backwards \n\nFunctions: \nMove(number of steps) \npickUp()";
        popeyeX1 = 400;
        popeyeY1 = 350;
        spinachX1 = 700;
        spinachY1 = 350;

        spinachX2 = 100;
        spinachY2 = 350;

        spinachX3 = 0;
        boat1X = 0;

        lifes = 5;


        break;
    case 3:
        hintNumber = 0;
        hint[0]="First hint";
        hint[1]="Second hint";
        hint[2]="Third hint";
        instructions = "Move and Turn Popeye \n\nFunctions: \nMove(number of steps) \nRotate()\npickUp()";
        popeyeX1 = 100;
        popeyeY1 = 350;

        spinachX1 = 400;
        spinachY1 = 350;

        spinachX2 = 670;
        spinachY2=200;

        spinachX3 = 0;
        boat1X = 0;

        lifes = 5;


        break;
    case 4:
        hintNumber = 0;
        hint[0]="First hint";
        hint[1]="Second hint";
        hint[2]="Third hint";
        instructions = "Utilizing objects. \nRiver element was added! Try NOT fall! \n\nFunctions: \nMove(number of steps) \nRotate() \nBoat.Move(number of steps) \npickUp()";

        popeyeX1 = 100;
        popeyeY1 = 415;

        spinachX1 = 600;
        spinachY1 = 100;

        spinachX2 = 600;
        spinachY2 = 300;

        spinachX3 = 0;

        lifes = 5;

        river1X = 0;
        river1Y = 300;

        boat1X = 50;
        boat1Y = 300;


        break;


    case 5:
        hintNumber = 0;
        hint[0]="First hint";
        hint[1]="Second hint";
        hint[2]="Third hint";
        instructions = "Utilizing objects \n\nFunctions: \nMove(number of steps) \nRotate() \nBoat.Move(number of steps) \nBoat.Rotate() \npickUp()";

        popeyeX1 = 670;
        popeyeY1 = 360;

        spinachX1 = 400;
        spinachY1 = 100;

        spinachX2 = 0;
        spinachX3 = 0;
        river1X = 0;

        lifes = 5;

        boat1X = 100;
        boat1Y = 360;

        rock1X = 650;
        rock1Y = 360;

        break;

    case 6:
        hintNumber = 0;
        hint[0]="First hint";
        hint[1]="Second hint";
        hint[2]="Third hint";
        instructions = "Using Loops \n\nFunctions: \nRepeat(number of time):[steps to repeat] \nMove(number of steps) \nRotate() \npickUp()";

        popeyeX1 = 600;
        popeyeY1 = 350;

        spinachX1 = 600;
        spinachY1 = 100;

        spinachX2 = 300;
        spinachY2 = 350;

        spinachX3 = 300;
        spinachY3 = 100;

        obstacleX = 450;
        obstacleY = 0;

        lifes = 5;


        break;

    case 7:
        hintNumber = 0;
        hint[0]="First hint";
        hint[1]="Second hint";
        hint[2]="Third hint";
        instructions = "Using Objects and Loops \n\nFunctions: \nRepeat(number of time):[steps to repeat] \nMove(number of steps) \nRotate() \nBoat.Move(number of steps) \npickUp()";

        popeyeX1 = 120;
        popeyeY1 = 220;

        boat1X = 60;
        boat1Y = 350;

        spinachX1 = 120;
        spinachY1 = 435;

        spinachX2 = 430;
        spinachY2 = 435;

        spinachX3 = 750;
        spinachY3 = 435;

        river1X = 0;
        river1Y = 350;

        smallRiver1X = 250;
        smallRiver1Y = 430;

        smallRiver2X = 550;
        smallRiver2Y = 430;

        lifes = 5;


        break;
    case 8:
        hintNumber = 0;
        hint[0]="First hint";
        hint[1]="Second hint";
        hint[2]="Third hint";
        instructions = "Utilizing objects \n\nFunctions: \nMove(number of steps) \nRotate() \nBoat.Move(number of steps) \nBoat.Rotate() \npickUp()";

        popeyeX1 = 670;
        popeyeY1 = 360;

        spinachX1 = 470;
        spinachY1 = 100;

        spinachX2 = 400;
        spinachY2 = 360;

        spinachX3 = 170;
        spinachY3 = 260;

        river1X = 0;

        lifes = 5;

        boat1X = 100;
        boat1Y = 360;

        rock1X = 650;
        rock1Y = 360;

        break;

    }

}
/*! \brief Decrementing the number of lifes
*/
void levels::decrementLifes(){
    this->lifes--;
}
/*! \brief Incrementing the score
*/
void levels::incrementScore(){
    score = score + 10;
}
/*! \brief Decrementing the score
*/
void levels::decrementScore(){
    score = score - 10;
}
/*! \brief Incrementing the Level Number
*/
void levels::incrementLevelNumb(){
    levelNumb++;
}
/*! \brief Increasing the hint Number
*/
void levels::incrementHintNumber(){
    this->hintNumber++;
}
/*! \brief Reseting the Hint Number
*/
void levels::resetHintNumber(){
    this->hintNumber=0;
}
/*! \brief Reseting the number of lives
*/
void levels::resetLives(){
    this->lifes=0;
}
/*! \brief Reseting the score to it's initial count of 100
*/
void levels::resetScore(){
    this->score=100;
}
/*! \brief Setting Popeye's new X position
*/
void levels::setPopeyeX1(int newX){
    this->popeyeX1=newX;
}
/*! \brief Setting Popeye's New Y position
*/
void levels::setPopeyeY1(int newY){
    this->popeyeY1=newY;
}
/*! \brief Updating the level Number when user passes a level
*/
void levels::updateLevel(QString user){    //!<To update the level number in the text file (stored as the 10th entry)
    int level=levelNumb;
    levelNumb++;
    if(level<8){
        QDir dir;
        dir.setPath(dir.path()+"/profiles");

        QFile inputFile(dir.path()+"/"+user+".txt");
        inputFile.open(QIODevice::ReadWrite);
        QTextStream in(&inputFile);
        QString line=in.readLine();
        inputFile.close();
        inputFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
        int charIndex=0,tabIndex=0;
        while(tabIndex<9 && charIndex<line.size()){
            if(line.at(charIndex)=='\t'){
                tabIndex++;
            }
            charIndex++;
        }
        int character=level+1+'0';
        line=line.replace(charIndex,1,QChar(character));
        in<<line;
        inputFile.close();
    }
}
/*! \brief Reseting the user's level to 1 if he looses the game
*/
void levels::updateLevelOne(QString user){    //!<To update the level number in the text file (stored as the 10th entry)

    QDir dir;
    dir.setPath(dir.path()+"/profiles");

    QFile inputFile(dir.path()+"/"+user+".txt");
    inputFile.open(QIODevice::ReadWrite);

    QTextStream in(&inputFile);
    QString line=in.readLine();

    inputFile.close();

    inputFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    int charIndex=0,tabIndex=0;
    while(tabIndex<9 && charIndex<line.size()){
        if(line.at(charIndex)=='\t'){
            tabIndex++;
        }
        charIndex++;
    }
    int character = 1 + '0';
    line=line.replace(charIndex,1,QChar(character));

    in<<line;
    inputFile.close();

}

/*
int levels::getScore(QString user){             //!<To get the User's Score from the second line of text file
    QDir dir;
    dir.setPath(dir.path()+"/profiles");

    int myScore=55;

    QFile inputFile(dir.path()+"/"+user+".txt");

    if (inputFile.open(QIODevice::ReadOnly))                // to check if it is entering the file, and it is
    {
       QTextStream in(&inputFile);
       QString s=in.readLine();
       s=in.readLine();

       myScore = s.toInt();

       qDebug()<<myScore<<"FIRST";
       inputFile.close();
    }

    return myScore;

}*/

/*
void levels::updateScore(QString user){

    QDir dir;
    dir.setPath(dir.path()+"/profiles");

    QFile inputFile(dir.path()+"/"+user+".txt");
    inputFile.open(QIODevice::ReadWrite);

    QTextStream in(&inputFile);
    QString line=in.readAll();


    qDebug()<<line<<"SSS";

    inputFile.close();

    inputFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);


    int character = score + '0';
    line=line.replace(0,3,QChar(character));

    in<<line;
    inputFile.close();

}*/
