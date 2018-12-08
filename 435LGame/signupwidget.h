#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include"logonwidget.h"
#include <QWidget>
#include<QtWidgets>
#include<fstream>
#include<QFileInfo>
#include<QCalendarWidget>
using namespace std;

/**
* \file signupwidget.h
* \brief User sign up widget
*
* This is the header file for our the sign up widget where the user enters his information before signing in
*/
class SignUpWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SignUpWidget(QWidget *parent = nullptr);
    QLabel *FirstName,*LastName,*UserName,*Password,*ConfirmPass,*ProfilePicture,*Gender;
    QLineEdit *First,*Last,*User,*Pass,*Confirm;
    QPushButton *Submit, *back;
    QRadioButton *Male,*Female,*ProfilePic1,*ProfilePic2,*ProfilePic3,*ProfilePic4;
    QGroupBox *groupBox;
    QGridLayout *GridLayout;
    QVBoxLayout *VerticalLayout;
    QGroupBox *previewGroupBox;
    QGridLayout *previewLayout;
    QCalendarWidget *calendar;

    const QString esc="7727";//for some reason endl and \n are not working so we provide this escape string to determine the end of a field

private:
    bool checkForWord(fstream *file,string user);
    bool fileExists(QString path) ;
    QGroupBox *profilePicGroup();
    void createPreviewGroupBox();

signals:

public slots:
    void VerifySubmitSlot();
    void GoBackToLogOnSlot();
    void homepage();

};

#endif // SIGNUPWIDGET_H
