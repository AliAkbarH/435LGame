#ifndef POPEYE_H
#define POPEYE_H
#include <QObject>
#include <QGraphicsPixmapItem>

/**
* \file popeye.h
* \brief Contains Popeye class definition
*
*
* \author Camille Farhat & Ali Haidar
*/

class Popeye : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Popeye(QObject *parent = nullptr);
    void collision();

signals:

public slots:
};

#endif // POPEYE_H
