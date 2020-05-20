#include "juego.h"
#include "paredes.h"

Juego::Juego(QWidget *Parent)
{
    //Se crea el escenario
    Escenario =new QGraphicsScene;
    Escenario->setSceneRect(0,0,1024,688);

    //Se pone el escenario
    setScene(Escenario);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,688);

    //Se ponen las paredes
    Paredes *Pared = new Paredes;
    Escenario->addItem(Pared);
}
