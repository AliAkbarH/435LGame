#include "coffeecup.h"
#include<QDir>

CoffeeCup::CoffeeCup()
{

    QDir dir;
    icon=new QPixmap(dir.absolutePath()+"/game2 images/coffee.png");
    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
}
