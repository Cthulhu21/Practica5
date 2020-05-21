#include "juego.h"
#include "paredes.h"
#include "jugador.h"
#include "frutos.h"
#include <list>
#include "puntaje.h"

using namespace std;

Juego::Juego(QWidget *Parent)
{
    srand(time(NULL));

    //Se crea el escenario
    Escenario =new QGraphicsScene;
    Escenario->setSceneRect(0,0,1224,688);
    setBackgroundBrush(QBrush(QImage(":/Fondo/Fondo.jpg")));

    //Se pone el escenario
    setScene(Escenario);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1224,688);

    //Se ponen las paredes
    Paredes *Pared = new Paredes;
    Escenario->addItem(Pared);

    //Poner los frutos
    /*                          |                       |                            |                          */
    list<int> Xs={78,78,78,78,78,954,954,954,954,954,460,358}, Ys={52,133,466,591,645,52,133,466,591,645,510,261};
    auto ComienzoY=Ys.begin();
    for(auto Elemento: Xs)
    {
        Frutos *frutas= new Frutos(Elemento,*ComienzoY);
        Escenario->addItem(frutas);
        ComienzoY++;
    }

    //Puntaje

    Puntaje *puntaje=new Puntaje;
    Escenario->addItem(puntaje);

    //Se pone al jugador

    Jugador *Player =new Jugador;
    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();
    Escenario->addItem(Player);

}
