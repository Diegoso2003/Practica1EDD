//
// Created by rafael-cayax on 22/8/25.
//

#include "Linea.h"

#include "../Color.h"
#include "../Jugador/Jugador.h"

Linea::Linea(bool vertical, Jugador *dueño) {
    linea = vertical ? &lineaVertical : &lineaHorizontal;
    this->dueño = dueño;
}

void Linea::imprimir() {
    std::cout << Color::codigo(*dueño->getColor()) << linea << Color::codigo(Color::Tipo::RESET);
}

