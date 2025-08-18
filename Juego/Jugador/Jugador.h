//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_JUGADOR_H
#define PRACTICA1EDD_JUGADOR_H
#include <string>


class Jugador {
private:
    std::string nombre;
    char inicial;
    std::string color;
public:
    Jugador();
    Jugador(std::string nombre, char inicial, std::string color);
    ~Jugador();
    std::string getNombre() const;
    std::string getColor() const;
    char getInicial() const;
};


#endif //PRACTICA1EDD_JUGADOR_H