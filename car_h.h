#ifndef CAR_H_H
#define CAR_H_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class car_h: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    car_h();
    int rotation;
    QTimer * timer = new QTimer(this);
public slots:
    void move_esquerda();
    void move_direita();
};

#endif // CAR_H_H
