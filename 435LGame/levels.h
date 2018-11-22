#ifndef LEVELS_H
#define LEVELS_H
#include <QWidget>
#include <QString>
#include <QTimer>
#include <QtWidgets>
#include <QObject>
#include <QString>
#include "spinach.h"
#include "popeye.h"

/**
* \file levels.h
* \brief The Level Object
*
* Creating a Level Object that will be passed to every scene to load the respective level.
*
*/
class levels
{
public:
    QString hint[3], instructions;

    int popeyeX1, popeyeY1;                                                  //!<popeye's X and Y positions
    int spinachX1, spinachY1, spinachX2, spinachY2, spinachX3, spinachY3;    //!<spinach can's X and Y positions
    int river1X,river1Y;                                                     //!<the river's X and Y positions
    int boat1X,boat1Y;                                                       //!<the boat's X and Y positions
    int rock1X,rock1Y;                                                       //!<the rock's X and Y positions
    int obstacleX,obstacleY;                                                 //!<the obstacle's X and Y positions
    int smallRiver1X, smallRiver1Y;                                          //!<the first small river's X and Y positions
    int smallRiver2X, smallRiver2Y;                                          //!<the second small river X and Y positions
    int levelNumb, hintNumber, lifes;                                        //!<User's level Number, hint number and life number count
    int score;                                                               //!<User's score count

    levels(int x,QString user);

    void setPopeyeX1(int newX); //!<Setting up popeye's X and Y positions
    void setPopeyeY1(int newY); //!<

    void incrementHintNumber(); //!<Incrementing the hint Number
    void resetHintNumber();     //!<Restting the hint Number

    void decrementLifes();      //!<Decrementing the number of lifes

    void incrementLevelNumb();  //!<Incrementing the Level Number

    void incrementScore();      //!<Incrementing the score
    void decrementScore();      //!<Decrementing the score

    void updateLevel(QString user);     //!<Updating the level Number when user passes a level
    void updateLevelOne(QString user);  //!<Reseting the user's level to 1 if he looses the game

    //int getScore(QString user);
    //void updateScore(QString user);

    void resetLives();      //!<Reseting the lifes to it's initial count of 5
    void resetScore();      //!<Reseting the score to it's initial count of 100

};

#endif // LEVELS_H
