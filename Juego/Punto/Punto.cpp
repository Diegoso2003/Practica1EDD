//
// Created by rafael-cayax on 22/8/25.
//

#include "Punto.h"
#include <iostream>
#include "../Linea/Linea.h"

Punto::Punto() {
    this->lineaAbajo = nullptr;
    this->lineaDerecha = nullptr;
    this->lineaIzquierda = nullptr;
    this->lineaArriba = nullptr;
}


void Punto::imprimir() {
    std::cout<<punto;
    if (lineaDerecha != nullptr) {
        lineaDerecha->imprimir();
    } else {
        std::cout << "  ";
    }
}
