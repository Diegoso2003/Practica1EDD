//
// Created by rafael-cayax on 21/8/25.
//

#ifndef PRACTICA1EDD_CREADORDEMATRIZ_H
#define PRACTICA1EDD_CREADORDEMATRIZ_H
#include <string>
#include <iostream>

#include "../../estructuras_de_datos/MatrizD/Matriz.h"
#include "../Punto/Punto.h"


class CreadorDeMatriz {
private:
    int limiteJugadores = 0;
    int minimoFilas = 3;
    int maximoFilas = 20;
    int minimoColumnas = 3;
    int maximoColumnas = 20;
    int pedirNumero(std::string &mensaje);
    bool esNumeroColumnasInvalido(int &numero) const;
    bool esNumeroFilasInvalido(int &numero) const;
    ListaDobleEnlazada<Punto> *crearPuntos(int &puntosTotales);
    void calcularMaximoJugadores(int &puntosTotales);
public:
    Matriz<Punto> *crearMatriz();
    int getLimiteJugadores(){return limiteJugadores;};
};


#endif //PRACTICA1EDD_CREADORDEMATRIZ_H