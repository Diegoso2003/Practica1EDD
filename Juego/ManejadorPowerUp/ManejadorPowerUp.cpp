//
// Created by rafael-cayax on 27/8/25.
//

#include "ManejadorPowerUp.h"
#include "../PowerUp/PowerUp.h"

void ManejadorPowerUp::activarPowerUp() {
    if (powerUpActual != nullptr) {
        powerUpActual->realizarAccion(totitoChino);
        if (borrarPowerUp) {
            delete powerUpActual;
            powerUpActual = nullptr;
        }
    }
}

ManejadorPowerUp::ManejadorPowerUp(TotitoChino *totitoChino) : totitoChino(totitoChino), powerUpActual(nullptr) {
}
