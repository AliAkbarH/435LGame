#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QtEvents>
#include <QTimer>

#include "popeye.h"
#include "locks.h"
#include "game1scene.h"
#include "gameswidget.h"
#include "gameover.h"

/**
* \file game1scene.cpp
* \brief contains Game1's class definition
*
* This is the scene where we see Popeye, Olive and the locks. Each time time popeye passes a level, the corresponding lock is hiden and popeye's
* position is updated. The let's Go Button is the button that lunches the user to the corresponding level.
*
* \author Camille Farhat & Ali Haidoura
*/

/*! \brief Setting the initial scene and object's positions.
*/

game1scene::game1scene(QString user)
{
    this->user=user;
    start = new QPushButton("Let's GO!");
    start->setStyleSheet("font: bold;background-color: orange;font-size: 36px;height: 48px;width: 170px;");

    this->addWidget(start);

    addItem(popeye);
    addItem(lock1);
    addItem(lock2);
    addItem(lock3);
    addItem(lock4);
    addItem(lock5);
    addItem(lock6);
    addItem(lock7);
    addItem(lock8);

   popeye->setPos(60,365);
   lock1->setPos(720,380);
   lock2->setPos(530,280);
   lock3->setPos(370,250);
   lock4->setPos(300,190);
   lock5->setPos(140,200);

   lock6->setScale(0.8);
   lock6->setPos(160,90);

   lock7->setScale(0.75);
   lock7->setRotation(90);
   lock7->setPos(600,100);

   lock8->setRotation(80);
   lock8->setPos(830,90);

   setBackgroundBrush(QBrush(QImage(":/Profile Images/Game1.png").scaledToHeight(512).scaledToWidth(910)));
   setSceneRect(0,0,908,510);


   popeye->setFlag(QGraphicsItem::ItemIsFocusable);
   popeye->setFocus();
   lock1->setFlag(QGraphicsItem::ItemIsFocusable);
   lock1->setFocus();
   lock2->setFlag(QGraphicsItem::ItemIsFocusable);
   lock2->setFocus();
   lock3->setFlag(QGraphicsItem::ItemIsFocusable);
   lock3->setFocus();
   lock4->setFlag(QGraphicsItem::ItemIsFocusable);
   lock4->setFocus();
   lock5->setFlag(QGraphicsItem::ItemIsFocusable);
   lock5->setFocus();
   lock6->setFlag(QGraphicsItem::ItemIsFocusable);
   lock6->setFocus();
   lock7->setFlag(QGraphicsItem::ItemIsFocusable);
   lock7->setFocus();
   lock8->setFlag(QGraphicsItem::ItemIsFocusable);
   lock8->setFocus();

   setUpCountdownTimer();

   QObject::connect(start, SIGNAL(clicked()), this, SLOT(startLevel()));


}

/*! \brief Starting the corresponsding level by calling the levelsscene constructure and updating the lock's positions accordingly.
*/
void game1scene::startLevel(){

    scene2 = new levelsscene(user);               //!< pointer to an Object of type levelsscene
    view2 = new QGraphicsView(scene2);            //!< pointer to an Object of type QGraphicsView

    view2->setFixedSize(910,512);
    view2->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view2->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    int levelNum = getLevel();

    if (levelNum==1){
       updatePosition1();
    }else if (levelNum==2){
        updatePosition2();
     }else if (levelNum==3){
        updatePosition3();
     }else if (levelNum==4){
        updatePosition4();
     }else if (levelNum==5){
        updatePosition5();
     }else if (levelNum==6){
        updatePosition6();
     }else if (levelNum==7){
        updatePosition7();
     }else if (levelNum==8){
        updatePosition8();
     }

    view2->setAlignment(Qt::AlignHCenter);
    view2->show();


}

void game1scene::hideLevelScene(){

    qDebug()<<view2->close();
    delete scene2;
    delete view2;
}

/*! \brief Getting the level number from the appropriate user text file (stored as the 10th entry)
*\param event only argument, key press
*\return int that is the Level Number
*/
int game1scene::getLevel(){
    QDir dir;
    dir.setPath(dir.path()+"/profiles");
    QString level;
    int myLevel=0;

    QFile inputFile(dir.path()+"/"+user+".txt");

    if (inputFile.open(QIODevice::ReadOnly))                //!< to check if it is entering the file, and it is
    {
       qDebug()<<"opening";
       QTextStream in(&inputFile);
       QString s=in.readAll();
       level=profileParser(s)[10];
       myLevel = level.toInt();

       inputFile.close();
    }
    else qDebug()<<"not opening";
    return myLevel;

}

/*! \brief Parsing the text file that was filled and has his attributes seperated by tabs.
 * \return List of strings
*/
QStringList game1scene::profileParser(QString line){       //parse the line and return a list.

    QRegExp rx("[\t\n]");
    QStringList list = line.split(rx, QString::SkipEmptyParts);
    return list;
}

/*! \brief Function Updating Popeye's position and hidding locks, according to the level Users' in.
*/
void game1scene::updatePosition1(){
    popeye->setPos(lock1->x(),lock1->y());

    lock2->show();
    lock3->show();
    lock4->show();
    lock5->show();
    lock6->show();
    lock7->show();
    lock8->show();

    lock1->hide();


}
/*! \brief Function Updating Popeye's position and hidding locks, according to the level Users' in.
*/
void game1scene::updatePosition2(){
    popeye->setPos(lock2->x(),lock2->y());

    lock3->show();
    lock4->show();
    lock5->show();
    lock6->show();
    lock7->show();
    lock8->show();

    lock2->hide();
    lock1->hide();
}
/*! \brief Function Updating Popeye's position and hidding locks, according to the level Users' in.
*/
void game1scene::updatePosition3(){
    popeye->setPos(lock3->x(),lock3->y());


    lock4->show();
    lock5->show();
    lock6->show();
    lock7->show();
    lock8->show();

    lock3->hide();
    lock2->hide();
    lock1->hide();
}
/*! \brief Function Updating Popeye's position and hidding locks, according to the level Users' in.
*/
void game1scene::updatePosition4(){
    popeye->setPos(lock4->x(),lock4->y());

    lock5->show();
    lock6->show();
    lock7->show();
    lock8->show();

    lock4->hide();
    lock3->hide();
    lock2->hide();
    lock1->hide();
}
/*! \brief Function Updating Popeye's position and hidding locks, according to the level Users' in.
*/
void game1scene::updatePosition5(){
    popeye->setPos(lock5->x(),lock5->y());

    lock6->show();
    lock7->show();
    lock8->show();

    lock5->hide();
    lock4->hide();
    lock3->hide();
    lock2->hide();
    lock1->hide();
}
/*! \brief Function Updating Popeye's position and hidding locks, according to the level Users' in.
*/
void game1scene::updatePosition6(){
    popeye->setPos(lock6->x(),lock6->y());

    lock7->show();
    lock8->show();

    lock6->hide();
    lock5->hide();
    lock4->hide();
    lock3->hide();
    lock2->hide();
    lock1->hide();
}
/*! \brief Function Updating Popeye's position and hidding locks, according to the level Users' in.
*/
void game1scene::updatePosition7(){
    popeye->setPos(lock7->x(),lock7->y());


    lock8->show();

    lock7->hide();
    lock6->hide();
    lock5->hide();
    lock4->hide();
    lock3->hide();
    lock2->hide();
    lock1->hide();
}
/*! \brief Function Updating Popeye's position and hidding locks, according to the level Users' in.
*/
void game1scene::updatePosition8(){
    popeye->setPos(lock8->x(),lock8->y());
    lock8->hide();
    lock7->hide();
    lock6->hide();
    lock5->hide();
    lock4->hide();
    lock3->hide();
    lock2->hide();
    lock1->hide();
}

/**
 * \brief Initializes TextItem that indicates the Countdown at the start of each level
 */
void game1scene::setUpCountdownTimer() {
    countDownText = new QGraphicsTextItem();
    addItem(countDownText);
    countDownText->setZValue(2);
    countDownText->setPos(370,-35);
    countDownText->setDefaultTextColor(QColor("yellow"));
    countDownText->setTransform(QTransform::fromScale(5,5));
    countdownTimer = new QTimer();
    connect(countdownTimer,SIGNAL(timeout()),this,SLOT(updateCountdownTimer()));
    updateCountdownTimer();
    countdownTimer->start(1000);

}
/**
 * \brief update SLOT that controls the Countdown to display it when adjusted, every second
 */
void game1scene::updateCountdownTimer() {
    countdown--;
    if(countdown == 0) {
        countdownTimer->stop();

        gameOver *over = new gameOver();
        over->setGeometry(100,100,100,100);
        over->show();
    }
    else {
        int minutes;
        QString timeOutput;

        minutes = countdown / 60;
        if(minutes < 10){
            timeOutput = "0"+QString::number(int(minutes%60))+":"+QString::number(int(countdown%60));
        }
        else{
           timeOutput = QString::number(int(minutes%60))+":"+QString::number(int(countdown%60));
           countDownText->setPlainText(timeOutput);
        }
    }
}
