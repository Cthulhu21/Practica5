#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

class Jugador: public QObject, public QGraphicsPixmapItem
{
public:
    Jugador(QGraphicsItem *parent=0);
};

#endif // JUGADOR_H
