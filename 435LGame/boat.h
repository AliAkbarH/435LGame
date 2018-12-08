#ifndef BOAT_H
#define BOAT_H

#include <QObject>
#include <QGraphicsPixmapItem>


/**
* \file boat.h
* \brief contains boat class definition
* \author Camille Farhat & Ali Haidar
*/
class boat : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit boat(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BOAT_H
