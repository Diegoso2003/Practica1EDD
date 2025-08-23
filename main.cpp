
#include "Juego/TotitoChino.h"

int main() {
    auto *juego = new TotitoChino();
    juego->iniciarJuego();
    delete juego;
    return 0;
}
