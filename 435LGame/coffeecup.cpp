#include "coffeecup.h"

CoffeeCup::CoffeeCup()
{
    icon=new QPixmap(":/game2 images/coffee.png");
    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
}
