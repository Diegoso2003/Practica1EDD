//
// Created by rafael-cayax on 23/8/25.
//

#include "DobleLinea.h"

DobleLinea::DobleLinea() : PowerUp(0) {
}

void DobleLinea::realizarAccion(TotitoChino *juego) {
    juego->setDarTurnoExtra(true);
}
