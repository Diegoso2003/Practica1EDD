//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_CREADORPOWERUPS_H
#define PRACTICA1EDD_CREADORPOWERUPS_H
#include "../PowerUp/PowerUp.h"


class CreadorPowerUps {
private:
    int calcularLimitePowerUps(int fila, int columna);
    int obtenerNumeroAleatorio(int min, int max);
    PowerUp *crearPowerUpAleatorio();
public:
    void llenarTableroDePowerUps(Matriz<Casilla> *tablero);
};


#endif //PRACTICA1EDD_CREADORPOWERUPS_H