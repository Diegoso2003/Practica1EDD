//
// Created by rafael-cayax on 25/8/25.
//

#include "ProcesadorOpciones.h"

#include <iostream>
#include <ostream>

#include "../TotitoChino.h"
#include "../ExtractorCoordenadas/ExtractorCoordenadas.h"
#include "../Jugador/Jugador.h"

ProcesadorOpciones::ProcesadorOpciones(TotitoChino *totitoChino) {
    this->totitoChino = totitoChino;
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
        } catch (const std::exception& e) {
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
            std::cout << std::endl;
            break;
        case 3:
            this->seguirJugando = false;
            break;
        default:
            std::cout << "otra opcion" <<std::endl;
    }
}

void ProcesadorOpciones::conectarLineas() {
    ExtractorCoordenadas *e = new ExtractorCoordenadas();
    bool hayError = false;
    do {
        if (hayError) {
            std::cout << "Ingrese coordenadas validas" << std::endl;
        }
        std::cout << "Ingrese las coordenadas de las lineas a unir" << std::endl;
        std::cout << "Usa: fila1,col1 -> fila2,col2" << std::endl;
        std::string entrada;
        std::getline(std::cin, entrada);
        hayError = !e->extraerDatos(entrada);
    }while (hayError);
    std::cout << "fila 1 ingresada: "<< e->getFila1() <<std::endl;
    std::cout << "columna 1 ingresada: "<< e->getColumna1() <<std::endl;
    std::cout << "fila 2 ingresada: "<< e->getFila2() <<std::endl;
    std::cout << "columna 2 ingresada: "<< e->getColumna2() <<std::endl;
    delete e;
}
