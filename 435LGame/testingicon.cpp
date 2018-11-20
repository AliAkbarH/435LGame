#include "testingicon.h"

TestingIcon::TestingIcon()
{
    icon=new QPixmap(":/images/test.png");

    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
}
