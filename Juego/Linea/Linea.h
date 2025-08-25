//
// Created by rafael-cayax on 22/8/25.
//

#ifndef PRACTICA1EDD_LINEA_H
#define PRACTICA1EDD_LINEA_H
#include <string>
#include <iostream>
class Jugador;
class PowerUp;
class Linea {
private:
    static constexpr std::string lineaVertical = "│";
    static constexpr std::string lineaHorizontal = "───";
    const std::string *linea;
    Jugador *dueño;
    PowerUp *powerUp;
public:
    Linea(bool vertical,Jugador *dueño);
    void imprimir();
};


#endif //PRACTICA1EDD_LINEA_H