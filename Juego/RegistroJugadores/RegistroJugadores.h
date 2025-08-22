//
// Created by rafael-cayax on 19/8/25.
//

#ifndef PRACTICA1EDD_REGISTROJUGADORES_H
#define PRACTICA1EDD_REGISTROJUGADORES_H
#include "../Color.h"
#include "../../estructuras_de_datos/Cola/ColaConArreglo.h"
#include "../../estructuras_de_datos/ListaEnlazadaDoble/ListaDobleEnlazada.h"
#include "../Jugador/Jugador.h"
#include <random>


class RegistroJugadores {
private:
    const int minimoJugadores = 2;
    const int maximoJugadores = 6;
    ListaDobleEnlazada<Color::Tipo>* coloresDisponibles;
    ColaConArreglo<Jugador> *jugadores = nullptr;
    void pedirNumeroJugadores();
    void inicializarColoresDisponibles();
    Jugador* pedirDatosJugador();
    Color::Tipo* obtenerColorAleatorio();
    bool caracterEstaApartado(char c);
public:
    RegistroJugadores();
    ~RegistroJugadores();
    ColaConArreglo<Jugador> *registrarJugadores();
};


#endif //PRACTICA1EDD_REGISTROJUGADORES_H