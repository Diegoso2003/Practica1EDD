//
// Created by rafael-cayax on 22/8/25.
//

#include "Linea.h"
#include "../Punto/Punto.h"

Linea::Linea(bool vertical, Punto *punto1, Punto *punto2, Jugador *dueño) {
    linea = vertical ? &lineaVertical : &lineaHorizontal;
    this->punto1 = punto1;
    this->punto2 = punto2;
    this->dueño = dueño;
}

void Linea::imprimir() {
    std::cout << Color::codigo(*dueño->getColor()) << linea << Color::codigo(Color::Tipo::RESET);
}

