#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include <QWidget>
#include<QtWidgets>

class SignUpWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SignUpWidget(QWidget *parent = nullptr);
    QLabel *FirstName,*LastName,*UserName,*Password,*ConfirmPass,*ProfilePic,*Gender;
    QLineEdit *First,*Last,*User,*Pass,*Confirm;
    QPushButton *Submit;
    QRadioButton *Male,*Female;
    QGridLayout *GridLayout;
    QVBoxLayout *VerticalLayout;

signals:

public slots:
};

#endif // SIGNUPWIDGET_H
