#include <QApplication>
#include "juego.h"

Juego *Game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Se crea y se muestra el juego
    Juego *Game = new Juego;
    Game->show();

    return a.exec();
}
