//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_ESCURRIDIZO_H
#define PRACTICA1EDD_ESCURRIDIZO_H
#include "../PowerUp.h"


class Escurridizo : public PowerUp{
public:
    Escurridizo();
    void realizarAccion(TotitoChino *juego) override;
};


#endif //PRACTICA1EDD_ESCURRIDIZO_H