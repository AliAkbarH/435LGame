#include "shield.h"
#include<QDir>

Shield::Shield()
{
    QDir dir;
    icon=new QPixmap(dir.absolutePath()+"/game2 images/shield.png");
    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
}
