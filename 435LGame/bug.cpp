#include "bug.h"
#include<QDir>

Bug::Bug()
{
    QDir dir;
    icon=new QPixmap(dir.absolutePath()+"/game2 images/bug.png");

    *icon=icon->scaledToHeight(40).scaledToWidth(40);
    setPixmap(*icon);

}
