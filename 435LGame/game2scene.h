/**
* \file game2scene.h
* \brief The scene in which all the logic and items of Game2 are located
* \author Ali Al Akbar Haidoura
  */
#ifndef GAME2SCENE_H
#define GAME2SCENE_H
#include<QGraphicsScene>
#include<QGraphicsView>
#include <QTimer>
#include<QLabel>
#include<QPushButton>
#include"tester.h"
#include"qualitycontrolicon.h"
#include"lifecounter.h"
#include"testingicon.h"
#include "bug.h"

class LevelParser;

class  Game2Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Game2Scene(QString user);//!<Constructor
    int dir;//!<Integer holding the direction of the tester
    int ammo;//!<Integer holding the amount of ammo left
    int bugs;//!<Integer holding the number of bugs left on the scene
    int remSec;//!<Integer holding the number of seconds left
    int HighScore;//!<Integer holding the HighScore of the Player
    int score;//!<Integer holding the current score of the player
    int level;//!<Integer holding the level the player is currently playing
    bool playing;//!<Boolean indicating if the player is active or not
    bool hasShield;//!<Boolean indicating if the tester has an active shiekd
    bool QCshown;//!<Boolean indicating if the Quality Control icon is hidden or shown
    bool paused;//!<Boolean indicating if the game is paused
    QList<Bug*> bugList;//!<QList of Bug objects pointers
    QLabel *announcement;//!<QLabel holding the win/loss announcements
    QLabel *timerLabel;///<QLabel holding the string Timer
    QLabel *ammoLabel;///<QLabel holding the word Ammo
    QLabel *livesLabel;///<QLabel holding the word Lives
    QLabel *HiScore;///QLabel holding the word HighScore
    QLabel *scoreL;///<QLabel holding the word score
    QPushButton *next;///<QPushButton used to continue when level finishes;
    QPushButton *pause;///<QPsuhButton used to pause/resume the
    LifeCounter *lifeCounter;///<QGraphicsPixmapItem representing the number of lives of the tester
    LevelParser *parser;///<Used to parse the levels from text files
    QString user;///<QString holding the current user
    Tester *tester;///<QGraphicsPixmapItem representing the tester character
    QualityControlIcon *QCIcon;///<QGraphicsPixmapItem representing the Quality control Icon
    QTimer *shieldTimer;///<QTimer responsible for deactivating the shield after 5 seconds
    QTimer *timer;///<QTimer responsible for updating the time each second
    QGraphicsPixmapItem *soul1,*soul2,*soul3;///<QGraphicsPixmapItem representing the souls of the tester
    QGraphicsPixmapItem *tens,*units;///<QGraphicsPixmapItem representing the time left
    QGraphicsPixmapItem *ammoTens, *ammoUnits;///<QGraphicsPixmapItem representing the ammo left
    void updateLifeScore();///<Responsible of updating the tester's lives when colliding with a bug or a miniBug
    int getHighScore();///<Responsible of fetching the HighScore from the profile file
    void updateHighScore(QString user);///<Responsible of updating the HighScore in the profile file if needed


private:
    void updateTimerPix();///<Responsible of updating the timer Pixmaps on each timer timeout
    void updateAmmoPix();///<Responsible of updating the ammo Pixmaps on every shooting
    void youWin();///<Provides win logic
    void youLose(QString reason);///<Provides loss logic
    void keyPressEvent(QKeyEvent *event);///<Overload of the keyPressEvent function responsible of translating keyboards events to game logic
    QStringList profileParser(QString line);///<Decomposes the profile file into entries
    void initializeScene();///<Initializes the Scene with common features across levels


public slots:
    void deactivateShield();///<Responsible of deactivating the shield on shieldTimer timeout
    void updateTimer();///<Responsible of updating remSec on every timer timeout
    void pauseOrResume();///<Responsible of pausing or resuming the game on pause PushButton press
    void startLevel();///<Responsible of starting a new level after passing the previous one
    void logScore();///<Responsible of logging the score to file after winning the game
    void retry();///<Responsible of restarting the game after losing

};

#endif // GAME2SCENE_H
