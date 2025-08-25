//
// Created by rafael-cayax on 19/8/25.
//

#ifndef PRACTICA1EDD_REGISTROJUGADORES_H
#define PRACTICA1EDD_REGISTROJUGADORES_H
#include "../Color.h"
#include "../../estructuras_de_datos/ListaEnlazadaDoble/NodoDoble/ListaDobleEnlazada.h"
#include "../Jugador/Jugador.h"


class RegistroJugadores {
private:
    const int minimoJugadores = 2;
    int maximoJugadores;
    int tamaño;
    ListaDobleEnlazada<Color::Tipo>* coloresDisponibles;
    ListaDobleEnlazada<Jugador> *jugadores = nullptr;
    void pedirNumeroJugadores();
    void inicializarColoresDisponibles();
    Jugador* pedirDatosJugador();
    Color::Tipo* obtenerColorAleatorio();
    bool caracterEstaApartado(char c);
public:
    RegistroJugadores(int limiteJugadores);
    ~RegistroJugadores();
    ListaDobleEnlazada<Jugador> *registrarJugadores();
};


#endif //PRACTICA1EDD_REGISTROJUGADORES_H