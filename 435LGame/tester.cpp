#include "tester.h"
#include<QDir>

Tester::Tester()
{
    QDir dir;
    icon=new QPixmap(dir.absolutePath()+"/game2 images/detective.png");
    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
    int i=0;
    QObject::connect(timer,SIGNAL(timeout()),this,step(i));
}




