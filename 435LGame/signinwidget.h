#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>

class signInWidget : public QWidget
{
    Q_OBJECT
public:
    explicit signInWidget(QWidget *parent = nullptr);

        QLabel *userName, *password, *signIn;
        QLineEdit *LuserName, *Lpassword;
        QPushButton *submit;

        QVBoxLayout *VerticalL;
        QGridLayout *GridL;

        void setVerticalLayout();
        void setGridLayout();

signals:


public slots:
        void loggedIn();

};

#endif
