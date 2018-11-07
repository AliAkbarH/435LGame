#ifndef SMALLRIVER_H
#define SMALLRIVER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class smallRiver : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit smallRiver(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SMALLRIVER_H
