//
// Created by rafael-cayax on 27/8/25.
//

#ifndef PRACTICA1EDD_ITERADORSIMPLE_CPP
#define PRACTICA1EDD_ITERADORSIMPLE_CPP
#include "IteradorSimple.h"

template<typename T>
bool IteradorSimple<T>::haySiguiente() {
    return actual != nullptr;
}

template<typename T>
T *IteradorSimple<T>::getActual() {
    NodoSimple<T> *aux = actual;
    actual = actual->getSiguiente();
    return aux->getElemento();
}


#endif