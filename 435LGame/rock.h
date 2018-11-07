#ifndef ROCK_H
#define ROCK_H

#include <QObject>
#include <QGraphicsPixmapItem>

class rock : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit rock(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ROCK_H
