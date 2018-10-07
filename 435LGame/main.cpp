#include <QApplication>
#include<QPushButton>
#include<logonwidget.h>
int main(int argc, char **argv)
{
QApplication app (argc, argv);
LogOnWidget *LogonWidget=new LogOnWidget();
LogonWidget->show();
//QGridLayout *layout=new QGridLayout;
return app.exec();
}
