//
// Created by rafael-cayax on 23/8/25.
//

#include "Casilla.h"

void Casilla::imprimir() {
    if (jugador != nullptr) {
        jugador->imprimir();
    } else if (powerUp != nullptr) {

    }
}
