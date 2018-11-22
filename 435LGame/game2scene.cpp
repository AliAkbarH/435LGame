#include "game2scene.h"
#include "levelparser.h"
#include"bug.h"
#include"wall.h"
#include"coffeecup.h"
#include"qualitycontrolicon.h"
#include"testingicon.h"
#include"shield.h"
#include"bullet.h"
#include <QDebug>

Game2Scene::Game2Scene(QString user)
{
    dir=0;
    ammo=30;
    tests=3;
    remSec=90;
    playing=true;
    QCshown=false;
    paused=false;
    this->user=user;

    announcement=new QLabel();
    announcement->setGeometry(700,-170,200,50);
    addWidget(announcement);
    announcement->setAttribute(Qt::WA_TranslucentBackground);
    announcement->setStyleSheet("font: bold;font-size: 20px;");

    livesLabel=new QLabel("Lives:");
    addWidget(livesLabel);
    livesLabel->setGeometry(50,-180,200,30);
    livesLabel->setAttribute(Qt::WA_TranslucentBackground);
    livesLabel->setStyleSheet("font: bold;font-size: 20px;");

    ammoLabel=new QLabel("Ammo:");
    addWidget(ammoLabel);
    ammoLabel->setGeometry(350,-180,200,30);
    ammoLabel->setAttribute(Qt::WA_TranslucentBackground);
    ammoLabel->setStyleSheet("font: bold;font-size: 20px;");

    timerLabel=new QLabel("Time remaining:");
    addWidget(timerLabel);
    timerLabel->setGeometry(500,-180,200,30);
    timerLabel->setAttribute(Qt::WA_TranslucentBackground);
    timerLabel->setStyleSheet("font: bold;font-size: 20px;");


    next=new QPushButton();
    next->setGeometry(900,-170,50,50);
    addWidget(next);
    next->hide();

    pause=new QPushButton();
    pause->setGeometry(1100,-150,100,100);
    pause->setAttribute(Qt::WA_TranslucentBackground);
    pause->setAutoFillBackground(true);
    //pause->setFlat(true);
    pause->setIcon(QIcon(QPixmap(":/game2 images/pause.png").scaled(100,100)));
    addWidget(pause);

    setSceneRect(0,-100,1280,640);
    setBackgroundBrush(QBrush(QImage(":/game2 images/background.jpg").scaledToHeight(640).scaledToWidth(1280)));

    LevelParser parser(":/game2 images/level1.txt");
    parser.parse(this);
    bugs=bugList.count();
    hasShield=false;

    lifeCounter=new LifeCounter(tester->lives);
    soul1=new QGraphicsPixmapItem();
    soul1->setPixmap((QPixmap(":/game2 images/heart.png")).scaledToHeight(50));
    addItem(soul1);
    soul1->setPos(150,-100);
    soul2=new QGraphicsPixmapItem();
    soul2->setPixmap((QPixmap(":/game2 images/heart.png")).scaledToHeight(50));
    addItem(soul2);
    soul2->setPos(200,-100);
    soul3=new QGraphicsPixmapItem();
    soul3->setPixmap((QPixmap(":/game2 images/heart.png")).scaledToHeight(50));
    addItem(soul3);
    soul3->setPos(250,-100);
    updateLifeScore();

    units=new QGraphicsPixmapItem();
    tens=new QGraphicsPixmapItem();
    addItem(units);
    addItem(tens);
    units->setPos(560,-150);
    tens->setPos(500,-150);
    updateTimerPix();

    ammoUnits=new QGraphicsPixmapItem();
    ammoTens=new QGraphicsPixmapItem();
    addItem(ammoUnits);
    addItem(ammoTens);
    ammoUnits->setPos(410,-150);
    ammoTens->setPos(350,-150);
    updateAmmoPix();


    timer=new QTimer();
    timer->start(1000);
    shieldTimer =new QTimer();

    connect(shieldTimer,SIGNAL(timeout()),this,SLOT(deactivateShield()));
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTimer()));
    connect(pause,SIGNAL(clicked(bool)),this,SLOT(pauseOrResume()));


}

void Game2Scene::keyPressEvent(QKeyEvent *event){
    if(!paused){
        int prevX=tester->x(),prevY=tester->y();
        int newX=prevX,newY=prevY;
        if(event->key()==Qt::Key_Right && tester->x()<=1240){
            newX=prevX+40;
            newY=prevY;
            dir=0;
        }
        if(event->key()==Qt::Key_Left && tester->x()>=40){
            newX=prevX-40;
            newY=prevY;
            dir=2;
        }
        if(event->key()==Qt::Key_Up && tester->y()>=40){
            newX=prevX;
            newY=prevY-40;
            dir=1;
        }
        if(event->key()==Qt::Key_Down && tester->y()<=600){
            newX=prevX;
            newY=prevY+40;
            dir=3;
        }
        if(event->key()==Qt::Key_Space && playing && ammo>0){
            Bullet *bullet=new Bullet(dir,tester->x(),tester->y(),this);
            addItem(bullet);
            ammo--;
            updateAmmoPix();
        }
        if(bugs==0){
            QCIcon->show();
            QCshown=true;
        }

        tester->setPos(newX,newY);
        QList<QGraphicsItem*> colliding=tester->collidingItems();

        if(!colliding.isEmpty()){
            if(dynamic_cast<Wall*>(colliding.at(0))!=NULL){
                newX=prevX;
                newY=prevY;
            }
            else if(dynamic_cast<Bug*>(colliding.at(0))!=NULL && !hasShield){
                tester->loseLife();
                updateLifeScore();
                newX=tester->startingX;
                newY=tester->startingY;
                if(tester->lives==0){
                    removeItem(tester);
                    playing=false;
                }
            }

            else if(dynamic_cast<CoffeeCup*>(colliding.at(0))!=NULL){
                tester->drinkCoffee();
                updateLifeScore();
                removeItem(colliding.at(0));
            }

            else if(dynamic_cast<Shield*>(colliding.at(0))!=NULL){
                hasShield=true;
                shieldTimer->start(5000);
                tester->setPixmap(QPixmap(":/game2 images/developer1.png").scaledToHeight(35));
                removeItem(colliding.at(0));
            }
            else if(dynamic_cast<TestingIcon*>(colliding.at(0))!=NULL && !dynamic_cast<TestingIcon*>(colliding.at(0))->isHidden){
                ammo+=5;
                updateAmmoPix();
                dynamic_cast<TestingIcon*>(colliding.at(0))->deActivate();
            }
            else if(dynamic_cast<QualityControlIcon*>(colliding.at(0))!=NULL &&QCshown){
                removeItem(colliding.at(0));
                youWin();
            }
        }

        tester->setPos(newX,newY);


    }

}

void Game2Scene::deactivateShield(){
    hasShield=false;
    shieldTimer->stop();
    tester->setPixmap(QPixmap(":/game2 images/developer.png").scaledToHeight(35));
}

void Game2Scene::updateLifeScore(){
    if(tester->lives==0){
        youLose("run out of Lives");
    }

        removeItem(lifeCounter);
        lifeCounter=new LifeCounter(tester->lives);
        addItem(lifeCounter);
        lifeCounter->setPos(50,-150);
        soul1->show();
        soul2->show();
        soul3->show();
        if(tester->souls<3){
            soul3->hide();
        }
        if(tester->souls<2){
            soul2->hide();
        }
        if(tester->lives==0){
            soul1->hide();
            soul2->hide();
            soul3->hide();
        }

}

void Game2Scene::updateTimer(){
    if(remSec>0){
        remSec--;
    }
    else{
        youLose("run out of time");
    }
    updateTimerPix();
}

void Game2Scene::updateTimerPix(){
    int ones=remSec%10;
    int tenss=remSec/10;
    units->setPixmap((QPixmap(":/game2 images/num"+QString::number(ones)+".png")).scaledToHeight(100));
    tens->setPixmap((QPixmap(":/game2 images/num"+QString::number(tenss)+".png")).scaledToHeight(100));
}

void Game2Scene::updateAmmoPix(){
    int ones=ammo%10;
    int tenss=ammo/10;
    ammoUnits->setPixmap((QPixmap(":/game2 images/num"+QString::number(ones)+".png")).scaledToHeight(100));
    ammoTens->setPixmap((QPixmap(":/game2 images/num"+QString::number(tenss)+".png")).scaledToHeight(100));
}

void Game2Scene::youLose(QString reason){
    announcement->setText("You Lost!\n"+reason);
    announcement->show();
    next->setText("retry");
    next->show();
    timer->stop();

}

void Game2Scene::youWin(){
    announcement->setText("You Won");
    announcement->show();
    //save score if higher than highscore
    next->setText("proceed");
    next->show();
    timer->stop();

}

void Game2Scene::pauseOrResume(){
    if(!paused){
        paused=true;
        for(int i=0;i<bugList.count();i++){
            dynamic_cast<Bug*>(bugList.at(i))->pause();
        }
        timer->stop();
        pause->setIcon(QIcon(QPixmap(":/game2 images/play.png").scaled(100,100)));
    }
    else{
        paused=false;
        for(int i=0;i<bugList.count();i++){
            dynamic_cast<Bug*>(bugList.at(i))->resume();
        }
        timer->start(1000);
        pause->setIcon(QIcon(QPixmap(":/game2 images/pause.png").scaled(100,100)));
    }
}
