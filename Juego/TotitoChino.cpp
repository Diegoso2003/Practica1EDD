//
// Created by rafael-cayax on 18/8/25.
//

#include "TotitoChino.h"
#include "RegistroJugadores/RegistroJugadores.h"

TotitoChino::TotitoChino() : jugadores(nullptr), tableroJuego(nullptr) {}

TotitoChino::~TotitoChino() {
    delete jugadores;
    delete tableroJuego;
}

void TotitoChino::darDescripcion() {
    cout<<"TOTITO CHINO: "<<endl;
    cout<<"OBJETIVO:"<<endl;
    cout<<"\tFormar el mayor número de cuadrados conectando puntos adyacentes." << endl;
    cout<<"\tCada cuadrado completo otorga 1 punto y en caso de tener, un poder especial."<<endl;
    cout<<"CÓMO JUGAR:"<<endl;
    cout<<"\tTablero: arreglo de puntos"<<endl;
    cout<<"\tTurnos: Los jugadores alternan turnos"<<endl;
    cout<<"\tMovimiento: Conectar dos puntos adyacentes con línea horizontal o vertical"<<endl;
    cout<<"Cuadrado completo: Al completar un cuadrado, el jugador gana:"<<endl;
    cout<<"\t1 punto"<<endl;
    cout<<"\tUn poder(en caso de que la casilla encerrada tenga una)"<<endl;
    cout<<"\tTurno extra"<<endl<<endl;
}

void TotitoChino::imprimirTablero() {
    cout<<"Tablero:"<<endl;
    IteradorMatriz<Casilla> *casillas = tableroJuego->getIteradorMatriz();
    for (int i = 0; i <= tableroJuego->getFila(); i++) {
        if (i == 1) {
            std::cout << std::to_string((i+1)/2) << ((i+1)/2 < 10 ? "  " : " ");
        } else {
            std::cout << "   ";
        }
        for (int j = 1; j <= tableroJuego->getColumna(); j++) {
            if (i == 0 ) {
                if (j % 2 != 0) {
                    std::cout << std::to_string(((j+1)/2)) << ((j+1)/2 < 10 ? "-  " : "- ");
                }
            } else {
                if (casillas->haySiguiente()) {
                    Casilla *casillaActual = casillas->getActual();
                    int fila = casillas->getFilaActual();
                    int columna = casillas->getColumnaActual();
                    while (fila != i) {
                        std::cout<<std::endl;
                        i++;
                        j = 1;
                        if (i % 2 != 0) {
                            std::cout << std::to_string((i+1)/2) << ((i+1)/2 < 10 ? "  " : " ");
                        }
                    }
                    while (columna != j) {
                        std::cout << (j % 2 == 0 ? "   ":  " ");
                        j++;
                    }
                    casillaActual->imprimir();
                } else {
                    std::cout << std::endl;
                    return;
                }
            }
        }
        std::cout << endl;
    }
    delete casillas;
}

void TotitoChino::iniciarJuego() {
    darDescripcion();
    auto *creadorMatriz = new CreadorDeMatriz();
    tableroJuego = creadorMatriz->crearMatriz();
    auto* registro = new RegistroJugadores(creadorMatriz->getLimiteJugadores());
    jugadores = registro->registrarJugadores();
    imprimirTablero();
    delete registro;
    delete creadorMatriz;
}