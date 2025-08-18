//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_NODO_SIMPLE_CPP
#define PRACTICA1EDD_NODO_SIMPLE_CPP
#include "NodoSimple.h"

template<typename T>
NodoSimple<T>::NodoSimple(T* elemento) {
    this->elemento = elemento;
    this->siguiente = nullptr;
}

template<typename T>
NodoSimple<T>::NodoSimple(T *elemento, NodoSimple<T> *siguiente) {
    this->elemento = elemento;
    this->siguiente = siguiente;
}

template<typename T>
void NodoSimple<T>::setSiguiente(NodoSimple<T> *siguiente) {
    this->siguiente = siguiente;
}

template<typename T>
NodoSimple<T> *NodoSimple<T>::getSiguiente() const {
    return this->siguiente;
}

template<typename T>
T *NodoSimple<T>::getElemento() const {
    return this->elemento;
}

#endif