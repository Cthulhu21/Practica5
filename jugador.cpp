#include "jugador.h"
#include "paredes.h"
#include "frutos.h"

bool Choque(QList<QGraphicsItem *>);
void ChoqueFruta(QList<QGraphicsItem *>);

Jugador::Jugador(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/Personaje/Pacman1T.png").scaled(22,22,Qt::AspectRatioMode::KeepAspectRatio));
    setPos(512,508);
}

void Jugador::keyPressEvent(QKeyEvent *event)
{
    //Opciones para pasar de un lado de la pantalla al otro

    if(this->x()>1024)
    {
        setX(0);
    }
    else if(this->x()<0)
    {
        setX(1024);
    }
    //Revisa que no esté chocando con el laberinto
    QList<QGraphicsItem *> ElementosChocando=collidingItems();
    bool ChoquePared=false;
    ChoquePared=Choque(ElementosChocando);
    //Se mueve si no choca
    if(!ChoquePared)
    {
        if(event->key()==Qt::Key_Left)
        {
            setX(x()-7);
            ElementosChocando=collidingItems(); //Revisa que después de moverlo no haya quedado dentro de la pared
            if(Choque(ElementosChocando))
            {
                setX(x()+7);
            }
        }
        else if (event->key()==Qt::Key_Right)
        {
            setX(x()+7);
            ElementosChocando=collidingItems();
            if(Choque(ElementosChocando))
            {
                setX(x()-7);
            }
        }
        else if(event->key()==Qt::Key_Up)
        {
            setY(y()-7);
            ElementosChocando=collidingItems();
            if(Choque(ElementosChocando))
            {
                setY(y()+7);
            }
        }
        else if(event->key()==Qt::Key_Down)
        {
            setY(y()+7);
            ElementosChocando=collidingItems();
            if(Choque(ElementosChocando))
            {
                setY(y()-7);
            }
        }
    }

    //Revisa que esté tocando a una fruta
    ChoqueFruta(ElementosChocando);
}

//Funcion para revisar el choque
bool Choque(QList<QGraphicsItem *> Lista)
{
    for(int i=0, n=Lista.size();i<n;++i)
    {
        if(typeid(*Lista[i])==typeid(Paredes))
        {
            return true;
        }
    }
    return false;
}

void ChoqueFruta(QList<QGraphicsItem * Lista>)
