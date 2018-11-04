#include "hints.h"
#include "levels.h"
#include<QLabel>
#include<QVBoxLayout>
hints::hints(QWidget *parent) : QWidget(parent)
{

}
hints::hints(QString hint, QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel(hint);
    QVBoxLayout *layout= new QVBoxLayout();
    layout->addWidget(label);
    setLayout(layout);
}
