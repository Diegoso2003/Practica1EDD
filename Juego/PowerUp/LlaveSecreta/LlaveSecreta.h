//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_LLAVESECRETA_H
#define PRACTICA1EDD_LLAVESECRETA_H
#include "../PowerUp.h"


class LlaveSecreta : public PowerUp{
public:
    LlaveSecreta();
    void realizarAccion(TotitoChino *juego) override;
};


#endif //PRACTICA1EDD_LLAVESECRETA_H