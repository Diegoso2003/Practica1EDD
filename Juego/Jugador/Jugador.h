//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_JUGADOR_H
#define PRACTICA1EDD_JUGADOR_H
#include <string>

#include "../Color.h"


class Jugador {
private:
    std::string nombre;
    char inicial;
    Color::Tipo* color;
public:
    Jugador(std::string nombre, char inicial, Color::Tipo *color);
    ~Jugador();
    std::string getNombre() const;
    Color::Tipo *getColor() const;
    char getInicial() const;
};


#endif //PRACTICA1EDD_JUGADOR_H