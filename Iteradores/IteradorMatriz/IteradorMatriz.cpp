//
// Created by rafael-cayax on 21/8/25.
//
#ifndef PRACTICA1EDD_ITERADOR_MATRIZ_CPP
#define PRACTICA1EDD_ITERADOR_MATRIZ_CPP
#include "IteradorMatriz.h"
#include <array>

template<typename T>
bool IteradorMatriz<T>::haySiguiente(){
    if (filaActual == nullptr) {
        return false;
    }
    if (actual == nullptr) {
        filaActual = filaActual->getAbajo();
        if (filaActual == nullptr) {
            return false;
        }
        actual = filaActual->getDerecha();
        return true;
    } else {
        anterior = actual;
        actual = actual->getDerecha();
        return actual == nullptr ? haySiguiente(): true;
    }
}

template<typename T>
void IteradorMatriz<T>::retroceder() {
    actual = anterior;
}


template<typename T>
int IteradorMatriz<T>::getColumnaActual() {
    if (actual == nullptr) { return -1;}
    return *actual->getColumna();
}

template<typename T>
int IteradorMatriz<T>::getFilaActual() {
    if (actual == nullptr) { return -1;}
    return *actual->getFila();
}

#endif