//
// Created by rafael-cayax on 25/8/25.
//

#include "ProcesadorOpciones.h"

#include <iostream>
#include <ostream>

#include "../TotitoChino.h"
#include "../Jugador/Jugador.h"
#include "../../estructuras_de_datos/Pila/Pila.h"
#include "../Conversor/Auxiliar.h"
#include "../ManejadorPowerUp/ManejadorPowerUp.h"
#include "../PowerUp/PowerUp.h"

ProcesadorOpciones::ProcesadorOpciones(TotitoChino *totitoChino) {
    this->totitoChino = totitoChino;
    e = new ExtractorCoordenadas();
}

ProcesadorOpciones::~ProcesadorOpciones() {
    delete e;
}


void ProcesadorOpciones::mostrarOpciones() {
    bool hayError = false;
    int numero = 0;
    std::string entrada;
    do {
        if (hayError) {
            std::cout << "Ingrese Una opcion valida" << std::endl;
        }
        std::cout << "Turno de: " << std::endl;
        totitoChino->getJugadores()->obtener(1)->imprimirJugador();
        std::cout << "Opciones Disponibles: " << std::endl;
        std::cout << "1.Hacer una linea " << std::endl;
        std::cout << "2.Usar ultimo power up obtenido " << std::endl;
        std::cout << "3.acabar con el juego " << std::endl;
        std::getline(std::cin, entrada);
        try {
            size_t pos;
            numero = std::stoi(entrada, &pos);
            hayError = numero < 0 || numero > 3 || pos != entrada.size();
        } catch (const std::exception &e) {
            hayError = true;
        }
    } while (hayError);
    procesarOpcion(numero);
}

void ProcesadorOpciones::procesarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            conectarLineas();
            break;
        case 2:
            mostrarPowerUpsobtenidos();
            break;
        case 3:
            this->seguirJugando = false;
            break;
        default:
            std::cout << "otra opcion" << std::endl;
    }
}

void ProcesadorOpciones::conectarLineas() {
    bool hayError = false;
    do {
        if (hayError) {
            imprimirAdvertencia("Ingrese coordenadas validas");
        }
        std::cout << "Ingrese las coordenadas de las lineas a unir" << std::endl;
        std::cout << "Usa: fila1,col1 -> fila2,col2" << std::endl;
        std::string entrada;
        std::getline(std::cin, entrada);
        hayError = !e->extraerDatos(entrada);
    } while (hayError);
    totitoChino->conectarLinea(e->getFila1(), e->getColumna1(), e->getFila2(), e->getColumna2());
}

void ProcesadorOpciones::imprimirAdvertencia(std::string mensaje) {
    std::cout << Color::codigo(Color::Tipo::ROJO) << mensaje << Color::codigo(Color::Tipo::RESET) << std::endl;
}

void ProcesadorOpciones::mostrarPowerUpsobtenidos() {
    Pila<PowerUp> *pilaJugador = totitoChino->getJugadores()->obtener(1)->getPila();
    if (pilaJugador->estaVacia()) {
        std::cout << "No hay power ups para usar, presione enter para seguir" << std::endl;
        std::cin.ignore();
        std::cin.get();
        totitoChino->setDarTurnoExtra(true);
        return;
    }
    IteradorSimple<PowerUp> *iterador = pilaJugador->getIteradorSimple();
    std::cout << "PowerUps acumulados(Solo se puede usar el primero)" << std::endl;
    std::cout << "¿Usar primer power up? S/n" << std::endl;
    while (iterador->haySiguiente()) {
        iterador->getActual()->imprimir();
        std::cout << " ";
    }
    std::cout << std::endl;
    std::string entrada;
    std::getline(std::cin, entrada);
    entrada = Auxiliar::trim(entrada);
    if (entrada == "S" || entrada == "s") {
        PowerUp *powerUp = pilaJugador->desapilar();
        totitoChino->getManejador()->setPowerUp(powerUp);
    }
    totitoChino->setDarTurnoExtra(true);
}
