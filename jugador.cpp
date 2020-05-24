#include "jugador.h"
#include "paredes.h"
#include "frutos.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "juego.h"
#include <QTimer>

extern Juego *Game;

int _Sprite=0;

bool Choque(QList<QGraphicsItem *>);

Jugador::Jugador(QGraphicsItem *parent)
{
    QTimer *Tiempo=new QTimer;
    setPixmap(QPixmap(":/Personaje/Pacman1TR.png"));
    setPos(512,508);
    connect(Tiempo,SIGNAL(timeout()),this,SLOT(Animar()));
    Tiempo->start(150);
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
    //Revisa que no esté chocando con el slaberinto
    QList<QGraphicsItem *> ElementosChocando=collidingItems();
    bool ChoquePared=false;
    //Revisa que esté chocando con una fruta
    for(int i=0, n=ElementosChocando.size();i<n;++i)
    {
        if(typeid(*ElementosChocando[i])==typeid(Frutos))
        {
            //Game->Puntos->Incremento();
            scene()-> removeItem(ElementosChocando[i]);
            delete ElementosChocando[i];
        }
    }
    ChoquePared=Choque(ElementosChocando);
    //Se mueve si no choca
    if(!ChoquePared)
    {
        if(event->key()==Qt::Key_Left)
        {
            setX(x()-7);
            setTransformOriginPoint(QPoint(11,11));
            setRotation(180);
            ElementosChocando=collidingItems(); //Revisa que después de moverlo no haya quedado dentro de la pared
            if(Choque(ElementosChocando))
            {
                setX(x()+7);
                //setRotation(180);
            }
        }
        else if (event->key()==Qt::Key_Right)
        {
            setX(x()+7);
            setTransformOriginPoint(QPoint(11,11));
            setRotation(0);
            ElementosChocando=collidingItems();
            if(Choque(ElementosChocando))
            {
                setX(x()-7);
                //setRotation(0);
            }
        }
        else if(event->key()==Qt::Key_Up)
        {
            setY(y()-7);
            setTransformOriginPoint(QPoint(11,11));
            setRotation(-90);
            ElementosChocando=collidingItems();
            if(Choque(ElementosChocando))
            {
                setY(y()+7);
                //setRotation(-90);
            }
        }
        else if(event->key()==Qt::Key_Down)
        {
            setY(y()+7);
            setTransformOriginPoint(QPoint(11,11));
            setRotation(90);
            ElementosChocando=collidingItems();
            if(Choque(ElementosChocando))
            {
                setY(y()-7);
            }
        }
    }
}

void Jugador::Animar()
{
    int Sprite=_Sprite;
    switch (Sprite)
    {
    case 0:
        setPixmap(QPixmap(":/Personaje/Pacman2TR.png"));
        _Sprite=1;
        break;
    case 1:
        setPixmap(QPixmap(":/Personaje/Pacman1TR.png"));
        _Sprite=0;
        break;
    }
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
