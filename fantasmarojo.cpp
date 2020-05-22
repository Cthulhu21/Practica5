#include "fantasmarojo.h"
#include "juego.h"
#include <QTimer>
#include "paredes.h"

bool Firts=true;
int Direccion=0;
list<int> MirarOpciones();
int ElegirDireccion(list<int>);


FantasmaRojo::FantasmaRojo(QGraphicsPixmapItem *parent)
{
    setPixmap(QPixmap(":/Fantasmas/FantasmaRojoR.png"));
    setPos(510,250);
    QTimer *Tiempo =new QTimer;
    connect(Tiempo,SIGNAL(timeout()),this,SLOT(DesplazarFantasma()));
    Tiempo->start(20);
}

void FantasmaRojo::DesplazarFantasma()
{
    bool Choque=false;
    bool _Firts=Firts;
    int _Direccion=Direccion;
    list<int> Opciones;
    QList<QGraphicsItem *> ElementosChoquePared=collidingItems();
    if(_Firts)
    {
        _Direccion=1+rand()%4;
        Firts=false;
    }
    Choque=ChoquePared(ElementosChoquePared);
    if(!Choque)
    {
        switch(_Direccion)
        {
        case 1: // Derecha
            setX(x()+5);
            ElementosChoquePared=collidingItems();
            if(ChoquePared(ElementosChoquePared))
            {
                setX(x()-5);
                Opciones=MirarOpciones();
                //Elegir nueva direccion
                bool Dentro=false;
                while(!Dentro)
                {
                    int _NuevaDir=1+rand()%4;
                    for(auto Numero: Opciones)
                    {
                        if(_NuevaDir==Numero)
                        {
                            Dentro=true;
                            Direccion=_NuevaDir;
                            break;
                        }
                    }
                }
            }
            else
            {
                Direccion=_Direccion;
            }
            break;
        case 2: //Izquierda
            setX(x()-5);
            ElementosChoquePared=collidingItems();
            if(ChoquePared(ElementosChoquePared))
            {
                setX(x()+5);
                Opciones=MirarOpciones();
                //Elegir nueva direccion
                bool Dentro=false;
                while(!Dentro)
                {
                    int _NuevaDir=1+rand()%4;
                    for(auto Numero: Opciones)
                    {
                        if(_NuevaDir==Numero)
                        {
                            Dentro=true;
                            Direccion=_NuevaDir;
                            break;
                        }
                    }
                }
            }
            else
            {
                Direccion=_Direccion;
            }
            break;
        case 3: //Abajo
            setY(y()+5);
            ElementosChoquePared=collidingItems();
            if(ChoquePared(ElementosChoquePared))
            {
                setY(y()-5);
                Opciones=MirarOpciones();
                //Elegir nueva direccion
                bool Dentro=false;
                while(!Dentro)
                {
                    int _NuevaDir=1+rand()%4;
                    for(auto Numero: Opciones)
                    {
                        if(_NuevaDir==Numero)
                        {
                            Dentro=true;
                            Direccion=_NuevaDir;
                            break;
                        }
                    }
                }
            }
            else
            {
                Direccion=_Direccion;
            }
            break;
        case 4: //Arriba
            setY(y()-5);
            ElementosChoquePared=collidingItems();
            if(ChoquePared(ElementosChoquePared))
            {
                setY(y()+5);
                Opciones=MirarOpciones();
                //Elegir nueva direccion
                bool Dentro=false;
                while(!Dentro)
                {
                    int _NuevaDir=1+rand()%4;
                    for(auto Numero: Opciones)
                    {
                        if(_NuevaDir==Numero)
                        {
                            Dentro=true;
                            Direccion=_NuevaDir;
                            break;
                        }
                    }
                }
            }
            else
            {
                Direccion=_Direccion;
            }
            break;
        }
        if(this->x()>1024)
        {
            setX(0);
        }
        else if(this->x()<0)
        {
            setX(1024);
        }
    }
}

bool FantasmaRojo::ChoquePared(QList<QGraphicsItem *> _Lista)
{
    for(int i=0, n=_Lista.size();i<n;++i)
    {
        if(typeid(*_Lista[i])==typeid(Paredes))
        {
            return true;
        }
    }
    return false;
}

list<int> FantasmaRojo::MirarOpciones()
{
    list<int> ListaOpciones;
    for(int i=0; i<4;i++)
    {
        QList<QGraphicsItem *> Elementos=collidingItems();
        switch (i)
        {
        case 0: //Derecha
            setX(x()+5);
            Elementos=collidingItems();
            if(!ChoquePared(Elementos))
            {
                ListaOpciones.push_back(1);
            }
            setX(x()-5);
            break;
        case 1: //Izquierda
            setX(x()-5);
            Elementos=collidingItems();
            if(!ChoquePared(Elementos))
            {
                ListaOpciones.push_back(2);
            }
            setX(x()+5);
            break;
        case 2://Abajo
            setY(y()+5);
            Elementos=collidingItems();
            if(!ChoquePared(Elementos))
            {
                ListaOpciones.push_back(3);
            }
            setY(y()-5);
            break;
        case 3://Arriba
            setY(y()-5);
            Elementos=collidingItems();
            if(!ChoquePared(Elementos))
            {
                ListaOpciones.push_back(4);
            }
            setY(y()+5);
            break;
        }
    }
    return ListaOpciones;
}
