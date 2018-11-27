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
    Game2Scene(QString user);
    int dir, ammo, bugs, tests, remSec, HighScore, score;
    bool playing, hasShield, QCshown, paused;
    QList<Bug*> bugList;
    QLabel *announcement, *timerLabel,*ammoLabel,*livesLabel, *HiScore, *scoreL;
    QPushButton *next,*pause;
    LifeCounter *lifeCounter;
    LevelParser *parser;
    QString user;
    Tester *tester;
    QualityControlIcon *QCIcon;
    QTimer *shieldTimer, *timer;
    QGraphicsPixmapItem *soul1,*soul2,*soul3,*tens,*units, *ammoTens, *ammoUnits;
    void updateLifeScore();
    int getHighScore();
    void updateHighScore(QString user);


private:
    void updateTimerPix();
    void updateAmmoPix();
    void youWin();
    void youLose(QString reason);
    void keyPressEvent(QKeyEvent *event);
    QStringList profileParser(QString line);


public slots:
    void deactivateShield();
    void updateTimer();
    void pauseOrResume();
};

#endif // GAME2SCENE_H
