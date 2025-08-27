//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_EXPLOSIVO_H
#define PRACTICA1EDD_EXPLOSIVO_H
#include "../PowerUp.h"


class Explosivo : public PowerUp{
public:
    Explosivo();
    void realizarAccion(TotitoChino *juego) override;
};


#endif //PRACTICA1EDD_EXPLOSIVO_H