//
// Created by rafael-cayax on 17/8/25.
//

#include "Jugador.h"
#include "../PowerUp/PowerUp.h"

#include <iostream>

Jugador::Jugador(std::string nombre, char inicial, Color::Tipo *color) {
    this->nombre = nombre;
    this->inicial = inicial;
    this->color = color;
    this->poderes = new Pila<PowerUp>();
}

Jugador::~Jugador() {
    delete color;
    delete poderes;
}

Color::Tipo *Jugador::getColor() const {
    return this->color;
}

char Jugador::getInicial() const {
    return this->inicial;
}

std::string Jugador::getNombre() const {
    return this->nombre;
}

void Jugador::imprimir() {
    std::cout << Color::codigo(*this->color) << " "<< this->inicial << " " << Color::codigo(Color::Tipo::RESET);
}

void Jugador::imprimirJugador() {
    std::cout << Color::codigo(*this->color) << nombre << ", inicial: " << inicial << ", punteo: "
    <<puntos<< Color::codigo(Color::Tipo::RESET)<<std::endl;
}
