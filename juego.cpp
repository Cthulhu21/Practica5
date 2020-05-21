#include "juego.h"
#include "paredes.h"
#include "jugador.h"

Juego::Juego(QWidget *Parent)
{
    //Se crea el escenario
    Escenario =new QGraphicsScene;
    Escenario->setSceneRect(0,0,1024,688);
    setBackgroundBrush(QBrush(QImage(":/Fondo/Fondo.jpg")));

    //Se pone el escenario
    setScene(Escenario);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,688);

    //Se ponen las paredes
    Paredes *Pared = new Paredes;
    Escenario->addItem(Pared);

    //Se pone al jugador

    Jugador *Player =new Jugador;
    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();
    Escenario->addItem(Player);
}
