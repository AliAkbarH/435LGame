#include "wall.h"

Wall::Wall()
{
    qsrand(0);
    int bit=qrand()%2;
    if(bit==0){
        icon=new QPixmap("/game2 images/zero.png");
    }
    else{
        icon=new QPixmap("/game2 images/one.png");
    }
    setPixmap(*icon);
}
