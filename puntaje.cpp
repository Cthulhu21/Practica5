#include "puntaje.h"
#include <QFont>

Puntaje::Puntaje(QGraphicsItem*parent):QGraphicsTextItem(parent)
{
    //La iniciliza en 0;
    Puntuacion=0;

    //Fuente, color y la barra
    setPlainText(QString("Puntuacion: ") + QString::number(Puntuacion));
    setDefaultTextColor(Qt::darkMagenta);
    setFont(QFont("times",16));
    setPos(1050,300);
}

void Puntaje::Incremento()
{
    Puntuacion++;
    setPlainText(QString("Puntuacion: ") + QString::number(Puntuacion));
}

int Puntaje::ShowPuntaje()
{
    return Puntuacion;
}
