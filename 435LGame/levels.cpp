#include "levels.h"

levels::levels(int x)
{
    this->levelNumb = x;
    switch(levelNumb){
    case 1:
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
        QString profilePicDir;


        QFile inputFile(dir.path()+"/"+user+".txt");

        if (inputFile.open(QIODevice::ReadWrite))                // to check if it is entering the file, and it is
        {
           QTextStream in(&inputFile);
           QString line=in.readLine();
           QRegExp toReplace("/t"+QString::number(level));
           QString replaceWith("/t"+QString::number(level+1));
           line.replace(toReplace,replaceWith);
           in<<line;

        }
        inputFile.close();
    }


}

