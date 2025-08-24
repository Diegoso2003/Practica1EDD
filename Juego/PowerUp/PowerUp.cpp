//
// Created by rafael-cayax on 23/8/25.
//

#include "PowerUp.h"
#include <iostream>
const std::string PowerUp::simbolos[10] =
    {"DL", "TS", "BL", "PS", "LS", "ES", "UF", "AC", "NT", "EX"};

PowerUp::PowerUp(int posicion) {
    this->simboloTablero = &simbolos[posicion];
}

void PowerUp::imprimir() {
    std::cout << simboloTablero;
}
