//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_CASILLA_H
#define PRACTICA1EDD_CASILLA_H
#include "../Jugador/Jugador.h"
#include "../PowerUp/PowerUp.h"


class Casilla {
private:
    PowerUp *powerUp;
    Jugador *jugador;
public:
    Casilla(PowerUp *powerUp): powerUp(powerUp), jugador(nullptr) {}
    Casilla(Jugador *jugador): powerUp(nullptr), jugador(jugador) {}
    PowerUp *getPowerUp() {return powerUp;}
    Jugador *getJugador() {return jugador;}
    void setJugador(Jugador *jugador) {this->jugador = jugador;}
    void imprimir();
};


#endif //PRACTICA1EDD_CASILLA_H