#include "tester.h"
#include<QDir>

Tester::Tester()
{
    QDir dir;
    icon=new QPixmap(dir.absolutePath()+"/game2 images/detective.png");
    setPixmap(*icon);
}
