#ifndef SMALLRIVER_H
#define SMALLRIVER_H

#include <QObject>
#include <QGraphicsPixmapItem>

/**
* \file smallriver.h
* \brief contains Small River class definition
* \author Camille Farhat & Ali Haidar
*/

class smallRiver : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit smallRiver(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SMALLRIVER_H
