//
// Created by rafael-cayax on 26/8/25.
//

#ifndef PRACTICA1EDD_COLAENLAZADA_H
#define PRACTICA1EDD_COLAENLAZADA_H
#include "../Pila/NodoSimple/NodoSimple.h"

template <typename T>
class ColaEnlazada {
private:
    NodoSimple<T> *primeroEnlaCola;
    NodoSimple<T> *ultimoEnlaCola;
    int tamaño = 0;
public:
    ColaEnlazada() : primeroEnlaCola(nullptr), ultimoEnlaCola(nullptr) {};
    ~ColaEnlazada();
    void agregar(T *elemento);
    T *desencolar();
    T *getPrimeroEnlaCola(){return primeroEnlaCola->getElemento();}
    bool estaVacia(){return tamaño == 0;}
};

#include "ColaEnlazada.cpp"
#endif //PRACTICA1EDD_COLAENLAZADA_H