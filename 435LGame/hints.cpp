#include "hints.h"
#include "levels.h"
#include<QLabel>
#include<QVBoxLayout>

/**
* \file hints.cpp
* \brief Shows the appropriate hints in a pop up window
*
* \author Camille Farhat & Ali Haidoura
*/


/*! \brief Setting the hints pop up window content
*/

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
