//
// Created by rafael-cayax on 18/8/25.
//

#include "TotitoChino.h"
#include "RegistroJugadores/RegistroJugadores.h"
#include "Linea/Linea.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "ManejadorPowerUp/ManejadorPowerUp.h"

#include "Conversor/Auxiliar.h"
#include "VerificadorCuadros/VerificadorCuadros.h"

TotitoChino::TotitoChino() : jugadores(nullptr), tableroJuego(nullptr), jugadorPunto(nullptr), jugadorCasilla(nullptr) {
    procesadorOpciones = new ProcesadorOpciones(this);
    manejador = new ManejadorPowerUp(this);
}

TotitoChino::~TotitoChino() {
    delete jugadores;
    delete tableroJuego;
    delete procesadorOpciones;
    delete manejador;
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
    jugadorCasilla = jugadores->obtener(1);
    jugadorPunto = jugadorCasilla;
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
        if (i != 0 && i % 2 != 0) {
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
    cuadradosDisponibles = (Auxiliar::numeroI(tableroJuego->getFila())-1)*
        (Auxiliar::numeroI(tableroJuego->getColumna())-1);
    auto* registro = new RegistroJugadores(creadorMatriz->getLimiteJugadores());
    jugadores = registro->registrarJugadores();
    imprimirInformacionJugadores();
    delete registro;
    delete creadorMatriz;
    do {
        manejador->activarPowerUp();
        std::cout<<std::endl;
        std::cout<<std::endl;
        imprimirTablero();
        procesadorOpciones->mostrarOpciones();
        cambiarTurno();
    }while (procesadorOpciones->getSeguirJugando() && cuadradosDisponibles > cuadrosTotales);
}

bool TotitoChino::esHorizontal(int fila1, int columna1, int fila2, int columna2) {
    return fila1 == fila2 && std::abs(columna1 - columna2) == 1;
}

bool TotitoChino::esVertical(int fila1, int columna1, int fila2, int columna2) {
    return columna1 == columna2 && std::abs(fila1 - fila2) == 1;
}


void TotitoChino::conectarLinea(int fila1, int columna1, int fila2, int columna2) {
    bool horizontal = esHorizontal(fila1, columna1, fila2, columna2);
    bool vertical = esVertical(fila1, columna1, fila2, columna2);
    if (!vertical && !horizontal) {
        imprimirAdvertencia("No es posible conectar los puntos");
        return;
    }
    int fila1real = Auxiliar::coordenadaR(fila1);
    int columna1real = Auxiliar::coordenadaR(columna1);
    int fila2real = Auxiliar::coordenadaR(fila2);
    int columna2real = Auxiliar::coordenadaR(columna2);
    NodoMatriz<Casilla> *casillaPunto1 = tableroJuego->getNodo(fila1real, columna1real);
    NodoMatriz<Casilla> *casillaPunto2 = tableroJuego->getNodo(fila2real, columna2real);
    if (casillaPunto1 == nullptr || casillaPunto2 == nullptr) {
        imprimirAdvertencia("Uno de los dos puntos ingresados no existen");
        return;
    }
    int filalinea = (fila1real + fila2real)/2;
    int columnalinea = (columna1real + columna2real)/2;
    if (tableroJuego->getElemento(filalinea, columnalinea) == nullptr) {
        Linea *linea = new Linea(vertical, jugadores->obtener(1));
        Casilla *casilla = new Casilla(linea);
        tableroJuego->agregar(casilla, filalinea, columnalinea);
        verificarLinea(casillaPunto1, casillaPunto2);
    } else {
        imprimirAdvertencia("No se puede ingresar una linea que ya este creada");
    }
}

void TotitoChino::cambiarTurno() {
    if (!darTurnoExtra) {
        Jugador *aux = jugadores->eliminar(1);
        jugadores->agregar(aux);
        jugadorCasilla = jugadores->obtener(1);
        jugadorPunto = jugadorCasilla;
    } else {
        darTurnoExtra = false;
    }
}

void TotitoChino::imprimirAdvertencia(std::string mensaje) {
    darTurnoExtra = true;
    std::cout<< Color::codigo(Color::Tipo::ROJO) <<mensaje << Color::codigo(Color::Tipo::RESET) <<std::endl;
}

void TotitoChino::verificarLinea(NodoMatriz<Casilla> *punto1, NodoMatriz<Casilla> *punto2) {
    VerificadorCuadros verificador;
    bool vertical = esVertical(Auxiliar::numeroI(*punto1->getFila()),
        Auxiliar::numeroI(*punto1->getColumna()), Auxiliar::numeroI(*punto2->getFila()),
        Auxiliar::numeroI(*punto2->getColumna()));
    if (verificador.verificarConeccion(punto1, punto2, vertical)) {
        int fila = (*punto1->getFila()+*punto2->getFila())/2;
        int columna = (*punto2->getColumna()+*punto1->getColumna())/2;
        if (vertical) {
            columna = verificador.esDerecha() ? columna+1 : columna-1;
        } else {
            fila = verificador.esArriba() ? fila-1 : fila+1;
        }
        Casilla *casilla = tableroJuego->getElemento(fila, columna);
        if (casilla == nullptr) {
            Casilla *casilla = new Casilla(jugadorCasilla);
            tableroJuego->agregar(casilla, fila, columna);
        } else {
            PowerUp *power = casilla->getPowerUp();
            jugadorCasilla->agregarPowerUp(power);
            casilla->setJugador(jugadorCasilla);
        }
        jugadorPunto->incrementarPunteo(puntosOtorgados);
        puntosOtorgados = 1;
        cuadrosTotales++;
        darTurnoExtra = true;
    }
}
