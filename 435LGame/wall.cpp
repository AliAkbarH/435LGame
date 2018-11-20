#include "wall.h"

Wall::Wall()
{
    qsrand(0);
    int bit=qrand()%2;
    if(bit==0){
        icon=new QPixmap(":/game2 images/zero.png");

        *icon=icon->scaledToHeight(40).scaledToWidth(40);
    }
    else{
        icon=new QPixmap(":/images/one.png");
        *icon=icon->scaledToHeight(40).scaledToWidth(40);
    }
    setPixmap(*icon);
}
