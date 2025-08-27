//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_PASE_H
#define PRACTICA1EDD_PASE_H
#include "../PowerUp.h"


class Pase : public PowerUp{
public:
    Pase();
    void realizarAccion(TotitoChino *juego) override;
};


#endif //PRACTICA1EDD_PASE_H