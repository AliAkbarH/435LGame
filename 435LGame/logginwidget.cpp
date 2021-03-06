#include "logginwidget.h"
#include <QtWidgets>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QMainWindow>
#include <QLabel>
#include<QStringList>
#include<QRegExp>
#include<QFileDialog>
#include <iostream>
#include<QFile>
#include<fstream>
#include"gameswidget.h"

loggInWidget::loggInWidget(QString user)
{
    games = new QPushButton("Let's PLay!");

    games->setStyleSheet("font: bold;background-color: blue;font-size: 36px;height: 48px;width: 190px;");
    this->user=user;
    userName = new QLabel("Username: "+this->user);
    userName->setStyleSheet("font: bold;font-size: 36px;height: 38px;width: 90px;");


    GridL = new QGridLayout();
    VerticalL = new QVBoxLayout();

    setGridLayout();
    setVerticalLayout();
    setLayout(VerticalL);


    QObject::connect(games, SIGNAL(clicked()), this, SLOT(startGames()));

}

void loggInWidget::startGames(){

    gamesWidget *games = new gamesWidget(user);
    games->show();
    this->close();

}

void loggInWidget::setVerticalLayout(){

    VerticalL->addItem(GridL);
    VerticalL->addWidget(games);
    VerticalL->setSpacing(20);
}

void loggInWidget::setGridLayout(){

    QPixmap m_logo_pic;
    QLabel *displayPic = new QLabel();
    QString directory = profilePic();
    m_logo_pic.load(directory);
    displayPic->setPixmap(m_logo_pic);

    GridL->addWidget(userName, 0, 0);
    GridL->addWidget(displayPic,2,0,40,40,Qt::AlignCenter);


}

QString loggInWidget::profilePic(){
    QDir dir;
    dir.setPath(dir.path()+"/profiles");
    QString profilePicDir;

    QFile inputFile(dir.path()+"/"+user+".txt");

    if (inputFile.open(QIODevice::ReadOnly))                // to check if it is entering the file, and it is
    {
       QTextStream in(&inputFile);
       QString s=in.readLine();
       profilePicDir=profileParser(s)[5];

       inputFile.close();
    }
    else
    {
        profilePicDir = ":/Profile Images/water.gif";  // same as above comment
    }

    return profilePicDir;

}

bool loggInWidget::fileExists(QString path) {
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}

QStringList loggInWidget::profileParser(QString line){       //parse the line and return a list.

    QRegExp rx("[\t]");
    QStringList list = line.split(rx, QString::SkipEmptyParts);
    return list;
}
