#include "tester.h"
#include<QTimer>

Tester::Tester(int x, int y)
{
    icon=new QPixmap(":/game2 images/developer.png");
    setPixmap((*icon).scaledToHeight(35));
    startingX=x;
    startingY=y;
    souls=3;
    lives=5;

}

void Tester::decrementLives(){
    souls--;
    if(souls==0){
        souls=3;
        lives--;
        if(lives>0){
            setPos(startingX,startingY);
        }
        else{
            //youLost
        }
    }
}

void Tester::loseLife(){
    lives--;
}

void Tester::drinkCoffee(){
    lives++;
    if(lives>5){
        lives=5;
        souls=3;
    }
}


