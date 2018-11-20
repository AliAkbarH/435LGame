#include "qualitycontrolicon.h"
#include<QDir>

QualityControlIcon::QualityControlIcon()
{
    QDir dir;
    icon=new QPixmap(dir.absolutePath()+"/game2 images/quality.png");
    setPixmap(*icon);
}
