#ifndef PAREDES_H
#define PAREDES_H

#include <QGraphicsPixmapItem>

class Paredes:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Paredes(QGraphicsItem *parent=0);
};

#endif // PAREDES_H
