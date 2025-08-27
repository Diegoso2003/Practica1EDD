//
// Created by rafael-cayax on 23/8/25.
//

#include "Pase.h"
Pase::Pase() : PowerUp(3){

}

void Pase::realizarAccion(TotitoChino *juego) {
    Jugador *jugador = juego->getJugadores()->eliminar(1);
    juego->getJugadores()->agregar(jugador);
}
