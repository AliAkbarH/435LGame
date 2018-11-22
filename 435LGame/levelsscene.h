#ifndef LEVELSSCENE_H
#define LEVELSSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QtEvents>
#include <QTimer>
#include <QtWidgets>
#include <QString>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QApplication>

#include "river.h"
#include "popeye.h"
#include "locks.h"
#include "levels.h"
#include "spinach.h"
#include "boat.h"
#include "rock.h"
#include "riverobstacle.h"
#include "smallriver.h"


/**
* \file game1scene.hB
* \brief The Game's scene
*
* This is the header file for our first game's scene. It publicly inherits from QGraphicsScene.
*/

class levelsscene : public QGraphicsScene
{
    Q_OBJECT
public:
    levelsscene(QString user);

    QString user;    


    Popeye *popeye = new Popeye();       //!< Creating the references to the Objects
    spinach *spinach1 = new spinach();
    spinach *spinach2 = new spinach();
    spinach *spinach3 = new spinach();

    river *river1 = new river();

    boat *boat1 = new boat();

    rock *rock1 = new rock();

    riverObstacle *obstacle = new riverObstacle;

    smallRiver *smallRiver1 = new smallRiver();
    smallRiver *smallRiver2 = new smallRiver();

    levels *l;

    QPushButton *run, *hint, *pause, *retry, *proceed;      //!<QWidgets that will displayed on the screen
    QTextEdit *text;
    QLabel *instructions;

    void looseLife();
    void gameOver();

    void youLost(bool);     //!<Decrementing lifes, score and showing appropriate pop up window when users' looses

    void youWon();      //!<Incrementing score, proceeding to the game1scene and showing appropriate pop up window when user wins


    QGraphicsTextItem *countDownText;
    int countdown = 120;                //! < value of the countdown at the start of the game that is = to 120 i.e. 2 mins for each level
    QTimer *countdownTimer;             //! < Timer controlling the countdown
    void setUpCountdownTimer();         //!< Setting up the timer



private:
        bool fileExists(QString path);          //!<Functions that checks if the file exists before using it
        int getLevel();                         //!<Return the level the user is currently in
        QStringList profileParser(QString in);  //!<Returns a list of strings from our text files that are seperated by spaces

signals:

public slots:
        void checkAnswer(); //!<Checking the User's input and moving popeye and the boat accordingly. If the User Clicks on the pickUp Spinach cans dissapear.
        void displayHint(); //!<Displaying the 3 hints and repeating them if passed over all of them and decrement score accordingly
        void pauseLevel();  //!<Pause the level the user's in
        void retryLevel();  //!<Retry level and reset positons to initial hard coded positions
        void hideScene();   //!<Hide the scene
        void updateCountdownTimer();//!<Function that will update the timer and then display it


};

#endif
