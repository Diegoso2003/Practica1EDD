//
// Created by rafael-cayax on 21/8/25.
//
#ifndef PRACTICA1EDD_ITERADOR_MATRIZ_CPP
#define PRACTICA1EDD_ITERADOR_MATRIZ_CPP
#include "IteradorMatriz.h"

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
        actual = actual->getDerecha();
        return actual == nullptr ? haySiguiente(): true;
    }
}


#endif