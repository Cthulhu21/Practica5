#ifndef FANTASMAROJO_H
#define FANTASMAROJO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <list>

using namespace std;

class FantasmaRojo: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    FantasmaRojo(QGraphicsPixmapItem *parent=0);
    bool ChoquePared(QList<QGraphicsItem *>);
    list<int> MirarOpciones();
public slots:
    void DesplazarFantasma();
};

#endif // FANTASMAROJO_H
