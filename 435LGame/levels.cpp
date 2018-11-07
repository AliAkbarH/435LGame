#include "levels.h"

levels::levels(int x)
{
    this->levelNumb = x;
    switch(levelNumb){
    case 1:                                                //switched with 5th
        hintNumber = 0;
        hint[0]="First hint";
        hint[1]="Second hint";
        hint[2]="Third hint";
        instructions = "Functions: \nMove(number of steps) \npickUp()";
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
        instructions = "Functions: \nMove(number of steps) \npickUp()";
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
        instructions = "Functions: \nMove(number of steps) \nRotate()\npickUp()";
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
        instructions = "Functions: \nMove(number of steps) \nRotate() \nBoat.Move(number of steps) \npickUp()";

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
        instructions = "Functions: \nMove(number of steps) \nRotate() \nBoat.Move(number of steps) \nBoat.Rotate() \npickUp()";

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
        instructions = "Functions: \nRepeat(number of time):[steps to repeat] \nMove(number of steps) \nRotate() \npickUp()";

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
        instructions = "Functions: \nRepeat(number of time):[steps to repeat] \nMove(number of steps) \nRotate() \nBoat.Move(number of steps) \npickUp()";

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

    }

}
void levels::decrementLifes(){
    this->lifes--;
}

void levels::incrementLevelNumb(){
    levelNumb++;

}

void levels::incrementHintNumber(){
    this->hintNumber++;
}
void levels::resetHintNumber(){
    this->hintNumber=0;
}
void levels::setPopeyeX1(int newX){
    this->popeyeX1=newX;
}
void levels::setPopeyeY1(int newY){
    this->popeyeY1=newY;
}
void levels::updateLevel(QString user){
                //!<To update the level number in the text file (stored as the 10th entry)
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

