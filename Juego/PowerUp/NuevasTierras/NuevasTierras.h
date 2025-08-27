//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_NUEVASTIERRAS_H
#define PRACTICA1EDD_NUEVASTIERRAS_H
#include "../PowerUp.h"


class NuevasTierras : public PowerUp{
public:
    NuevasTierras();
    void realizarAccion(TotitoChino *juego) override;
};


#endif //PRACTICA1EDD_NUEVASTIERRAS_H