#ifndef PAREDES_H
#define PAREDES_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class Paredes:public QObject, public QGraphicsPixmapItem
{
public:
    Paredes(QGraphicsItem *parent=0);
};

#endif // PAREDES_H
