//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_JUGADOR_H
#define PRACTICA1EDD_JUGADOR_H
#include <string>

#include "../Color.h"
#include "../../estructuras_de_datos/Pila/Pila.h"

class PowerUp;

class Jugador {
private:
    std::string nombre;
    int puntos = 0;
    char inicial;
    Color::Tipo* color;
    Pila<PowerUp> *poderes;
public:
    Jugador(std::string nombre, char inicial, Color::Tipo *color);
    ~Jugador();
    std::string getNombre() const;
    Color::Tipo *getColor() const;
    char getInicial() const;
    void imprimir();
    void imprimirJugador();
    void incrementarPunteo(int puntos);
    void agregarPowerUp(PowerUp *powerUp);
};


#endif //PRACTICA1EDD_JUGADOR_H