#ifndef LOST_H
#define LOST_H


#include <QWidget>

class lost : public QWidget
{
    Q_OBJECT
public:
    explicit lost(QWidget *parent = nullptr);
    lost(int lifes, QWidget *parent = nullptr);

signals:


public slots:
};

#endif // LOST_H
