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
        actual = filaActual->getPrimero();
        return true;
    } else {
        actual = actual->getDerecha();
        return actual == nullptr ? haySiguiente(): true;
    }
}

template<typename T>
void IteradorMatriz<T>::getPosicionActual(int *posicionActual) {
    posicionActual[0] = -1;
    posicionActual[1] = -1;
    if (actual != nullptr) {
        posicionActual[0] = *actual->getFila();
        posicionActual[1] = *actual->getColumna();
    }
}



#endif