#include "jugador.h"
#include "paredes.h"
#include <QMessageBox>

bool Choque(QList<QGraphicsItem *>);

Jugador::Jugador(QGraphicsItem *parent)
{
    //57,515
    setPixmap(QPixmap(":/Personaje/Pacman1T.png").scaled(22,22,Qt::AspectRatioMode::KeepAspectRatio));
    setPos(512,508);
}

void Jugador::keyPressEvent(QKeyEvent *event)
{
    bool ChoquePared=false;

    //Revisa que no esté chocando con el laberinto
    QList<QGraphicsItem *> ElementosChocando=collidingItems();
    ChoquePared=Choque(ElementosChocando);
    //Opciones para pasar de un lado de la pantalla al otro
    if(this->x()>1024)
    {
        setX(0);
    }
    else if(this->x()<0)
    {
        setX(1024);
    }

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
    /*
    else
    {
        int UltimaTecla=0;
        // Se revisa que tecla está siendo presionada
        if(event->key()==Qt::Key_Left)
        {
            UltimaTecla=1;
        }
        else if (event->key()==Qt::Key_Right)
        {
            UltimaTecla=2;
        }
        else if(event->key()==Qt::Key_Up)
        {
            UltimaTecla=3;
        }
        else if(event->key()==Qt::Key_Down)
        {
            UltimaTecla=4;
        }
        switch (UltimaTecla)
        {
        case 1:
            setX(x()+7);
            break;
        case 2:
            setX(x()-7);
            break;
        case 3:
            setY(y()+7);
            break;
        case 4:
            setY(y()-7);
            break;
        }
    }*/
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
