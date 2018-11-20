#include "levelparser.h"
#include<QDebug>
#include<bug.h>
#include"wall.h"
#include"tester.h"
#include"testingicon.h"
#include"shield.h"
#include"coffeecup.h"
#include"qualitycontrolicon.h"


LevelParser::LevelParser(QString filePath){

    this->filePath=new QDir(filePath);
}

void LevelParser::parse(Game2Scene *scene){
    QFile *levelFile=new QFile(filePath->absolutePath());

    if(levelFile->open(QIODevice::ReadOnly)){
        qDebug()<<"file open";
        QTextStream encoding(levelFile);
        QChar endToken;
        int row=0, column=0;
        encoding>>endToken;
        while(endToken!='\t'){
            qDebug()<<"entered first loop";
            QChar token=endToken;
            while(token!='\n'){
                qDebug()<<"Entered second loop";
                if(token=='x'){
                    qDebug()<<"detected x";
                    Wall *wall=new Wall();
                    addItem(scene, wall, column, row);
                }
                else if(token=='u'){
                    qDebug()<<"detected u";
                    scene->tester=new Tester();
                    scene->addItem(scene->tester);
                    scene->tester->setPos(column,row);
                }
                else if(token=='b'){
                    qDebug()<<"detected b";
                    Bug *bug=new Bug();
                    addItem(scene, bug, column, row);
                }
                else if(token=='s'){
                    qDebug()<<"detected s";
                    Shield *shield=new Shield();
                    addItem(scene, shield, column, row);
                }
                else if(token=='T'){
                    qDebug()<<"detected T";
                    TestingIcon *testingIcon=new TestingIcon();
                    addItem(scene, testingIcon, column, row);
                }
                else if(token=='c'){
                    qDebug()<<"detected c";
                    CoffeeCup *coffeeCup=new CoffeeCup();
                    addItem(scene, coffeeCup, column, row);
                }
                else if(token=='q'){
                    qDebug()<<"detected c";
                    QualityControlIcon *QCIcon=new QualityControlIcon();
                    addItem(scene, QCIcon, column, row);
                    QCIcon->hide();
                }
                column+=40;
                qDebug()<<"incremented column to "<<column;
                encoding>>token;
            }
            row+=40;
            qDebug()<<"incremented row to "<<row;
            column=0;
            qDebug()<<"resetted column to "<<column;
            encoding>>endToken;

        }
    }
    else{
        qDebug()<<"can't open file";
    }
}

void LevelParser::addItem(Game2Scene *scene, QGraphicsItem *item, int column, int row){
    scene->addItem(item);
    item->setPos(column,row);
    item->show();
    qDebug()<<"added item";
}



