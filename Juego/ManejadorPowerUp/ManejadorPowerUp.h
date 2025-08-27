//
// Created by rafael-cayax on 27/8/25.
//

#ifndef PRACTICA1EDD_MANEJADORPOWERUP_H
#define PRACTICA1EDD_MANEJADORPOWERUP_H


class PowerUp;
class TotitoChino;

class ManejadorPowerUp {
private:
    TotitoChino *totitoChino;
    PowerUp *powerUpActual;
    bool borrarPowerUp = true;
public:
    explicit ManejadorPowerUp(TotitoChino *totitoChino);
    void activarPowerUp();
    void setPowerUp(PowerUp* power){powerUpActual = power;}
    void setBorrarPowerUp(bool borrar){this->borrarPowerUp = borrar;}
};


#endif //PRACTICA1EDD_MANEJADORPOWERUP_H