#ifndef TESTINGICON_H
#define TESTINGICON_H
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<QObject>

class TestingIcon : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    TestingIcon();
    QPixmap *icon;
    bool isHidden;
    QTimer *timer;

    void deActivate();

public slots:
    void reActivate();

};

#endif // TESTINGICON_H
