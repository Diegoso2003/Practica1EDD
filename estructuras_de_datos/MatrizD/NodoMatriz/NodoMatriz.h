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
    NodoMatriz(T *elemento);
    ~NodoMatriz();
    bool esNodoCabecera(){return this->elemento == nullptr;}
    int *getFila(){return fila;}
    int *getColumna(){return columna;}
    NodoMatriz<T> *getDerecha(){return derecha;}
    NodoMatriz<T> *getIzquierda(){return izquierda;}
    NodoMatriz<T> *getArriba(){return arriba;}
    NodoMatriz<T> *getAbajo(){return abajo;}
    T* getElemento(){return elemento;}
    void setElemento(T *elemento){this->elemento = elemento;}
    void setDerecha(NodoMatriz<T> *derecha){this->derecha = derecha;}
    void setIzquierda(NodoMatriz<T> *izquierda){this->izquierda = izquierda;}
    void setArriba(NodoMatriz<T> *arriba){this->arriba = arriba;}
    void setAbajo(NodoMatriz<T> *abajo){this->abajo = abajo;};
    void setColumna(int *columna){this->columna = columna;}
    void setFila(int *fila){this->fila = fila;}
};

#include "NodoMatriz.cpp"
#endif //PRACTICA1EDD_NODOMATRIZ_H