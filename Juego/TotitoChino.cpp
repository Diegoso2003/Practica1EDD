//
// Created by rafael-cayax on 18/8/25.
//

#include "TotitoChino.h"

TotitoChino::TotitoChino() : jugadores(nullptr), matrizPuntos(nullptr) {}

TotitoChino::~TotitoChino() {
    delete jugadores;
    delete matrizPuntos;
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


void TotitoChino::iniciarJuego() {
    darDescripcion();
    auto *creadorMatriz = new CreadorDeMatriz();
    matrizPuntos = creadorMatriz->crearMatriz();
    auto* registro = new RegistroJugadores(creadorMatriz->getLimiteJugadores());
    jugadores = registro->registrarJugadores();
    matrizPuntos->imprimir();
    delete registro;
    delete creadorMatriz;
}