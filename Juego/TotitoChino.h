//
// Created by rafael-cayax on 18/8/25.
//

#ifndef PRACTICA1EDD_TOTITO_CHINO_H
#define PRACTICA1EDD_TOTITO_CHINO_H

#include "../estructuras_de_datos/Cola/ColaConArreglo.h"
#include "CreadorDeMatriz/CreadorDeMatriz.h"

class Casilla;
class Jugador;
class TotitoChino {
private:
    Matriz<Casilla> *tableroJuego;
    ColaConArreglo<Jugador> *jugadores;
    void darDescripcion();
    void imprimirTablero();
public:
    TotitoChino();
    ~TotitoChino();
    void iniciarJuego();
};


#endif //PRACTICA1EDD_TOTITOCHINO_H