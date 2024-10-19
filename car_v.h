#ifndef CAR_V_H
#define CAR_V_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class car_v: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    car_v();
    int rotation;
    QTimer * timer = new QTimer(this);
public slots:
    void move_cima();
    void move_baixo();
};


#endif // CAR_V_H
