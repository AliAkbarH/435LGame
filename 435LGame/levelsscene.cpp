#include "levelsscene.h"
#include "levels.h"
#include "hints.h"
#include "lost.h"
#include "won.h"
#include"instruction.h"
#include"boat.h"

/**
* \file levelsscene.cpp
* \brief Contains Game1's class definition
*
*
* This file is creating the enviorment of our game. Setting everything from background image to the timer, popeye,
* the spinach cans, the boat and the river obstacles and other level-specific specifications.
* The user will be writing code into the text editor. This code will be chekcked and popeye will move accordingly.
*
* \author Camille Farhat & Ali Haidoura
*/


/*! \brief The constructor the this class is called, everytime the user clicks on the Let's Go! Button and thus, the corresponding level is loaded
* from the appropriate text file.
* Each Level have different specs and object that are loaded to their appropriate positions.
*/

levelsscene::levelsscene(QString user)
{
    this->user=user;
    int myLevel = getLevel();
    l = new levels(myLevel,user);

    run = new QPushButton("Run");
    hint = new QPushButton("Hint");
    pause = new QPushButton("Pause");
    retry = new QPushButton("Retry");
    proceed=new QPushButton("Continnue");

    text = new QTextEdit();
    instructions = new QLabel(l->instructions);


    run->setStyleSheet("font: bold;background-color: red;font-size: 15px;height: 25px;width: 70px;");
    hint->setStyleSheet("font: bold;background-color: blue;font-size: 15px;height: 25px;width: 70px;");
    pause->setStyleSheet("font: bold;background-color: white;font-size: 15px;height: 25px;width: 70px;");
    retry->setStyleSheet("font: bold;background-color: yellow;font-size: 15px;height: 25px;width: 70px;");
    proceed->setStyleSheet("font: bold;background-color: green;font-size: 15px;height: 25px;width: 70px;");

    text->setFixedHeight(130);

    addWidget(retry)->moveBy(830,0);
    addWidget(instructions)->moveBy(700,70);
    addWidget(text)->moveBy(80,50);
    addWidget(run)->moveBy(110,200);
    addWidget(hint)->moveBy(230,200);

    if (myLevel!=1){                    //!< User can only pause after level 1 is completed
        addWidget(pause);
    }



    if(myLevel==4){
        addItem(river1);
        river1->setPos(l->river1X,l->river1Y);
        river1->setFlag(QGraphicsItem::ItemIsFocusable);
        river1->setFocus();

        addItem(boat1);
        boat1->setPos(l->boat1X,l->boat1Y);
        boat1->setFlag(QGraphicsItem::ItemIsFocusable);
        boat1->setFocus();
    }else if (myLevel == 6){
        addItem(obstacle);
        obstacle->setPos(l->obstacleX,l->obstacleY);
        obstacle->setFlag(QGraphicsItem::ItemIsFocusable);
        obstacle->setFocus();
    }else if (myLevel ==7){
        addItem(river1);
        river1->setPos(l->river1X,l->river1Y);
        river1->setFlag(QGraphicsItem::ItemIsFocusable);
        river1->setFocus();

        addItem(boat1);
        boat1->setPos(l->boat1X,l->boat1Y);
        boat1->setFlag(QGraphicsItem::ItemIsFocusable);
        boat1->setFocus();

        addItem(smallRiver1);
        smallRiver1->setPos(l->smallRiver1X,l->smallRiver1Y);
        smallRiver1->setFlag(QGraphicsItem::ItemIsFocusable);
        smallRiver1->setFocus();

        addItem(smallRiver2);
        smallRiver2->setPos(l->smallRiver2X,l->smallRiver2Y);
        smallRiver2->setFlag(QGraphicsItem::ItemIsFocusable);
        smallRiver2->setFocus();
    }


    addItem(spinach1);
    spinach1->setPos(l->spinachX1,l->spinachY1);
    spinach1->setFlag(QGraphicsItem::ItemIsFocusable);
    spinach1->setZValue(2);
    spinach1->setFocus();

    if(l->spinachX2!=0){                    //!< if the levels has ot not other spinach cans
        addItem(spinach2);
        spinach2->setPos(l->spinachX2,l->spinachY2);
        spinach2->setFlag(QGraphicsItem::ItemIsFocusable);
        spinach2->setZValue(2);
        spinach2->setFocus();
    }
    if(l->spinachX3!=0){
        addItem(spinach3);
        spinach3->setPos(l->spinachX3,l->spinachY3);
        spinach3->setFlag(QGraphicsItem::ItemIsFocusable);
        spinach3->setZValue(2);
        spinach3->setFocus();
    }


    if ((myLevel!=5) && (myLevel!=8)){
    setBackgroundBrush(QBrush(QImage(":/Profile Images/background.PNG").scaledToHeight(600).scaledToWidth(1000)));
    setSceneRect(0,0,908,510);
    }else {
        setBackgroundBrush(QBrush(QImage(":/Profile Images/backgroundLevel5.jpg").scaledToHeight(600).scaledToWidth(1000)));
        setSceneRect(0,0,908,510);

        addItem(boat1);
        boat1->setPos(l->boat1X,l->boat1Y);
        boat1->setFlag(QGraphicsItem::ItemIsFocusable);
        boat1->setFocus();

        addItem(rock1);
        rock1->setPos(l->rock1X,l->rock1Y);
        rock1->setFlag(QGraphicsItem::ItemIsFocusable);
        rock1->setFocus();
    }


    addItem(popeye);
    popeye->setScale(1.2);
    popeye->setZValue(2);
    popeye->setPos(l->popeyeX1,l->popeyeY1);
    popeye->setFlag(QGraphicsItem::ItemIsFocusable);
    popeye->setFocus();


    if(myLevel == 1){
        instruction *inst = new instruction();
        inst->setGeometry(100,100,100,100);
        inst->show();
    }

    setUpCountdownTimer();

    QObject::connect(run, SIGNAL(clicked()), this, SLOT(checkAnswer()));
    QObject::connect(hint, SIGNAL(clicked()), this, SLOT(displayHint()));
    QObject::connect(pause, SIGNAL(clicked()), this, SLOT(pauseLevel()));
    QObject::connect(retry, SIGNAL(clicked()), this, SLOT(retryLevel()));
    QObject::connect(proceed, SIGNAL(clicked()), this, SLOT(hideScene()));



}

/*! \brief Getting the level number from the appropriate user text file (stored as the 10th entry)
*\param event only argument, key press
*\return int that is the Level Number
*/
int levelsscene::getLevel(){
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

/**
 * \brief Initializes TextItem that indicates the Countdown at the start of each level
 */
void levelsscene::setUpCountdownTimer() {
    countDownText = new QGraphicsTextItem();
    addItem(countDownText);
    countDownText->setZValue(2);
    countDownText->setPos(370,-35);
    countDownText->setDefaultTextColor(QColor("black"));
    countDownText->setTransform(QTransform::fromScale(5,5));
    countdownTimer = new QTimer();
    connect(countdownTimer,SIGNAL(timeout()),this,SLOT(updateCountdownTimer()));

    updateCountdownTimer();
    countdownTimer->start(1000);

}
/**
 * \brief update SLOT that controls the Countdown to display it when adjusted, every second
 */
void levelsscene::updateCountdownTimer() {
    countdown--;
    if(countdown == 0) {
        countdownTimer->stop();
        youLost(true);
    }
    else {
        int minutes;
        QString timeOutput;

        minutes = countdown / 60;
        timeOutput = QString::number(int(minutes%60))+":"+QString::number(int(countdown%60));
        countDownText->setPlainText(timeOutput);
    }
}

/*! \brief Decrementing lifes, score and showing appropriate pop up window when users' looses
*/
void levelsscene::youLost(bool timeIsUp){

    if(timeIsUp == false){
        if (l->lifes>1){
            l->decrementLifes();
            l->decrementScore();

            l->updateScore(user);

            lost *loose = new lost(l->lifes);
            loose->setGeometry(100,100,100,100);

            loose->show();
        }else {

            l->updateLevelOne(user);    //!<reset the user to level 1
            l->resetHintNumber();
            l->resetLives();
            l->resetScore();

            l->updateScore(user);

            retryLevel();

            lost *loose = new lost(l->lifes);
            loose->setGeometry(100,100,100,100);

            loose->show();

        }
    }else {

        l->updateLevelOne(user);    //!<reset the user to level 1
        l->resetHintNumber();
        l->resetLives();
        l->resetScore();

        retryLevel();
        lost *loose = new lost(0);
        loose->setGeometry(100,100,100,100);

        loose->show();
    }
}
/*! \brief Incrementing score, proceeding to the game1scene and showing appropriate pop up window when user wins
*/
void levelsscene::youWon(){

    for (int i=0;i<l->lifes;i++){       //!<Increment the score according the count of lifes, the higher the lifes, the higher the score
        l->incrementScore();
    }

    for(int j=0; j<(countdown/5);j++){     //!< Increment the score according to the player's time
        l->incrementScore();
    }

    Won *winWidget=new Won(l->levelNumb,l->lifes);
    winWidget->setGeometry(100,100,100,100);
    winWidget->show();

    l->updateLevel(user);
    l->updateScore(user);

    addWidget(proceed)->moveBy(800,450);

}
/*! \brief Displaying the 3 hints and repeating them if passed over all of them and decrement score accordingly
*/
void levelsscene::displayHint(){

    int hintNumber = l->hintNumber;
    if (hintNumber==3){
        l->resetHintNumber();
        hintNumber = l->hintNumber;
    }
    hints *hint = new hints(l->hint[hintNumber]);
    hint->setGeometry(100,100,100,100);

    hint->show();

    l->incrementHintNumber();
    l->decrementScore();
}
/*! \brief Pause the level the user's in
*/
void levelsscene::pauseLevel(){                 //!<Since everything is loaded from the text file; the lives, scores, timer and level number, the pause simply closes the scene and when the user
                                                //!<re-logs in, he just continues where he left off when he clicks on the Let's Start! button
    this->views()[0]->hide();
}

/*! \brief Retry level and reset positons to initial hard coded positions
*/
void levelsscene::retryLevel(){                  //!<retry -> reset popeye's position

    removeItem(spinach1);
    addItem(spinach1);
    spinach1->setPos(l->spinachX1,l->spinachY1);

    if(l->spinachX2!=0){                        //!< if the levels has ot not other spinach cans
        removeItem(spinach2);
        addItem(spinach2);
        spinach2->setPos(l->spinachX2,l->spinachY2);
    }
    if(l->spinachX3!=0){
        removeItem(spinach3);
        addItem(spinach3);
        spinach3->setPos(l->spinachX3,l->spinachY3);
    }
    if(l->boat1X!=0){
        removeItem(boat1);
        addItem(boat1);
        boat1->setPos(l->boat1X,l->boat1Y);
    }


    popeye->setPos(l->popeyeX1,l->popeyeY1);
}

/*! \brief Functions that checks if the file exists before using it
*/
bool levelsscene::fileExists(QString path) {
    QFileInfo check_file(path);

    //!< check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}

/*! \brief Parsing the text file that was filled and has his attributes seperated by tabs.
 * \return List of strings
*/
QStringList levelsscene::profileParser(QString line){       //parse the line and return a list.

    QRegExp rx("[\t\n]");
    QStringList list = line.split(rx, QString::SkipEmptyParts);
    return list;
}

/*! \brief Hide the levelsscene
*/
void levelsscene::hideScene(){
    views().at(0)->close();
    delete this;

}

/*! \brief Checking the User's input and moving popeye and the boat accordingly. If the User Clicks on the pickUp Spinach cans dissapear.
*/
void levelsscene::checkAnswer(){                 //!< Run push button function
    int myLevel = getLevel();

    QString input = text->toPlainText();

    QRegExp rx("[( ) ; : \n]");
    QStringList list = input.split(rx, QString::SkipEmptyParts);
    int direction=0;                            //!<direction of movement, 0 to the right and anticlockwise
    int boatDirection = 0;

    QString iterations = "1";                   //!<check the argument of the Repeat(args) from the user
    int i =0;
    bool repeat = false;


    QString checkForRepeat = list.at(0);
    if (checkForRepeat=="Repeat" || checkForRepeat=="repeat"){
        iterations = list.at(1);                //!<get the number of iterations
        i=2;                                    //!<start reading after we get the number of iterations
        repeat = true;
    }

    for (int j = 0; j<iterations.toInt() ; j++){            //!< iterate j times over the user's Code
        for(i ; i<list.size();i++){                         //!< i is either = 0 or 2 and at the end of the first for loop i is reseted to 2 if there is repetition
            QString command=list.at(i);
             // qDebug()<<command;

            if((command=="Move") && myLevel!=5){      //!popeye cannot move in level 5; boat collides with him only

                QString newpos = list.at(i+1);
              //  qDebug()<<newpos;
                int displacement =newpos.toInt()*50;

                switch(direction){
                case 0:
                    if (myLevel == 6){                                  //!to check if popeye can pass on the bridge or if there is a river
                        if(popeye->y()<610 && popeye->y()>590) {
                            popeye->setPos(popeye->x()+displacement,popeye->y());
                        }
                    }else{
                        popeye->setPos(popeye->x()+displacement,popeye->y());
                    }
                    break;
                case 1:
                    if (myLevel == 7){
                        if(popeye->collidesWithItem(boat1)){
                             popeye->setPos(popeye->x(),popeye->y()-displacement);
                        }
                    }else {
                        popeye->setPos(popeye->x(),popeye->y()-displacement);
                    }
                    break;
                case 2:
                    if (myLevel == 6){
                        if(popeye->y()<610 && popeye->y()>590){
                    popeye->setPos(popeye->x()-displacement,popeye->y());
                    }else{
                        popeye->setPos(popeye->x()-displacement,popeye->y());
                    }
                    break;
                case 3:
                    if (myLevel == 7 && popeye->collidesWithItem(boat1)){
                    popeye->setPos(popeye->x(),popeye->y()+displacement);
                    }else{
                        popeye->setPos(popeye->x(),popeye->y()+displacement);
                    }
                    break;
                default:
                    popeye->setPos(popeye->x()+displacement,popeye->y());
                    break;
                }
                i++;
            }
            }
            else if(command=="Boat.Move"){   //!<If popeye collides with the boat, they should both move in the same manner if Boat.Move is inputed
                QString newpos = list.at(i+1);
                int displacement =newpos.toInt()*50;

                if(myLevel ==7){                                            //!<In level 7 the boat can only move on a horizontal line
                    if (boat1->collidesWithItem(popeye)){
                        boat1->setPos(boat1->x()+displacement,boat1->y());
                        popeye->setPos(popeye->x()+displacement,popeye->y());
                    }else{
                        boat1->setPos(boat1->x()+displacement,boat1->y());
                    }
                }else{
                if (boat1->collidesWithItem(popeye)){
                    switch(boatDirection){
                    case 0:
                        boat1->setPos(boat1->x()+displacement,boat1->y());
                        popeye->setPos(popeye->x()+displacement,popeye->y());
                        break;
                    case 1:
                        boat1->setPos(boat1->x(),boat1->y()-displacement);
                        popeye->setPos(popeye->x(),popeye->y()-displacement);

                        break;
                    case 2:
                        boat1->setPos(boat1->x()-displacement,boat1->y());
                        popeye->setPos(popeye->x()-displacement,popeye->y());
                        break;
                    case 3:
                        boat1->setPos(boat1->x(),boat1->y()+displacement);
                        popeye->setPos(popeye->x(),popeye->y()+displacement);
                        break;
                    default:
                        boat1->setPos(boat1->x()+displacement,boat1->y());
                        popeye->setPos(popeye->x()+displacement,popeye->y());
                        break;
                    }

                }
                else{
                    switch(boatDirection){
                    case 0:
                        boat1->setPos(boat1->x()+displacement,boat1->y());
                        break;
                    case 1:
                        boat1->setPos(boat1->x(),boat1->y()-displacement);
                        break;
                    case 2:
                        boat1->setPos(boat1->x()-displacement,boat1->y());
                        break;
                    case 3:
                        boat1->setPos(boat1->x(),boat1->y()+displacement);
                        break;
                    default:
                        boat1->setPos(boat1->x()+displacement,boat1->y());
                        break;
                    }
                }
                i++;
            }
            }
            else if(command=="Rotate"){
                direction=(direction+1)%4;                      //!< Each Rotate will rotate popeye by 90 degrees
                //qDebug()<<direction;
            }
            else if(command=="Boat.Rotate"){
                boatDirection=(boatDirection+1)%4;
                //qDebug()<<boatDirection;
            }
            else if(command=="pickUp"){
                QList<QGraphicsItem*> colliding=this->collidingItems(popeye);
                if(!colliding.isEmpty()){
                    for(int i=0;i<colliding.size();i++){
                        if (dynamic_cast<spinach*>(colliding.at(i))!=NULL)  //!<if the colliding object is of type spinach
                        {
                            removeItem(colliding.at(i));
                        }
                    }
                }
            }else {

                lost *loose = new lost(l->lifes -1 , command);      //!< decrement the number of lifes before showing it to the user and show appropriate syntax error
                loose->setGeometry(100,100,100,100);
                loose->show();
            }

        }if (repeat == true){
            i=2;
        }
    }

    QList<QGraphicsItem*> sceneItems=this->items();
    bool noMoreSpinach=true;
    for(int i=0;i<sceneItems.size();i++){
        if(dynamic_cast<spinach*>(sceneItems.at(i))!=NULL){
            noMoreSpinach=false;
        }
    }
    if(noMoreSpinach){
        youWon();
    }
    else{
        youLost(false);
    }
}





