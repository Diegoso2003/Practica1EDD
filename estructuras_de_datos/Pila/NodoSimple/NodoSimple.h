//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_NODO_SIMPLE_H
#define PRACTICA1EDD_NODO_SIMPLE_H

template <typename T>
class NodoSimple {
private:
    T *elemento;
    NodoSimple<T> *siguiente;
public:
    explicit NodoSimple(T *elemento);
    NodoSimple(T *elemento, NodoSimple<T> *siguiente);
    void setSiguiente(NodoSimple<T> *siguiente);
    NodoSimple<T> *getSiguiente() const;
    T *getElemento() const;
};

#include "NodoSimple.cpp"
#endif
