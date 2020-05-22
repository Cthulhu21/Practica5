#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

class Jugador: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jugador(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
};

#endif // JUGADOR_H
