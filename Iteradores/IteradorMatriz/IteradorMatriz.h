//
// Created by rafael-cayax on 21/8/25.
//

#ifndef PRACTICA1EDD_ITERADOR_MATRIZ_H
#define PRACTICA1EDD_ITERADOR_MATRIZ_H
#include "../../estructuras_de_datos/MatrizD/ListaMatriz/ListaMatriz.h"
#include "../../estructuras_de_datos/MatrizD/NodoMatriz/NodoMatriz.h"

template<typename T>
class IteradorMatriz {
private:
    ListaMatriz<T> *filaActual;
    NodoMatriz<T> *actual;
public:
    IteradorMatriz(ListaMatriz<T> *cabecera):filaActual(cabecera), actual(nullptr) {}
    bool haySiguiente();
    T *getActual(){return actual->getElemento();}
    void getPosicionActual(int *posicionActual);
};

#include "IteradorMatriz.cpp"
#endif //PRACTICA1EDD_ITERADOR_MATRIZ_H