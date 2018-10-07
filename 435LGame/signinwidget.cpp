#include "signinwidget.h"
#include"logginwidget.h"
#include <QtWidgets>
#include <QObject>


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

    loggInWidget *login = new loggInWidget();
    this->close();
    login->show();
}

void signInWidget::setVerticalLayout(){

    VerticalL->addWidget(signIn, 0, 0);
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
