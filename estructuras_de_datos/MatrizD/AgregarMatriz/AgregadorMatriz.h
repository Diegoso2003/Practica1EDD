//
// Created by rafael-cayax on 24/8/25.
//

#ifndef PRACTICA1EDD_AGREGADORMATRIZ_H
#define PRACTICA1EDD_AGREGADORMATRIZ_H
#include "../NodoMatriz/NodoMatriz.h"
template<typename T> class Matriz;

template<typename T>
class AgregadorMatriz {
private:
    Matriz<T> *matriz;
    bool intentarAgregarDesdeColumna(int fila, NodoMatriz<T> *nodo);
    bool intentarConectarDerecha(int fila, NodoMatriz<T> *nodo, NodoMatriz<T> *nodoActual, bool arriba);
    bool intentarConectarIzquierda(int fila, NodoMatriz<T> *nodo, NodoMatriz<T> *nodoActual, bool arriba);
public:
    AgregadorMatriz(Matriz<T> *matriz): matriz(matriz) {}
    void agregarNuevaFilaAbajo(int fila);
    void agregarNuevaColumnaDerecha(int columna);
    void agregarDesdeFila(int columna, NodoMatriz<T> *nodo, NodoMatriz<T> *nodoFila);
    bool agregarDesdeColumna(int fila, NodoMatriz<T> *nodo, NodoMatriz<T> *nodoColumna);
};

#include "AgregadorMatriz.cpp"
#endif //PRACTICA1EDD_AGREGADORMATRIZ_H