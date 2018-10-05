#include "signupwidget.h"
#include<QFileDialog>
#include <iostream>

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
    ProfilePicture=new QPushButton("Browse");
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
    VerticalLayout->addWidget(ProfilePic);
    VerticalLayout->addWidget(ProfilePicture);
    VerticalLayout->addStretch(3);
    VerticalLayout->addWidget(Submit);

    connect(ProfilePicture,SIGNAL(pressed()),this,SLOT(AddProfilePictureSlot));
    connect(Submit,SIGNAL(pressed()),this,  SLOT(VerifySubmitSlot));
    setLayout(VerticalLayout);
    resize(450,700);

}

void SignUpWidget::AddProfilePictureSlot(){
    QString fileName= QFileDialog::getOpenFileName(this, "Select a file to open...", QDir::homePath());
    std::cout<<&fileName;
    QFile::copy(fileName, "./images/profilePic"+User->text());
}

void SignUpWidget::VerifySubmitSlot(){
    if(First->text().isNull()||First->text().isEmpty()){
        First->setText("First Name can't be empty");
        return;
    }

    if(Last->text().isNull()||Last->text().isEmpty()){
        Last->setText("Last Name can't be empty");
        return;
    }
    if(User->text().isNull()||User->text().isEmpty()){
        User->setText("Username can't be empty");
        return;
    }
    if(Pass->text().isNull()||Pass->text().isEmpty()){
        First->setText("Password can't be empty");
        return;
    }
    if(Confirm->text()!=Pass->text()){
        Confirm->setText("The Passwords are not matching");
        return;
    }
    bool hasNum=false;
    bool hasCaptial=false;
    bool hasSmall=false;
    bool hasSize=Pass->text().size()>=8;
    for(int i=0;i<Pass->text().size();i++){
        if(Pass->text()[i]>='A'&&Pass->text()[i]<='Z')hasCaptial=true;
        if(Pass->text()[i]>='a'&&Pass->text()[i]<='z')hasSmall=true;
        if(Pass->text()[i]>='0'&&Pass->text()[i]<='9')hasNum=true;

    }
    if(!(hasNum&&hasCaptial&&hasSize&&hasSmall)){
        Pass->setText("Password Not Valid");
        return;
    }

}
