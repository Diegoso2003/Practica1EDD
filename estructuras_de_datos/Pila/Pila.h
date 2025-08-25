//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_PILA_H
#define PRACTICA1EDD_PILA_H
#include "NodoSimple/NodoSimple.h"

template<typename T>
class Pila {
private:
    int tamaño;
    NodoSimple<T> *primeroEnSalir;
public:
    Pila();
    ~Pila();
    bool estaVacia() const;
    int getTamaño() const;
    void encolar(T *elemento);
    T *desEncolar();
};

#include "Pila.cpp"
#endif //PRACTICA1EDD_PILA_H