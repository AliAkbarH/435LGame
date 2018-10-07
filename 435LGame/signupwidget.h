#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include"logonwidget.h"
#include <QWidget>
#include<QtWidgets>
#include<fstream>
#include<QFileInfo>
using namespace std;
class SignUpWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SignUpWidget(QWidget *parent = nullptr);
    QLabel *FirstName,*LastName,*UserName,*Password,*ConfirmPass,*ProfilePic,*Gender;
    QLineEdit *First,*Last,*User,*Pass,*Confirm;
    QPushButton *Submit,*ProfilePicture;
    QRadioButton *Male,*Female;
    QGridLayout *GridLayout;
    QVBoxLayout *VerticalLayout;

private:
    bool checkForWord(fstream *file,string user);
    bool fileExists(QString path) ;

signals:

public slots:
    void VerifySubmitSlot();
    void AddProfilePictureSlot();
    void GoBackToLogOnSlot();
};

#endif // SIGNUPWIDGET_H
