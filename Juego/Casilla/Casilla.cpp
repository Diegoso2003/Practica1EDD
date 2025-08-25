//
// Created by rafael-cayax on 23/8/25.
//

#include "Casilla.h"
#include "../Jugador/Jugador.h"
#include "../Linea/Linea.h"
#include "../PowerUp/PowerUp.h"

void Casilla::imprimir() {
    if (jugador != nullptr) {
        jugador->imprimir();
    } else if (powerUp != nullptr) {
        powerUp->imprimir();
    } else if (linea != nullptr) {
        linea->imprimir();
    } else {
        std::cout << punto;
    }
}

Casilla::~Casilla() {
    delete linea;
    delete powerUp;
}

