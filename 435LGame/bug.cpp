#include "bug.h"


Bug::Bug()
{

    icon=new QPixmap(":/images/bug.png");

    *icon=icon->scaledToHeight(40).scaledToWidth(40);
    setPixmap(*icon);
}
