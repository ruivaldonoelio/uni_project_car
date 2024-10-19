//Ruivaldo Santana - 30009351
//Denilson Ucuahamba - 30009025
//Walgidio Santos - 30009596
//Rui Miguel Lopes Cardoso - 30004959

#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();

    Mainwindow * estrada = new Mainwindow();
    scene->addItem(estrada);

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(722,655);
    scene->setSceneRect(0,0,722,655);

    return a.exec();
}

