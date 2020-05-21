#include "frutos.h"

Frutos::Frutos(int _X,int _Y,QGraphicsItem *parent)
{
    //Se elige la imagen de la fruta de manera aleatoria
    int NumeroAleatorio=1+rand()%4;
    switch (NumeroAleatorio)
    {
    case 1:
        setPixmap(QPixmap(":/Frutos/Fresa.png").scaled(10,10,Qt::AspectRatioMode::KeepAspectRatio));
        setPos(_X,_Y);
        break;
    case 2:
        setPixmap(QPixmap(":/Frutos/Frambuesa.png").scaled(10,10,Qt::AspectRatioMode::KeepAspectRatio));
        setPos(_X,_Y);
        break;
    case 3:
        setPixmap(QPixmap(":/Frutos/Kiwi.png").scaled(10,10,Qt::AspectRatioMode::KeepAspectRatio));
        setPos(_X,_Y);
        break;
    case 4:
        setPixmap(QPixmap(":/Frutos/Sandia.png").scaled(10,10,Qt::AspectRatioMode::KeepAspectRatio));
        setPos(_X,_Y);
        break;
    }
}
