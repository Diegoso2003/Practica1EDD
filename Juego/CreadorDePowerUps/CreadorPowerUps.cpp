//
// Created by rafael-cayax on 23/8/25.
//

#include "CreadorPowerUps.h"
#include <random>
#include "../PowerUp/AQueCosto/AQueCosto.h"
#include "../PowerUp/Bloqueo/Bloqueo.h"
#include "../PowerUp/DobleLinea/DobleLinea.h"
#include "../PowerUp/Escurridizo/Escurridizo.h"
#include "../PowerUp/Explosivo/Explosivo.h"
#include "../PowerUp/LlaveSecreta/LlaveSecreta.h"
#include "../PowerUp/NuevasTierras/NuevasTierras.h"
#include "../PowerUp/Pase/Pase.h"
#include "../PowerUp/TrampaSecreta/TrampaSecreta.h"
#include "../PowerUp/UnionAFuturo/UnionAFuturo.h"

int CreadorPowerUps::obtenerNumeroAleatorio(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    int numeroAleatorio = dis(gen);
    return numeroAleatorio;
}


int CreadorPowerUps::calcularLimitePowerUps(int fila, int columna) {
    int totalCuadros = (fila - 1) * (columna-1);
    int minimos = totalCuadros / 4;
    int maximos = totalCuadros / 3;
    return obtenerNumeroAleatorio(minimos, maximos);
}

PowerUp *CreadorPowerUps::crearPowerUpAleatorio() {
    int numeroAleatorio = obtenerNumeroAleatorio(1, 10);
    switch (numeroAleatorio) {
        case 1:
            return new AQueCosto();
        case 2:
            return new Bloqueo();
        case 3:
            return new DobleLinea();
        case 4:
            return new Escurridizo();
        case 5:
            return new Explosivo();
        case 6:
            return new LlaveSecreta();
        case 7:
            return new NuevasTierras();
        case 8:
            return new Pase();
        case 9:
            return new TrampaSecreta();
        default:
            return new UnionAFuturo();
    }
}

void CreadorPowerUps::llenarTableroDePowerUps(Matriz<Casilla> *tablero) {
    int filas = (tablero->getFila() + 1) / 2;
    int columnas = (tablero->getColumna() + 1) / 2;
    int limite = calcularLimitePowerUps(filas, columnas);
    std::cout << "Limite: " << limite << std::endl;
    for (int i = limite; i > 0; i--) {
        int fila = 0;
        int columna = 0;
        do {
            fila = obtenerNumeroAleatorio(1, filas - 1);
            columna = obtenerNumeroAleatorio(1, columnas - 1);
            fila*=2;
            columna*=2;
        }while (tablero->getElemento(fila, columna) != nullptr);
        PowerUp *poder = crearPowerUpAleatorio();
        Casilla *casilla = new Casilla(poder);
        tablero->agregar(casilla, fila, columna);
    }
}
