#include "juego.h"

Juego::Juego(QWidget *Parent)
{
    //Se crea el escenario
    Escenario =new QGraphicsScene;
    Escenario->setSceneRect(0,0,1366,768);
    setBackgroundBrush(QBrush(QImage(":/Fondo/Fondo.jpg")));

    //Se pone el escenario
    setScene(Escenario);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1366,768);

    //Se ponen las paredes
}
