#ifndef GAMESWIDGET_H
#define GAMESWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QPixmap>
#include "game1scene.h"
#include "game2scene.h"

class gamesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit gamesWidget(QString user);


        QPushButton *game1, *game2;
        QString user;
        QVBoxLayout *VerticalL;
        QGridLayout *GridL;

        game1scene *scene1;                     //!< pointer to an Object of type game1scene
        Game2Scene *scene2;
        QGraphicsView *view1;                   //!< pointer to an Object of type QGraphicsView
        QGraphicsView *view2;

        void setVerticalLayout();
        void setGridLayout();

signals:


public slots:
        void startGame1();
        void startGame2();
};

#endif // GAMESWIDGET_H
