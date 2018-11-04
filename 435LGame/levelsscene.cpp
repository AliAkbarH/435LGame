#include "levelsscene.h"
#include "levels.h"
#include "hints.h"
#include "lost.h"


levelsscene::levelsscene(QString user)
{
    this->user=user;
    l = new levels(getLevel());

    run = new QPushButton("Run");
    hint = new QPushButton("Hint");
    pause = new QPushButton("Pause");
    retry = new QPushButton("Retry");

    text = new QTextEdit();
    instructions = new QLabel(l->instructions);


    run->setStyleSheet("font: bold;background-color: red;font-size: 15px;height: 25px;width: 70px;");
    hint->setStyleSheet("font: bold;background-color: blue;font-size: 15px;height: 25px;width: 70px;");
    pause->setStyleSheet("font: bold;background-color: white;font-size: 15px;height: 25px;width: 70px;");
    retry->setStyleSheet("font: bold;background-color: yellow;font-size: 15px;height: 25px;width: 70px;");

    text->setFixedHeight(130);

    addWidget(retry)->moveBy(830,0);
    addWidget(instructions)->moveBy(700,70);
    addWidget(text)->moveBy(80,50);
    addWidget(run)->moveBy(110,200);
    addWidget(hint)->moveBy(230,200);
    addWidget(pause);

    addItem(popeye);
    popeye->setScale(1.2);
    popeye->setPos(l->popeyeX1,l->popeyeY1);


    addItem(spinach1);
    spinach1->setPos(l->spinachX1,l->spinachY1);

    if(l->spinachX2!=0){                    //!< if the levels has ot not other spinach cans
        addItem(spinach1);
        spinach1->setPos(l->spinachX2,l->spinachY2);
    }
    if(l->spinachX3!=0){
        addItem(spinach3);
        spinach1->setPos(l->spinachX3,l->spinachY3);
    }


    setBackgroundBrush(QBrush(QImage(":/Profile Images/background.PNG").scaledToHeight(600).scaledToWidth(1000)));
    setSceneRect(0,0,908,510);


    popeye->setFlag(QGraphicsItem::ItemIsFocusable);
    popeye->setFocus();
    spinach1->setFlag(QGraphicsItem::ItemIsFocusable);
    spinach1->setFocus();


    QObject::connect(run, SIGNAL(clicked()), this, SLOT(checkAnswer()));
    QObject::connect(hint, SIGNAL(clicked()), this, SLOT(displayHint()));
    QObject::connect(pause, SIGNAL(clicked()), this, SLOT(pauseLevel()));
    QObject::connect(retry, SIGNAL(clicked()), this, SLOT(retryLevel()));



}

void levelsscene::levelssceneTimer(){           //!< function to set up the timer INCOMPLETE

timerPreview = new QGraphicsTextItem();
//addItem(timer);
//timerPreview->setPlainText(QString::number(timer));
timerPreview->setPos(300,-50);
timer = new QTimer();

}


int levelsscene::getLevel(){             //!<To get the level number from the text file (stored as the 10th entry)
    QDir dir;
    dir.setPath(dir.path()+"/profiles");
    QString profilePicDir;
    int levelNum=1;

    QFile inputFile(dir.path()+"/"+user+".txt");

    if (inputFile.open(QIODevice::ReadOnly))                // to check if it is entering the file, and it is
    {
       QTextStream in(&inputFile);
       QString s=in.readLine();
       profilePicDir=profileParser(s)[9];
       levelNum = profilePicDir.toInt();

       inputFile.close();
    }
    return levelNum;

}

void levelsscene::checkAnswer(){                 //!< INCOMPLETE run push button function
    QString input = text->toPlainText();

    QRegExp rx("[() \n]");
    QStringList list = input.split(rx, QString::SkipEmptyParts);

    qDebug() << list.at(0);              //!< to display on the console
    qDebug() << list.at(1);

    if (list.at(0)=="Move"){
        QString newx = list.at(1);
        int newX =newx.toInt() + l->popeyeX1;

        popeye->setPos(newX,l->popeyeY1);

        if(!this->collidingItems(popeye).isEmpty() && list.at(2)=="pickUp"){
            this->removeItem(spinach1);
        }else {
           youLost();
        }
    }
}

void levelsscene::youLost(){


    if (l->lifes>0){
        l->decrementLifes();

        lost *loose = new lost(l->lifes);
        loose->setGeometry(100,100,100,100);

        loose->show();
    }
}

void levelsscene::displayHint(){         //!< displaying the 3 hints and repeating them if passed over all of them

    int hintNumber = l->hintNumber;
    if (hintNumber==3){
        l->resetHintNumber();
        hintNumber = l->hintNumber;
    }
    hints *hint = new hints(l->hint[hintNumber]);
    hint->setGeometry(100,100,100,100);

    hint->show();

    l->incrementHintNumber();
}

void levelsscene::pauseLevel(){

}

void levelsscene::retryLevel(){                  //!<retry -> reset popeye's position
    popeye->setPos(l->popeyeX1,l->popeyeY1);
}

bool levelsscene::fileExists(QString path) {
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}

QStringList levelsscene::profileParser(QString line){       //parse the line and return a list.

    QRegExp rx("[\t]");
    QStringList list = line.split(rx, QString::SkipEmptyParts);
    return list;
}
