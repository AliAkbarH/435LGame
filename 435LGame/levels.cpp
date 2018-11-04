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

