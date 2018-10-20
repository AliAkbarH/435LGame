#include "signinwidget.h"
#include"logginwidget.h"
#include <QtWidgets>
#include <QObject>
#include<QStringList>
#include<QRegExp>
#include<QFileDialog>
#include <iostream>
#include<QFile>
#include<fstream>



signInWidget::signInWidget(QWidget *parent) : QWidget(parent)
{
    submit = new QPushButton("Submit");
    submit->setStyleSheet("background-color: white;font-size: 30px;height: 40px;width: 90px;");

    signIn = new QLabel("Sign IN");
    signIn->setStyleSheet("font-size: 36px;height: 38px;width: 90px;");
    signIn->setAlignment(Qt::AlignCenter);

    userName = new QLabel("Username");
    password = new QLabel("Password");

    Lpassword = new QLineEdit();
    LuserName= new QLineEdit();


    Lpassword->setEchoMode(QLineEdit::Password);

    GridL = new QGridLayout();
    VerticalL = new QVBoxLayout();

    setGridLayout();
    setVerticalLayout();
    setLayout(VerticalL);


    QObject::connect(submit, SIGNAL(clicked()), this, SLOT(loggedIn()));

}

void signInWidget::loggedIn(){
    if(userValid()){
    loggInWidget *login = new loggInWidget(LuserName->text());
    this->close();
    login->show();
    }
    else return;
}

void signInWidget::setVerticalLayout(){

    VerticalL->addWidget(signIn, 0);
    VerticalL->addItem(GridL);
    VerticalL->addWidget(submit);
    VerticalL->setSpacing(50);
}

void signInWidget::setGridLayout(){

     GridL->addWidget(userName, 1, 0);
     GridL->addWidget(LuserName, 2, 0);

     GridL->addWidget(password, 3, 0);
     GridL->addWidget(Lpassword, 4, 0);

     GridL->setSpacing(15);

}

bool signInWidget::userValid(){
    QDir dir;
    dir.setPath(dir.path()+"/profiles");
    //LuserName->setText(dir.absolutePath());
    if(!fileExists(dir.path()+"/"+LuserName->text()+".txt")){
        password->setText("Password");
        userName->setText("Username Not found");
        return false;
    }
    else{
        userName->setText("Username");

        QFile *user = new QFile(dir.path()+"/"+LuserName->text()+".txt");
        user->open(QIODevice::ReadWrite);
        QTextStream in(user);
        QString s = in.readLine();
        QString Password = profileParser(s)[4];



        if(Lpassword->text()!=Password){
            password->setText("Incorrect Password");
            return false;
        }

        user->close();


    }
    userName->setText("Username");
    password->setText("Password");

    return true;
}

bool signInWidget::fileExists(QString path) {
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}

QStringList signInWidget::profileParser(QString line){       //pars the line and return a list.

    QRegExp rx("[\t]");
    QStringList list = line.split(rx, QString::SkipEmptyParts);
    return list;
}

