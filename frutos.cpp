#include "frutos.h"

Frutos::Frutos(int _X,int _Y,QGraphicsItem *parent)
{
    //Se elige la imagen de la fruta de manera aleatoria
    int NumeroAleatorio=1+rand()%4;
    switch (NumeroAleatorio)
    {
    case 1:
        setPixmap(QPixmap(":/Frutos/FresaR.png"));
        setPos(_X,_Y);
        break;
    case 2:
        setPixmap(QPixmap(":/Frutos/FrambuesaR.png"));
        setPos(_X,_Y);
        break;
    case 3:
        setPixmap(QPixmap(":/Frutos/KiwiR.png"));
        setPos(_X,_Y);
        break;
    case 4:
        setPixmap(QPixmap(":/Frutos/SandiaR.png"));
        setPos(_X,_Y);
        break;
    }
}
