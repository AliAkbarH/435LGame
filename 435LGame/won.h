#ifndef WON_H
#define WON_H

#include <QWidget>

class Won : public QWidget
{
    Q_OBJECT
public:
    explicit Won(QWidget *parent = nullptr);
    explicit Won(int level, int lives);

signals:

public slots:
};

#endif // WON_H
