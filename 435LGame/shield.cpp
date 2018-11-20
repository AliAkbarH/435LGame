#include "shield.h"

Shield::Shield()
{
    icon=new QPixmap(":/game2 images/shield.png");

    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
}
