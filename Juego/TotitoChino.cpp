//
// Created by rafael-cayax on 18/8/25.
//

#include "TotitoChino.h"
#include "RegistroJugadores/RegistroJugadores.h"
#include <iostream>

TotitoChino::TotitoChino() : jugadores(nullptr), tableroJuego(nullptr) {
    procesadorOpciones = new ProcesadorOpciones(this);
}

TotitoChino::~TotitoChino() {
    delete jugadores;
    delete tableroJuego;
    delete procesadorOpciones;
}

void TotitoChino::imprimirInformacionJugadores() {
    std::cout << "Orden en el que se establecieron los turnos: " << std::endl;
    IteradorLED<Jugador> *lista = jugadores->getIterador();
    while (lista->haySiguiente()) {
        lista->getActual()->imprimirJugador();
    }
    std::cout << "Presiona enter para empezar "<<std::endl;
    std::cin.ignore();
    std::cin.get();
}


void TotitoChino::darDescripcion() {
    std::cout<<"TOTITO CHINO: "<<std::endl;
    std::cout<<"OBJETIVO:"<<std::endl;
    std::cout<<"\tFormar el mayor número de cuadrados conectando puntos adyacentes." << std::endl;
    std::cout<<"\tCada cuadrado completo otorga 1 punto y en caso de tener, un poder especial."<<std::endl;
    std::cout<<"CÓMO JUGAR:"<<std::endl;
    std::cout<<"\tTablero: arreglo de puntos"<<std::endl;
    std::cout<<"\tTurnos: Los jugadores alternan turnos"<<std::endl;
    std::cout<<"\tMovimiento: Conectar dos puntos adyacentes con línea horizontal o vertical"<<std::endl;
    std::cout<<"Cuadrado completo: Al completar un cuadrado, el jugador gana:"<<std::endl;
    std::cout<<"\t1 punto"<<std::endl;
    std::cout<<"\tUn poder(en caso de que la casilla encerrada tenga una)"<<std::endl;
    std::cout<<"\tTurno extra"<<std::endl<<std::endl;
    std::cout << "Para conectar dos puntos vecinos:" << std::endl;
    std::cout << "Usa: fila1,col1 -> fila2,col2" << std::endl << std::endl;
    std::cout << "Ejemplos:" << std::endl;
    std::cout << "- 5,10 -> 5,11 (horizontal)" << std::endl;
    std::cout << "- 3,8 -> 4,8 (vertical)" << std::endl << std::endl;
    std::cout << "Reglas:" << std::endl;
    std::cout << "- Puntos deben estar juntos (horizontal o vertical)." << std::endl;
    std::cout << "- No debe existir una linea ya entre ellos." << std::endl;
    std::cout << "- Coordenadas entre las dimensiones del tablero." << std::endl<< std::endl;
}

void TotitoChino::imprimirTablero() {
    std::cout<<"Tablero:"<<std::endl;
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
                    std::cout << std::to_string(((j+1)/2)) << ((j+1)/2 < 10 ? "   " : "  ");
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
        std::cout << std::endl;
    }
    delete casillas;
}

void TotitoChino::iniciarJuego() {
    darDescripcion();
    auto *creadorMatriz = new CreadorDeMatriz();
    tableroJuego = creadorMatriz->crearMatriz();
    auto* registro = new RegistroJugadores(creadorMatriz->getLimiteJugadores());
    jugadores = registro->registrarJugadores();
    imprimirInformacionJugadores();
    imprimirTablero();
    do {
        procesadorOpciones->mostrarOpciones();
        imprimirTablero();
    }while (procesadorOpciones->getSeguirJugando());
    delete registro;
    delete creadorMatriz;
}
