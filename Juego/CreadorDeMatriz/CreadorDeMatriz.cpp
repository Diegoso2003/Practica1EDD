//
// Created by rafael-cayax on 21/8/25.
//

#include "CreadorDeMatriz.h"

int CreadorDeMatriz::pedirNumero(std::string &mensaje) {
    bool hayError = false;
    int numero = 0;
    std::string entrada;
    do {
        if (hayError) {
            std::cout << "Ingrese los datos solicitados correctamente" << std::endl;
            hayError = false;
        }
        std::cout << mensaje << std::endl;
        std::getline(std::cin, entrada);
        try {
            numero = std::stoi(entrada);
        } catch (const std::exception& e) {
            hayError = true;
        }
    } while (hayError);
    return numero;
}

bool CreadorDeMatriz::esNumeroColumnasInvalido(int &numero) const{
    return numero > maximoColumnas || numero < minimoColumnas;
}

bool CreadorDeMatriz::esNumeroFilasInvalido(int &numero) const {
    return numero > maximoFilas || numero < minimoFilas;
}

ListaDobleEnlazada<Punto> *CreadorDeMatriz::crearPuntos(int &puntosTotales) {
    auto *listaDoble = new ListaDobleEnlazada<Punto>();
    for (int i = 0; i < puntosTotales; i++) {
        listaDoble->agregar(new Punto);
    }
    return listaDoble;
}

void CreadorDeMatriz::calcularMaximoJugadores(int &puntosTotales) {
    if (puntosTotales <= 16) {
        limiteJugadores = 2;
    } else if (puntosTotales <= 36) {
        limiteJugadores = 3;
    } else if (puntosTotales <= 64) {
        limiteJugadores = 4;
    } else if (puntosTotales <= 128) {
        limiteJugadores = 5;
    } else {
        limiteJugadores = 6;
    }
}


Matriz<Punto> *CreadorDeMatriz::crearMatriz() {
    bool hayError = false;
    int filas;
    int columnas;
    do {
        if (hayError) {
            std::cout << "Ingrese correctamente los valores solicitados" << std::endl;
            hayError = false;
        }
        std::string mensaje = "Ingrese el numero de filas del tablero, min: ";
        mensaje.append(std::to_string(minimoFilas))
        .append(", max: ")
        .append(std::to_string(maximoFilas));
        filas = pedirNumero(mensaje);
        mensaje = "Ingrese el numero de columnas del tablero, min: ";
        mensaje.append(std::to_string(minimoColumnas))
        .append(", max: ")
        .append(std::to_string(maximoColumnas));
        columnas = pedirNumero(mensaje);
        hayError = esNumeroColumnasInvalido(columnas);
        hayError = esNumeroFilasInvalido(filas);
    }while (hayError);
    int totalPuntos = filas * columnas;
    auto *listaDoble = crearPuntos(totalPuntos);
    auto *matriz = new Matriz<Punto>(filas, columnas, listaDoble);
    delete listaDoble;
    calcularMaximoJugadores(totalPuntos);
    return matriz;
}
