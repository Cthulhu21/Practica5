#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "puntaje.h"

class Juego :public QGraphicsView
{
public:
    Juego(QWidget *parent=0);
    QGraphicsScene *Escenario;
    Puntaje *Puntos;
};

#endif // JUEGO_H
