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
    QDir temp;
    this->filePath=new QDir(temp.absolutePath() +filePath);
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
                    Tester *tester=new Tester();
                    addItem(scene, tester, column, row);
                }
                else if(token=='b'){
                    Bug *bug=new Bug();
                    addItem(scene, bug, column, row);
                }
                else if(token=='s'){
                    Shield *shield=new Shield();
                    addItem(scene, shield, column, row);
                }
                else if(token=='t'){
                    TestingIcon *testingIcon=new TestingIcon();
                    addItem(scene, testingIcon, column, row);
                }
                else if(token=='c'){
                    CoffeeCup *coffeeCup=new CoffeeCup();
                    addItem(scene, coffeeCup, column, row);
                }
                else if(token=='q'){
                    QualityControlIcon *QCIcon=new QualityControlIcon();
                    addItem(scene, QCIcon, column, row);
                    QCIcon->hide();
                }
                column+=20;
                encoding>>token;
            }
            row+=20;
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



