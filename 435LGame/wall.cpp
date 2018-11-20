#include "wall.h"
#include <QDir>

Wall::Wall()
{
    qsrand(0);
    int bit=qrand()%2;
    QDir dir;
    if(bit==0){
        icon=new QPixmap(dir.absolutePath()+"/game2 images/zero.png");
    }
    else{
        icon=new QPixmap(dir.absolutePath()+"/game2 images/one.png");
    }
    setPixmap(*icon);
}
