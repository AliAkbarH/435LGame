#include "tester.h"
#include<QDir>

Tester::Tester()
{
    QDir dir;
    icon=new QPixmap(dir.absolutePath()+"/game2 images/detective.png");
    setPixmap((*icon).scaledToHeight(40).scaledToWidth(40));

}

void Tester::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Right && x()<=1240){
        setPos(x()+40,y());
    }
    if(event->key()==Qt::Key_Left && x()>=40){
        setPos(x()-40,y());
    }
    if(event->key()==Qt::Key_Up && y()<=640){
        setPos(x(),y()-40);
    }
    if(event->key()==Qt::Key_Down && y()>=40){
        setPos(x(),y()+40);
    }

}
