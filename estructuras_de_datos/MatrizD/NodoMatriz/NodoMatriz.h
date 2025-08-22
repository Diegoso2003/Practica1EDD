//
// Created by rafael-cayax on 18/8/25.
//

#ifndef PRACTICA1EDD_NODO_MATRIZ_H
#define PRACTICA1EDD_NODO_MATRIZ_H
#include <iostream>

template <typename T>
class NodoMatriz {
private:
    int *fila;
    int *columna;
    NodoMatriz<T> *derecha;
    NodoMatriz<T> *izquierda;
    NodoMatriz<T> *arriba;
    NodoMatriz<T> *abajo;
    T *elemento;
public:
    NodoMatriz(T *elemento, int *fila, int *columna);
    ~NodoMatriz();
    int *getFila(){return fila;}
    int *getColumna(){return columna;}
    NodoMatriz<T> *getDerecha();
    NodoMatriz<T> *getIzquierda();
    NodoMatriz<T> *getArriba();
    NodoMatriz<T> *getAbajo();
    T* getElemento(){return elemento;}
    void setElemento(T *elemento){this->elemento = elemento;}
    void setDerecha(NodoMatriz<T> *derecha);
    void setIzquierda(NodoMatriz<T> *izquierda);
    void setArriba(NodoMatriz<T> *arriba);
    void setAbajo(NodoMatriz<T> *abajo);
};

#include "NodoMatriz.cpp"
#endif //PRACTICA1EDD_NODOMATRIZ_H