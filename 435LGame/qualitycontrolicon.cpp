#include "qualitycontrolicon.h"

QualityControlIcon::QualityControlIcon()
{
    icon=new QPixmap(":/game2 images/quality.png");
    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));
}
