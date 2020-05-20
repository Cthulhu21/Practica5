#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Juego :public QGraphicsView
{
public:
    Juego(QWidget *parent=0);
    QGraphicsScene *Escenario;
};

#endif // JUEGO_H
