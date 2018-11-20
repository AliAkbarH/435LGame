#include "coffeecup.h"

CoffeeCup::CoffeeCup()
{
    icon=new QPixmap(":/images/coffee.png");
    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
}
