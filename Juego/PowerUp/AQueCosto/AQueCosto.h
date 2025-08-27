//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_AQUECOSTO_H
#define PRACTICA1EDD_AQUECOSTO_H
#include "../PowerUp.h"


class AQueCosto : public PowerUp{
public:
    AQueCosto();
    void realizarAccion(TotitoChino *juego) override;
};


#endif //PRACTICA1EDD_AQUECOSTO_H