#include "logonwidget.h"

LogOnWidget::LogOnWidget(QWidget *parent) : QWidget(parent)
{
    SignInButton=new QPushButton("Sign In");
    SignUpButton=new QPushButton("Sign Up");
    GuestButton=new QPushButton("Log in as Guest");
    TitleLabel=new QLabel("Welcome to Our Game");
    InfoLabel=new QLabel("Created by Ali Haidoura and Camille Farhat for EECE435L");
    Scene=new QGraphicsScene();
    Scene->setBackgroundBrush(QBrush(QImage(":/images/background.jpeg").scaledToHeight(700)
                              .scaledToWidth(450)));
    VerticalLayout=new QVBoxLayout();
    VerticalLayout->addWidget(TitleLabel);
    VerticalLayout->addWidget(SignInButton);
    VerticalLayout->addWidget(SignUpButton);
    VerticalLayout->addWidget(GuestButton);
    VerticalLayout->addWidget(InfoLabel);
    setLayout(VerticalLayout);
    setStyleSheet("background-image: "
                  "/home/eece435l/Documents/Qt Projects/Lab2/images/background.png)");
    resize(450,700);
    connect(SignUpButton,SIGNAL(pressed()),this,SLOT(GotoSignUpPage()));

}

void LogOnWidget::GotoSignUpPage(){
    SignUpWidget *SignUp=new SignUpWidget();
    SignUp->show();
}
