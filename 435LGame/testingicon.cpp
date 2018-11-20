#include "testingicon.h"

TestingIcon::TestingIcon()
{
    icon=new QPixmap(":/game2 images/test.png");

    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
}
