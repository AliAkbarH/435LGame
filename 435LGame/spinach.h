#ifndef SPINACH_H
#define SPINACH_H

#include <QObject>
#include <QGraphicsPixmapItem>

class spinach : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit spinach(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SPINACH_H
