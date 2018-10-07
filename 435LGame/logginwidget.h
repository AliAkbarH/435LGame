#ifndef LOGGIN_H
#define LOGGIN_H


#include <QtWidgets>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QMainWindow>
#include <QLabel>

class loggInWidget : public QWidget
{
    Q_OBJECT
public:
    explicit loggInWidget(QWidget *parent = nullptr);

        QLabel *userName, *logIn;
        QPushButton *games;

        QVBoxLayout *VerticalL;
        QGridLayout *GridL;

        void setVerticalLayout();
        void setGridLayout();

signals:


public slots:
        void startGames();

};

#endif // LOGGIN_H
