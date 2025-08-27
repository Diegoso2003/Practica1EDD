//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_BLOQUEO_H
#define PRACTICA1EDD_BLOQUEO_H
#include "../PowerUp.h"


class Bloqueo : public PowerUp{
public:
    Bloqueo();
    void realizarAccion(TotitoChino *juego) override;
};


#endif //PRACTICA1EDD_BLOQUEO_H