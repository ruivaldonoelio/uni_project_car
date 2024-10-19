#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Mainwindow: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Mainwindow();
    int troca;
    QTimer * posi = new QTimer(this);
    QTimer * horizontal = new QTimer(this);
    QTimer * vertical = new QTimer(this);

public slots:
    void horizontal_car();
    void vertical_car();
    void position();
};

#endif // MAINWINDOW_H
