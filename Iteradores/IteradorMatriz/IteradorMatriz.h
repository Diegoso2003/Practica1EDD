//
// Created by rafael-cayax on 21/8/25.
//

#ifndef PRACTICA1EDD_ITERADOR_MATRIZ_H
#define PRACTICA1EDD_ITERADOR_MATRIZ_H
#include "../../estructuras_de_datos/MatrizD/NodoMatriz/NodoMatriz.h"

template<typename T>
class IteradorMatriz {
private:
    NodoMatriz<T> *filaActual;
    NodoMatriz<T> *actual;
public:
    IteradorMatriz(NodoMatriz<T> *cabecera):filaActual(cabecera), actual(nullptr) {}
    bool haySiguiente();
    NodoMatriz<T> *getActual(){return actual;}
};

#include "IteradorMatriz.cpp"
#endif //PRACTICA1EDD_ITERADOR_MATRIZ_H