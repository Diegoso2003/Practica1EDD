//
// Created by rafael-cayax on 18/8/25.
//

#include "TotitoChino.h"
#include "RegistroJugadores/RegistroJugadores.h"

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

void TotitoChino::imprimirTablero() {
    cout<<"Tablero:"<<endl;
    IteradorMatriz<Punto> *puntos = matrizPuntos->getIteradorMatriz();
    puntos->haySiguiente();
    std::cout << "   ";
    for (int i = 0; i <= matrizPuntos->getFila(); i++) {
        if (i !=0) {
            std::cout << std::to_string(i) << (i < 10 ? "  " : " ");
        }
        for (int j = 1; j <= matrizPuntos->getColumna(); j++) {
            if (i == 0) {
                std::cout << std::to_string((j)) << (j < 10 ? "- " : "-");
            } else {
            Punto *puntoActual = puntos->getActual();
            int posicionActual[2];
            puntos->getPosicionActual(posicionActual);
            if (posicionActual[1] != j ) {
                std::cout << "   ";
            } else {
                puntoActual->imprimir();
                if (!puntos->haySiguiente()) {
                    break;
                }
            }
            }
        }
        std::cout << endl;
    }
    delete puntos;
}

void TotitoChino::iniciarJuego() {
    darDescripcion();
    auto *creadorMatriz = new CreadorDeMatriz();
    matrizPuntos = creadorMatriz->crearMatriz();
    auto* registro = new RegistroJugadores(creadorMatriz->getLimiteJugadores());
    jugadores = registro->registrarJugadores();
    imprimirTablero();
    delete registro;
    delete creadorMatriz;
}