//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_POWERUP_H
#define PRACTICA1EDD_POWERUP_H
#include <string>

#include "../TotitoChino.h"


class PowerUp {
private:
    static const std::string simbolos[10];
    const std::string *simboloTablero;
public:
    PowerUp(int posicion);
    virtual ~PowerUp(){}
    void imprimir();
};



#endif //PRACTICA1EDD_POWERUP_H