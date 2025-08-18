//
// Created by rafael-cayax on 18/8/25.
//

#include "TotitoChino.h"

TotitoChino::~TotitoChino() {
    delete jugadores;
}

int TotitoChino::pedirNumeroDeJugadores() {
    std::string entrada;
    int numero;
    bool hecho = false;
    do {
        std::cout << "Ingrese el numero de jugadores para empezar: " << std::endl;
        std::getline(std::cin, entrada);

        try {
            numero = std::stoi(entrada);
            hecho = numero >= minimoJugadores && numero <= maximoJugadores;
        } catch (const std::exception& e) {
            std::cout << "¡Error! Entrada no válida.\n";
        }
    } while (!hecho);
    return numero;
}


void TotitoChino::iniciarJuego() {
    int totalJugadores = pedirNumeroDeJugadores();
    jugadores = new ColaConArreglo<Jugador>(totalJugadores);
}