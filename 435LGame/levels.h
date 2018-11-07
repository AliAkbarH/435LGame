#ifndef LEVELS_H
#define LEVELS_H
#include <QWidget>
#include <QString>
#include <QTimer>
#include <QtWidgets>
#include <QObject>
#include <QString>
#include "spinach.h"
#include "popeye.h"

/**
* \file levels.h
* \brief The Level Object
*
* Creating a Level Object that will be passed to every scene to load the respective level.
*
*/
class levels
{
public:
    QString hint[3], instructions;
    int popeyeX1, popeyeY1, spinachX1, spinachY1, spinachX2, spinachY2, spinachX3, spinachY3;
    int levelNumb, hintNumber, lifes;

    levels(int x);
    void setPopeyeX1(int newX);
    void setPopeyeY1(int newY);
    void incrementHintNumber();
    void resetHintNumber();
    void decrementLifes();
    void incrementLevelNumb();
    void updateLevel(QString user);

};

#endif // LEVELS_H
