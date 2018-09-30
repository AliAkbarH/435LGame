#include "signupwidget.h"

SignUpWidget::SignUpWidget(QWidget *parent) : QWidget(parent)
{
    FirstName=new QLabel("First Name");
    LastName=new QLabel("Last Name");
    UserName=new QLabel("Username");
    Password=new QLabel("Password");
    ConfirmPass=new QLabel("Confirm Password");
    ProfilePic=new QLabel("Profile Picture");
    Gender=new QLabel("Gender");
    First=new QLineEdit("First Name");
    Last=new QLineEdit("Last Name");
    User=new QLineEdit("Username");
    Pass=new QLineEdit("Password");
    Confirm=new QLineEdit("Confirm Password");
    Submit=new QPushButton("Submit");
    Male=new QRadioButton("Male");
    Female=new QRadioButton("Female");
    GridLayout=new QGridLayout;
    VerticalLayout=new QVBoxLayout;


    GridLayout->addWidget(FirstName,0,0,1,2);
    GridLayout->addWidget(First,1,0,1,2);
    GridLayout->addWidget(LastName,2,0,1,2);
    GridLayout->addWidget(Last,3,0,1,2);
    GridLayout->addWidget(Gender,4,0);
    GridLayout->addWidget(Male,4,1);
    GridLayout->addWidget(Female,5,1);
    GridLayout->addWidget(UserName,6,0,1,2);
    GridLayout->addWidget(User,7,0,1,2);
    GridLayout->addWidget(Password,8,0,1,2);
    GridLayout->addWidget(Pass,9,0,1,2);
    GridLayout->addWidget(ConfirmPass,10,0,1,2);
    GridLayout->addWidget(Confirm,11,0,1,2);

    VerticalLayout->addLayout(GridLayout);
    VerticalLayout->addWidget(ProfilePic,6);
    VerticalLayout->addWidget(Submit);

    setLayout(VerticalLayout);
    resize(450,700);

}
