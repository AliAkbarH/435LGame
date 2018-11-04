#ifndef HINTS_H
#define HINTS_H


#include <QWidget>

class hints : public QWidget
{
    Q_OBJECT
public:
    explicit hints(QWidget *parent = nullptr);
    hints(QString hint, QWidget *parent = nullptr);

signals:


public slots:
};


#endif // HINTS_H
