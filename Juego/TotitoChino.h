//
// Created by rafael-cayax on 18/8/25.
//

#ifndef PRACTICA1EDD_TOTITO_CHINO_H
#define PRACTICA1EDD_TOTITO_CHINO_H

#include "CreadorDeMatriz/CreadorDeMatriz.h"
#include "ProcesadorOpciones/ProcesadorOpciones.h"

class ManejadorPowerUp;
class Casilla;
class Jugador;
class TotitoChino {
private:
    Matriz<Casilla> *tableroJuego;
    ListaDobleEnlazada<Jugador> *jugadores;
    ProcesadorOpciones *procesadorOpciones;
    ManejadorPowerUp *manejador;
    Jugador *jugadorPunto;
    Jugador *jugadorCasilla;
    int puntosOtorgados = 1;
    int cuadradosDisponibles = 0;
    int cuadrosTotales = 0;
    bool darTurnoExtra = false;
    bool esVertical(int fila1, int columna1, int fila2, int columna2);
    bool esHorizontal(int fila1, int columna1, int fila2, int columna2);
    void darDescripcion();
    void imprimirTablero();
    void imprimirInformacionJugadores();
    void imprimirAdvertencia(std::string mensaje);
    void verificarLinea(NodoMatriz<Casilla> *punto1, NodoMatriz<Casilla> *punto2);
public:
    TotitoChino();
    ~TotitoChino();
    ListaDobleEnlazada<Jugador> *getJugadores(){return jugadores;}
    Matriz<Casilla> *getTableroJuego(){return tableroJuego;}
    void iniciarJuego();
    void conectarLinea(int fila1, int columna1, int fila2, int columna2);
    void cambiarTurno();
    void setDarTurnoExtra(bool darTurnoExtra){this->darTurnoExtra =darTurnoExtra;}
    bool getDarTurnoExtra() const {return darTurnoExtra;}
    ManejadorPowerUp *getManejador() {return manejador;}
};


#endif //PRACTICA1EDD_TOTITOCHINO_H