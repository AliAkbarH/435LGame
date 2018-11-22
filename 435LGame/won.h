#ifndef WON_H
#define WON_H
#include <QWidget>

/**
* \file won.h
* \brief Shows the appropriate win message in a pop up window
*
* \author Camille Farhat & Ali Haidar
*/

class Won : public QWidget


public:
    Won(QWidget *parent);
    Won(int,int);
};

#endif // WON_H
