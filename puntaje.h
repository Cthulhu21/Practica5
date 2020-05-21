#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QGraphicsTextItem>

class Puntaje: public QGraphicsTextItem
{
public:
    Puntaje(QGraphicsItem *parent =0);
    void Incremento();
    int ShowPuntaje();
private:
    int Puntuacion;
};

#endif // PUNTAJE_H
