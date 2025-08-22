//
// Created by rafael-cayax on 18/8/25.
//

#include "TotitoChino.h"

TotitoChino::TotitoChino() : jugadores(nullptr) {}

TotitoChino::~TotitoChino() {
    delete jugadores;
}

void TotitoChino::iniciarJuego() {
    auto* registro = new RegistroJugadores();
    jugadores = registro->registrarJugadores();
    std::cout << "registro hecho" << std::endl;
    delete registro;
}