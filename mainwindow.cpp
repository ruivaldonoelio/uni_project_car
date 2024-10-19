#include "mainwindow.h"
#include "car_h.h"
#include "car_v.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QPixmap>
#include <time.h>
#include <QDebug>

Mainwindow::Mainwindow(): QObject(), QGraphicsPixmapItem(){
    setPos(0,0);
    setPixmap(QPixmap("C:/Users/FoxAngry/Desktop/Trabalho.PP/PP/imagens/road.png"));
    troca = 1;

    QObject::connect(posi,SIGNAL(timeout()),this,SLOT(position()));
    posi->start(5000);
}

void Mainwindow::position()
{
    if (troca == 1){
        QObject::connect(horizontal,SIGNAL(timeout()),this,SLOT(horizontal_car()));
        horizontal->start(1000);
        vertical->stop();
    }else if (troca == 5){
        QObject::connect(vertical,SIGNAL(timeout()),this,SLOT(vertical_car()));
        vertical->start(1000);
        horizontal->stop();
    }else if (troca == 10) {troca = 0;}

    troca +=1;
}

void Mainwindow::horizontal_car()
{
    car_h * car = new car_h();
    scene()->addItem(car);
}

void Mainwindow::vertical_car()
{
    car_v * car = new car_v();
    scene()->addItem(car);
}
