//
// Created by rafael-cayax on 18/8/25.
//

#ifndef PRACTICA1EDD_TOTITO_CHINO_H
#define PRACTICA1EDD_TOTITO_CHINO_H

#include "CreadorDeMatriz/CreadorDeMatriz.h"
#include "ProcesadorOpciones/ProcesadorOpciones.h"

class Casilla;
class Jugador;
class TotitoChino {
private:
    Matriz<Casilla> *tableroJuego;
    ListaDobleEnlazada<Jugador> *jugadores;
    ProcesadorOpciones *procesadorOpciones;
    Jugador *jugadorPunto;
    Jugador *jugadorCasilla;
    bool darTurnoExtra = false;
    void darDescripcion();
    void imprimirTablero();
    void imprimirInformacionJugadores();
public:
    TotitoChino();
    ~TotitoChino();
    ListaDobleEnlazada<Jugador> *getJugadores(){return jugadores;}
    Matriz<Casilla> *getTableroJuego(){return tableroJuego;}
    void iniciarJuego();
    void conectarLinea(int fila1, int columna1, int fila2, int columna2);
    void cambiarTurno();
    void setDarTurnoExtra(bool darTurnoExtra){this->darTurnoExtra =darTurnoExtra;}
};


#endif //PRACTICA1EDD_TOTITOCHINO_H