#ifndef LOST_H
#define LOST_H


#include <QWidget>

/**
* \file lost.h
* \brief The Level's scene's loose pop up
*
* Pop up window that will display the number of lifes remaining and that the player lost. 
* 
*/

class lost : public QWidget
{
    Q_OBJECT
public:
    explicit lost(QWidget *parent = nullptr);
    lost(int lifes, QWidget *parent = nullptr);

signals:


public slots:
};

#endif // LOST_H
