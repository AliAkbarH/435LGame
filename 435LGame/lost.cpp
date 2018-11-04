#include"lost.h"
#include<QLabel>
#include<QVBoxLayout>
lost::lost(QWidget *parent) : QWidget(parent)
{

}
lost::lost(int lifes, QWidget *parent) : QWidget(parent)
{
    QString life = QString::number(lifes);
    QLabel *label = new QLabel("You have " + life + " lifes left! \n Close this window and click on Retry to start again!");
    QVBoxLayout *layout= new QVBoxLayout();
    layout->addWidget(label);
    setLayout(layout);
}
