#ifndef HINTS_H
#define HINTS_H


#include <QWidget>

/**
* \file hints.h
* \brief The Level's scene's Hints
*
* Pop up window that will display the hints. 
* 
*/
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
