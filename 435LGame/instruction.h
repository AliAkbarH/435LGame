#ifndef INSTRUCTION_H
#define INSTRUCTION_H



#include <QWidget>

/**
* \file instruction.h
* \brief The Level's scene's levels pop up used for displaying instructions.
*
* Pop up window that will display the Initial Instructions before starting the Game.
*
*/

class instruction : public QWidget
{
    Q_OBJECT
public:
    explicit instruction(QWidget *parent = nullptr);

signals:


public slots:
};


#endif // INSTRUCTION_H
