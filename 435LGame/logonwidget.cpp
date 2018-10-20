#include "logonwidget.h"
#include "signinwidget.h"
#include"logginwidget.h"

LogOnWidget::LogOnWidget(QWidget *parent) : QWidget(parent)
{
    SignInButton=new QPushButton("Sign In");
    SignUpButton=new QPushButton("Sign Up");
    GuestButton=new QPushButton("Log in as Guest");


    TitleLabel=new QLabel("Welcome to Our Game");
    TitleLabel->setStyleSheet("font-size: 36px;height: 38px;width: 90px;");
    TitleLabel->setAlignment(Qt::AlignCenter);

    InfoLabel=new QLabel("Created by Ali Haidoura and Camille Farhat for EECE435L");

    SignInButton->setStyleSheet("font-size: 36px;height: 38px;width: 90px;");
    SignUpButton->setStyleSheet("font-size: 36px;height: 38px;width: 90px;");
    GuestButton->setStyleSheet("font-size: 36px;height: 38px;width: 90px;");

    //Scene=new QGraphicsScene();
    //Scene->setBackgroundBrush(QBrush(QImage(":/Profile Images/background.PNG").scaledToHeight(700)
                             // .scaledToWidth(450)));


    GridLayout = new QGridLayout();
    VerticalLayout = new QVBoxLayout();

    setGridLayout();
    setVerticalLayout();
    setLayout(VerticalLayout);

    //setStyleSheet("background-image: "
                 // ":/Profile Images/background.PNG)");
   // resize(450,700);

    connect(SignUpButton,SIGNAL(pressed()),this,SLOT(GotoSignUpPage()));
    connect(SignInButton,SIGNAL(pressed()),this,SLOT(GotoSignInPage()));
    connect(GuestButton,SIGNAL(pressed()),this,SLOT(LogInAsGuest()));

}

void LogOnWidget::setVerticalLayout(){

    VerticalLayout->addWidget(TitleLabel, 0);
    VerticalLayout->addItem(GridLayout);
    VerticalLayout->addWidget(InfoLabel);
    VerticalLayout->setSpacing(50);
}

void LogOnWidget::setGridLayout(){

     GridLayout->addWidget(SignInButton, 1, 0);
     GridLayout->addWidget(SignUpButton, 2, 0);
     GridLayout->addWidget(GuestButton, 3, 0);

     GridLayout->setSpacing(15);


}

void LogOnWidget::GotoSignUpPage(){
    SignUpWidget *SignUp=new SignUpWidget();

    this->close();
    SignUp->show();
}

void LogOnWidget::GotoSignInPage(){
    signInWidget *signin = new signInWidget();
    this->close();
    signin->show();
}

void LogOnWidget::LogInAsGuest(){
    loggInWidget *loggin=new loggInWidget("guest");
    this->close();
    loggin->show();
}


