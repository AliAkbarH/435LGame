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
    explicit loggInWidget(QString user="guest");

        QLabel *userName, *logIn;
        QPushButton *games;
        QString user;
        QVBoxLayout *VerticalL;
        QGridLayout *GridL;

        void setVerticalLayout();
        void setGridLayout();

private:
        bool fileExists(QString path);
        QString profilePic();
        QStringList profileParser(QString in);

signals:


public slots:
        void startGames();

};

#endif // LOGGIN_H
