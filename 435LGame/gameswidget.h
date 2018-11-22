#ifndef GAMESWIDGET_H
#define GAMESWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QPixmap>
#include "game1scene.h"

class gamesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit gamesWidget(QString user);


        QPushButton *game1, *game2, *game3, *score;
        QString user;
        QVBoxLayout *VerticalL;
        QGridLayout *GridL;

        game1scene *scene1;                     //!< pointer to an Object of type game1scene
        QGraphicsView *view1;                   //!< pointer to an Object of type QGraphicsView

        void setVerticalLayout();
        void setGridLayout();

signals:


public slots:
        void scoreLog();
        void startGame1();
        void startGame2();
};

#endif // GAMESWIDGET_H
