#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QDir>
#include<QFileDialog>
#include <iostream>
#include<QFile>
#include<fstream>


class signInWidget : public QWidget
{
    Q_OBJECT
public:
    explicit signInWidget(QWidget *parent = nullptr);

        QLabel *userName, *password, *signIn;
        QLineEdit *LuserName, *Lpassword;
        QPushButton *submit, *back;
        const QString esc="7727";//for some reason endl and \n are not working so we provide this escape string to determine the end of a field

        QVBoxLayout *VerticalL;
        QGridLayout *GridL;

        void setVerticalLayout();
        void setGridLayout();

private:
        bool fileExists(QString path);
        bool userValid();
        QStringList profileParser(QString in);
signals:


public slots:
        void loggedIn();
        void homepage();


};

#endif
