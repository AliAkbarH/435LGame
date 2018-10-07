#ifndef GAMESWIDGET_H
#define GAMESWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QPixmap>

class gamesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit gamesWidget(QWidget *parent = nullptr);


        QPushButton *game1, *game2, *game3, *score;

        QVBoxLayout *VerticalL;
        QGridLayout *GridL;

        void setVerticalLayout();
        void setGridLayout();

signals:


public slots:
        void scoreLog();
        void startGame1();
        void startGame2();
        void startGame3();

};

#endif // GAMESWIDGET_H
