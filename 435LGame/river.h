#ifndef RIVER_H
#define RIVER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class river : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit river(QObject *parent = nullptr);

signals:

public slots:
};



#endif // RIVER_H
