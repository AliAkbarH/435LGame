#include "wall.h"
#include<QDir>

Wall::Wall()
{
    QDir dir;
    qsrand(0);
    int bit=qrand()%2;
    if(bit==0){
        icon=new QPixmap(dir.absolutePath()+"/game2 images/zero.png");

        *icon=icon->scaledToHeight(40).scaledToWidth(40);
    }
    else{
        icon=new QPixmap(dir.absolutePath()+"/game2 images/one.png");
        *icon=icon->scaledToHeight(40).scaledToWidth(40);
    }
    setPixmap(*icon);
}
