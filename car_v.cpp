#include "car_v.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QPixmap>
#include <time.h>
#include <QDebug>
#include <iostream>

car_v::car_v(): QObject(), QGraphicsPixmapItem()
{

    srand(time(NULL));
    int random_spot = rand() % 2;
    int random_color = rand() % 3;
    int random_direction = rand() % 2;

    if (random_color == 0){setPixmap(QPixmap("C:/Users/FoxAngry/Desktop/Trabalho.PP/PP/imagens/car.png"));}
    else if (random_color == 1){setPixmap(QPixmap("C:/Users/FoxAngry/Desktop/Trabalho.PP/PP/imagens/car2.png"));}
    else if (random_color == 2){setPixmap(QPixmap("C:/Users/FoxAngry/Desktop/Trabalho.PP/PP/imagens/car3.png"));}

    if (random_direction == 0){

        rotation = 180;
        setRotation(rotation);

        if (random_spot == 0){setPos(352,0);}
        else if (random_spot == 1){setPos(327,0);}

        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move_baixo()));
        timer->start(40);

    }else {

        rotation = 360;
        setRotation(rotation);

        if (random_spot == 0){setPos(383,655);}
        else if (random_spot == 1){setPos(357,655);}

        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move_cima()));
        timer->start(40);
    }

}

void car_v::move_cima()
{
    setPos(x(),y()-4);

    if (pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

void car_v::move_baixo()
{
    setPos(x(),y()+4);

    if (pos().y() + pixmap().height() > 760){
        scene()->removeItem(this);
        delete this;
    }
}

