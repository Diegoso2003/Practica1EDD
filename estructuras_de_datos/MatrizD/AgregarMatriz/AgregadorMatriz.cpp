//
// Created by rafael-cayax on 24/8/25.
//
#ifndef PRACTICA1EDD_AGREGADOR_MATRIZ_CPP
#define PRACTICA1EDD_AGREGADOR_MATRIZ_CPP

#include "AgregadorMatriz.h"
#include "../NodoMatriz/NodoMatriz.h"

template<typename T>
void AgregadorMatriz<T>::agregarNuevaColumnaDerecha(int columna) {
    auto *nodo = new NodoMatriz<T>(nullptr,  new int(0), new int(columna));
    matriz->getUltimaColumna()->setDerecha(nodo);
    nodo->setIzquierda(matriz->getUltimaColumna());
    matriz->setUltimaColumna(nodo);
}

template<typename T>
bool AgregadorMatriz<T>::agregarDesdeColumna(int fila, NodoMatriz<T> *nodo, NodoMatriz<T> *nodoColumna) {
    while (nodoColumna->getAbajo() != nullptr && *nodoColumna->getFila() < fila) {
        nodoColumna = nodoColumna->getAbajo();
    }
    if (nodoColumna->getAbajo() == nullptr) {
        nodoColumna->setAbajo(nodo);
        nodo->setArriba(nodoColumna);
    } else {
        nodoColumna->getArriba()->setAbajo(nodo);
        nodo->setArriba(nodoColumna->getArriba());
        nodoColumna->setArriba(nodo);
        nodo->setAbajo(nodoColumna);
    }
    return intentarAgregarDesdeColumna(fila, nodo);
}

template<typename T>
void AgregadorMatriz<T>::agregarDesdeFila(int columna, NodoMatriz<T> *nodo, NodoMatriz<T> *nodoFila) {
    while (nodoFila->getDerecha() != nullptr && *nodoFila->getColumna() < columna) {
        nodoFila = nodoFila->getDerecha();
    }
    if (nodoFila->getDerecha() == nullptr) {
        nodoFila->setDerecha(nodo);
        nodo->setIzquierda(nodoFila);
    } else {
        nodoFila->getIzquierda()->setDerecha(nodo);
        nodo->setIzquierda(nodoFila->getIzquierda());
        nodoFila->setIzquierda(nodo);
        nodo->setDerecha(nodoFila);
    }
}

template<typename T>
bool AgregadorMatriz<T>::intentarAgregarDesdeColumna(int fila, NodoMatriz<T> *nodo) {
    bool arriba = false;
    NodoMatriz<T> *aux = nodo;

}


template<typename T>
void AgregadorMatriz<T>::agregarNuevaFilaAbajo(int fila) {
    auto *nodo = new NodoMatriz<T>(nullptr,new int(fila),new int(0));
    matriz->getUltimaFila()->setAbajo(nodo);
    nodo->setArriba(matriz->getUltimaFila());
    matriz->setUltimaFila(nodo);
}

#endif