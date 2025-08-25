//
// Created by rafael-cayax on 24/8/25.
//

#ifndef PRACTICA1EDD_BUSCADORMATRIZ_H
#define PRACTICA1EDD_BUSCADORMATRIZ_H
#include "../NodoMatriz/NodoMatriz.h"
template <typename T> class Matriz;

template <typename T>
class BuscadorMatriz {
private:
    Matriz<T> *matriz;
public:
    BuscadorMatriz(Matriz<T> *matriz): matriz(matriz) {}
    NodoMatriz<T> *buscarColumna(int columna, bool crear);
    NodoMatriz<T> *buscarFila(int fila, bool crear);
};

#include "BuscadorMatriz.cpp"
#endif //PRACTICA1EDD_BUSCADORMATRIZ_H