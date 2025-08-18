//
// Created by rafael-cayax on 18/8/25.
//

#ifndef PRACTICA1EDD_TOTITO_CHINO_H
#define PRACTICA1EDD_TOTITO_CHINO_H
#include "../estructuras_de_datos/Cola/ColaConArreglo.h"
#include "Jugador/Jugador.h"


class TotitoChino {
private:
    const int minimoJugadores = 2;
    const int maximoJugadores = 6;
    std::string colores[6] =
        {"\x1B[31m", "\x1B[32m", "\x1B[33m", "\x1B[34m", "\x1B[35m", "\033[38;5;214m"};
    ColaConArreglo<Jugador> *jugadores = nullptr;
    int pedirNumeroDeJugadores();
public:
    ~TotitoChino();
    void iniciarJuego();
};


#endif //PRACTICA1EDD_TOTITOCHINO_H