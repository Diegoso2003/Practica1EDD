//
// Created by rafael-cayax on 17/8/25.
//

#include "Jugador.h"

#include <iostream>

Jugador::Jugador(std::string nombre, char inicial, std::string color) {
    this->nombre = nombre;
    this->inicial = inicial;
    this->color = color;
}

Jugador::Jugador() {
    this->nombre = "";
    this->inicial = 0;
    this->color = "";
}

Jugador::~Jugador() {
    std::cout << "borrando a " << this->nombre << std::endl;
}

std::string Jugador::getColor() const {
    return this->color;
}

char Jugador::getInicial() const {
    return this->inicial;
}

std::string Jugador::getNombre() const {
    return this->nombre;
}