#ifndef LOGONWIDGET_H
#define LOGONWIDGET_H

#include<QWidget>
#include<QtWidgets>
#include<signupwidget.h>


class LogOnWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LogOnWidget(QWidget *parent = nullptr);
    QPushButton *SignUpButton,*SignInButton,*GuestButton;
    QLabel *TitleLabel,*InfoLabel;
    QVBoxLayout *VerticalLayout;
<<<<<<< HEAD
    QGridLayout *GridLayout;
    QGraphicsScene *Scene;

    void setVerticalLayout();
    void setGridLayout();
=======
    QGraphicsScene *Scene;

>>>>>>> 86e14ac02bc6cf2db4233b89273c53a6a12b3eb1
signals:

public slots:
    void GotoSignUpPage();
<<<<<<< HEAD
    void GotoSignInPage();
=======
>>>>>>> 86e14ac02bc6cf2db4233b89273c53a6a12b3eb1
};

#endif // LOGONWIDGET_H
