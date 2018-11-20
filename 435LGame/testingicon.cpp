#include "testingicon.h"
#include<QDir>

TestingIcon::TestingIcon()
{
    QDir dir;
    icon=new QPixmap(dir.absolutePath()+"/game2 images/test.png");
    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
}
