#include "car_h.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QPixmap>
#include <time.h>
#include <QDebug>

car_h::car_h(): QObject(), QGraphicsPixmapItem()
{

    srand(time(NULL));
    int random_spot = rand() % 3;
    int random_color = rand() % 3;
    int random_direction = rand() % 2;

    if (random_color == 0){setPixmap(QPixmap("C:/Users/FoxAngry/Desktop/Trabalho.PP/PP/imagens/car.png"));}
    else if (random_color == 1){setPixmap(QPixmap("C:/Users/FoxAngry/Desktop/Trabalho.PP/PP/imagens/car2.png"));}
    else if (random_color == 2){setPixmap(QPixmap("C:/Users/FoxAngry/Desktop/Trabalho.PP/PP/imagens/car3.png"));}

    if (random_direction == 0){
        rotation = 90;
        setRotation(rotation);

        if (random_spot == 0){setPos(0,240);}
        else if (random_spot == 1){setPos(0,275);}
        else if (random_spot == 2){setPos(0,310);}

        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move_esquerda()));
        timer->start(40);

    }else{

        rotation = 270;
        setRotation(rotation);

        if (random_spot == 0){setPos(720,375);}
        else if (random_spot == 1){setPos(720,406);}
        else if (random_spot == 2){setPos(720,440);}
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move_direita()));
        timer->start(40);
    }

}

void car_h::move_direita()
{
    setPos(x()-4,y());

    if (pos().x() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

void car_h::move_esquerda()
{

    setPos(x()+4,y());

    if (pos().x() + pixmap().height() > 820){
        scene()->removeItem(this);
        delete this;
    }
}

