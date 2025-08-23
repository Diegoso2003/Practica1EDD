//
// Created by rafael-cayax on 18/8/25.
//

#ifndef PRACTICA1EDD_TOTITO_CHINO_H
#define PRACTICA1EDD_TOTITO_CHINO_H

#include "../estructuras_de_datos/Cola/ColaConArreglo.h"
#include "Jugador/Jugador.h"
#include "CreadorDeMatriz/CreadorDeMatriz.h"
#include "Punto/Punto.h"

class TotitoChino {
private:
    Matriz<Punto> *matrizPuntos;
    ColaConArreglo<Jugador> *jugadores;
    void darDescripcion();
    void imprimirTablero();
public:
    TotitoChino();
    ~TotitoChino();
    void iniciarJuego();
};


#endif //PRACTICA1EDD_TOTITOCHINO_H