#include <QApplication>
#include <QtWidgets>
#include<QPushButton>
#include<signinwidget.h>
#include<logginwidget.h>
#include<gameswidget.h>
#include<logonwidget.h>

int main(int argc, char **argv)
{
QApplication app (argc, argv);
LogOnWidget *LogonWidget=new LogOnWidget();
LogonWidget->show();
return app.exec();
}
