//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_CASILLA_H
#define PRACTICA1EDD_CASILLA_H
#include <string>

class Jugador;
class Linea;
class PowerUp;

class Casilla {
private:
    static constexpr std::string punto = "•";
    PowerUp *powerUp;
    Jugador *jugador;
    Linea *linea;
public:
    explicit Casilla(PowerUp *powerUp): powerUp(powerUp), jugador(nullptr), linea(nullptr) {}
    explicit Casilla(Jugador *jugador): powerUp(nullptr), jugador(jugador), linea(nullptr) {}
    explicit Casilla(Linea *linea): linea(linea), powerUp(nullptr), jugador(nullptr) {}
    Casilla(): powerUp(nullptr), jugador(nullptr), linea(nullptr) {}
    ~Casilla();
    PowerUp *getPowerUp() {return powerUp;}
    Jugador *getJugador() {return jugador;}
    Linea *getLinea() {return linea;}
    void setJugador(Jugador *jugador) {this->jugador = jugador;}
    void setLinea(Linea *linea) {this->linea = linea;}
    void setPowerUp(PowerUp *powerUp) {this->powerUp = powerUp;}
    void imprimir();
};


#endif //PRACTICA1EDD_CASILLA_H