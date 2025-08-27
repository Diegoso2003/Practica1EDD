//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_UNIONAFUTURO_H
#define PRACTICA1EDD_UNIONAFUTURO_H
#include "../PowerUp.h"


class UnionAFuturo : public PowerUp{
public:
    UnionAFuturo();
    void realizarAccion(TotitoChino *juego) override;
};


#endif //PRACTICA1EDD_UNIONAFUTURO_H