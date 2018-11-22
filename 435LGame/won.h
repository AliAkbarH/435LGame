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
{
    Q_OBJECT
public:
    explicit Won(QWidget *parent = nullptr);
    explicit Won(int level, int lives);

signals:

public slots:
};

#endif // WON_H
