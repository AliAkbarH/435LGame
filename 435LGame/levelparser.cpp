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
        QTextStream encoding(levelFile);
        QChar endToken;
        int row=0, column=0;
        encoding>>endToken;
        while(endToken!='\t'){
            QChar token=endToken;
            while(token!='\n'){
                if(token=='x'){
                    Wall *wall=new Wall();
                    addItem(scene, wall, column, row);
                }
                else if(token=='u'){
                    scene->tester=new Tester(column+3,row+3);
                    scene->addItem(scene->tester);
                    scene->tester->setPos(column+3,row+3);
                }
                else if(token=='b'){
                    Bug *bug=new Bug(scene);
                    addItem(scene, bug, column, row);
                    scene->bugList.append(bug);
                }
                else if(token=='s'){
                    Shield *shield=new Shield();
                    addItem(scene, shield, column, row);
                }
                else if(token=='T'){
                    TestingIcon *testingIcon=new TestingIcon();
                    addItem(scene, testingIcon, column, row);
                }
                else if(token=='c'){
                    CoffeeCup *coffeeCup=new CoffeeCup();
                    addItem(scene, coffeeCup, column, row);
                }
                else if(token=='q'){
                    scene->QCIcon=new QualityControlIcon();
                    scene->QCIcon->setPos(column,row);
                    scene->addItem(scene->QCIcon);
                    scene->QCIcon->hide();
                }
                column+=40;
                encoding>>token;
            }
            row+=40;
            column=0;
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
}



