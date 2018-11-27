#include "signupwidget.h"
#include<QFileDialog>
#include <iostream>
#include<QFile>
#include<fstream>
#include<string>
#include<QJsonObject>
#include<QJsonDocument>
#include<QCalendarWidget>
using namespace std;

SignUpWidget::SignUpWidget(QWidget *parent) : QWidget(parent)
{
    FirstName=new QLabel("First Name");
    LastName=new QLabel("Last Name");
    UserName=new QLabel("Username");
    Password=new QLabel("Password");
    ConfirmPass=new QLabel("Confirm Password");
    ProfilePicture=new QLabel("Profile Picture");
    Gender=new QLabel("Gender");
    First=new QLineEdit("FirstName");
    Last=new QLineEdit("LastName");
    User=new QLineEdit("Username");
    Pass=new QLineEdit("Password1");
    Confirm=new QLineEdit("Password1");
    Submit=new QPushButton("Submit");
    Male=new QRadioButton("Male");
    Female=new QRadioButton("Female");
    GridLayout=new QGridLayout;
    VerticalLayout=new QVBoxLayout;

    Submit->setStyleSheet("font-size: 36px;height: 38px;width: 90px;");


    Pass->setEchoMode(QLineEdit::Password);
    Confirm->setEchoMode(QLineEdit::Password);

    createPreviewGroupBox();

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

    GridLayout->addWidget(profilePicGroup(), 12, 0);

    GridLayout->addWidget(previewGroupBox,13,0);


    VerticalLayout->addLayout(GridLayout);
    VerticalLayout->addStretch(3);
    VerticalLayout->addWidget(Submit);


    connect(Submit,SIGNAL(pressed()),this,  SLOT(VerifySubmitSlot()));
    setLayout(VerticalLayout);
    resize(450,700);

}


void SignUpWidget::createPreviewGroupBox()
{
    previewGroupBox = new QGroupBox(tr("Preview"));

    calendar = new QCalendarWidget;
    calendar->setMinimumDate(QDate(1900, 1, 1));
    calendar->setMaximumDate(QDate(3000, 1, 1));
    calendar->setGridVisible(true);

    connect(calendar, SIGNAL(currentPageChanged(int,int)),
            this, SLOT(reformatCalendarPage()));

    previewLayout = new QGridLayout;
    previewLayout->addWidget(calendar, 0, 0, Qt::AlignCenter);
    previewGroupBox->setLayout(previewLayout);
}

QGroupBox *SignUpWidget::profilePicGroup()
{
    groupBox = new QGroupBox(tr("Profile Picture Style "));

    ProfilePic1=new QRadioButton("Style 1");
    ProfilePic2=new QRadioButton("Style 2");
    ProfilePic3=new QRadioButton("Style 3");
    ProfilePic4=new QRadioButton("Style 4");


    ProfilePic1->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
       vbox->addWidget(ProfilePic1);
       vbox->addWidget(ProfilePic2);
       vbox->addWidget(ProfilePic3);
       vbox->addWidget(ProfilePic4);
       vbox->addStretch(1);
       groupBox->setLayout(vbox);

       return groupBox;
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
        Pass->setText("Password can't be empty");
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

    if(!Male->isChecked()&&!Female->isChecked()){
        QLabel *GenderMissing=new QLabel("Need to select gender");
        GridLayout->addWidget(GenderMissing,5,0);
        return;
    }

   QDir dir;
   dir.setPath(dir.path()+"/profiles");
   QFile *NewProfile;
   if(fileExists(dir.path()+"/"+User->text()+".txt")){
       UserName->setText("Username : Username taken");
       return;
   }

       UserName->setText("Username");
       NewProfile=new QFile(dir.path()+"/"+User->text()+".txt");
       NewProfile->open(QIODevice::ReadWrite);
       QTextStream out(NewProfile);

       out<<First->text()<<'\t';
       out<<Last->text()<<'\t';
       if(Male->isChecked()){
           out<<"Male"<<'\t';
       }
       else{
           out<<"Female"<<'\t';

       }

       out<<User->text()<<'\t';
       out<<Pass->text()<<'\t';

       if (ProfilePic1->isChecked()){
           out<<":/Profile Images/Popeye.png"<<'\t';
       }else if (ProfilePic2->isChecked()){
           out<<":/Profile Images/bucket.png"<<'\t';
       }else if (ProfilePic3->isChecked()){
           out<<":/Profile Images/water.gif"<<'\t';     //same as Profile PIc 4, for now
       }else if (ProfilePic4->isChecked()){
           out<<":/Profile Images/water.gif"<<'\t';
       }

       out<<calendar->selectedDate().day()<<'\t'<<calendar->selectedDate().month()<<'\t'<<calendar->selectedDate().year()<<'\t';

       out<<"1"<<'\t';          //USER IS AT LEVEL 1 WHEN HE STARTS

       out<<"5"<<'\t';          //User has 5 lives initially and for each level

       out<<'\n'<<"100";        //User has a score of 100 writen on a new line

       out<<'\n'<<"0";          //User has a highscore of 0 in game2 written on a new Line

       Submit->setText("Press to continue");
       connect(Submit,SIGNAL(pressed()),this,SLOT(GoBackToLogOnSlot()));

}


bool SignUpWidget::fileExists(QString path) {
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}

void SignUpWidget::GoBackToLogOnSlot(){
    LogOnWidget *logon=new LogOnWidget();
    logon->show();
    delete this;
}
