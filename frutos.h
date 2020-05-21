#ifndef FRUTOS_H
#define FRUTOS_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Frutos: public QObject, public QGraphicsPixmapItem
{
public:
    Frutos(int X=0,int Y=0,QGraphicsItem *parent=0);
};

#endif // FRUTOS_H
