#ifndef RIVEROBSTACLE_H
#define RIVEROBSTACLE_H

#include <QObject>
#include <QGraphicsPixmapItem>

/**
* \file riverobstacle.h
* \brief Contains River Obstacle class definition
*
*
* \author Camille Farhat & Ali Haidar
*/

class riverObstacle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit riverObstacle(QObject *parent = nullptr);

signals:

public slots:
};

#endif // RIVEROBSTACLE_H
