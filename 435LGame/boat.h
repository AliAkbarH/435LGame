#ifndef BOAT_H
#define BOAT_H

#include <QObject>
#include <QGraphicsPixmapItem>

class boat : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit boat(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BOAT_H
