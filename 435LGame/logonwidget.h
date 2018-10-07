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
    QGraphicsScene *Scene;

signals:

public slots:
    void GotoSignUpPage();
};

#endif // LOGONWIDGET_H
