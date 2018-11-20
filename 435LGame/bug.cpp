#include "bug.h"
#include<QDir>

Bug::Bug()
{
    QDir dir;
    icon=new QPixmap(dir.absolutePath()+"/game2 images/bug.png");
    setPixmap(*icon);
}
