#ifndef LOCKS_H
#define LOCKS_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QObject>

/**
* \file locks.h
* \brief Contains Lock class definition
*
*
* \author Camille Farhat & Ali Haidar
*/

class locks : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit locks(QObject *parent = nullptr);

signals:

public slots:
};

#endif // LOCKS_H
