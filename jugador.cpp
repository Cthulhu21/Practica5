#include "jugador.h"

Jugador::Jugador(QGraphicsItem *parent)
{
    //510,515
    setPixmap(QPixmap(":/Personaje/Pacman1T.png").scaled(35,35,Qt::AspectRatioMode::KeepAspectRatio));
    setPos(500,500);
}
