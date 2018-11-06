#include "won.h"
#include<QLabel>
#include<QLayout>

Won::Won(QWidget *parent) : QWidget(parent)
{

}

Won::Won(int level, int lives){


    QLabel *label = new QLabel("You have successfully passed level "+QString::number(level)+". You may now proceed to the next level. You have "+QString::number(lives)+" lives remaining.");
    QVBoxLayout *layout= new QVBoxLayout();
    layout->addWidget(label);
    setLayout(layout);
}
