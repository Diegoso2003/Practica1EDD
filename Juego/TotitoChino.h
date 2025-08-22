//
// Created by rafael-cayax on 18/8/25.
//

#ifndef PRACTICA1EDD_TOTITO_CHINO_H
#define PRACTICA1EDD_TOTITO_CHINO_H

#include "Color.h"
#include "../estructuras_de_datos/Cola/ColaConArreglo.h"
#include "Jugador/Jugador.h"
#include "RegistroJugadores/RegistroJugadores.h"

class TotitoChino {
private:

    ColaConArreglo<Jugador> *jugadores;
public:
    TotitoChino();
    ~TotitoChino();
    void iniciarJuego();
};


#endif //PRACTICA1EDD_TOTITOCHINO_H