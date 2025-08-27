//
// Created by rafael-cayax on 27/8/25.
//

#ifndef PRACTICA1EDD_ITERADORSIMPLE_H
#define PRACTICA1EDD_ITERADORSIMPLE_H
#include "../../estructuras_de_datos/Pila/NodoSimple/NodoSimple.h"

template<typename T>
class IteradorSimple {
private:
    NodoSimple<T> *actual = nullptr;
public:
    explicit IteradorSimple(NodoSimple<T> *primero): actual(primero) {}
    bool haySiguiente();
    T *getActual();
};

#include "IteradorSimple.cpp"
#endif //PRACTICA1EDD_ITERADORSIMPLE_H