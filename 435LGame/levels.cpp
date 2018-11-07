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

        lifes = 5;

        break;
    case 3:
        hintNumber = 0;
        hint[0]="First hint";
        hint[1]="Second hint";
        hint[2]="Third hint";
        instructions = "Functions: \nMove(number of steps) \nrotate()\npickUp()";
        popeyeX1 = 100;
        popeyeY1 = 350;
        spinachX1 = 400;
        spinachY1 = 350;

        spinachX2 = 700;
        spinachY2=200;
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

