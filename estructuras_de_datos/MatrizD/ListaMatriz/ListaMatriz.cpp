//
// Created by rafael-cayax on 23/8/25.
//
#ifndef PRACTICA1EDD_LISTAMATRIZ_CPP
#define PRACTICA1EDD_LISTAMATRIZ_CPP
#include "ListaMatriz.h"

template<typename T>
ListaMatriz<T>::ListaMatriz(int *fila, int *columna) {
    this->columna = columna;
    this->fila = fila;
    primero = nullptr;
    ultimo = nullptr;
    tamaño = 0;
    arriba = nullptr;
    abajo = nullptr;
    izquierda = nullptr;
    derecha = nullptr;
}

template<typename T>
bool ListaMatriz<T>::intentarConectarDesdeColumna(int fila, NodoMatriz<T> *nodo) {
    return false;
}


template<typename T>
void ListaMatriz<T>::agregarNodoDesdeFila(int columna, NodoMatriz<T> *nodo) {
    if (estaVacia()) {
        primero = nodo;
        ultimo = nodo;
        tamaño++;
        return;
    }
    if (columna < *primero->getColumna()) {
        primero->setIzquierda(nodo);
        nodo->setDerecha(primero);
        primero = nodo;
        tamaño++;
        return;
    }
    if (columna > *ultimo->getColumna()) {
        ultimo->setDerecha(nodo);
        nodo->setIzquierda(ultimo);
        ultimo = nodo;
        tamaño++;
        return;
    }
    int mitadTamaño = tamaño / 2;
    bool buscarDesdeInicio = columna > mitadTamaño;
    bool agregado = false;
    NodoMatriz<T> *nodoAuxiliar = buscarDesdeInicio ? primero : ultimo;
    do {
        if (buscarDesdeInicio && *nodoAuxiliar->getColumna() > columna) {
            nodoAuxiliar->getIzquierda()->setDerecha(nodo);
            nodo->setIzquierda(nodoAuxiliar->getIzquierda());
            nodo->setDerecha(nodoAuxiliar);
            nodoAuxiliar->setIzquierda(nodo);
            agregado = true;
        } else if (!buscarDesdeInicio && *nodoAuxiliar->getColumna() < columna) {
            nodoAuxiliar->getDerecha()->setIzquierda(nodo);
            nodo->setDerecha(nodoAuxiliar->getDerecha());
            nodo->setIzquierda(nodoAuxiliar);
            nodoAuxiliar->setDerecha(nodo);
            agregado = true;
        }
    }while (!agregado);
    tamaño++;
}

template<typename T>
bool ListaMatriz<T>::agregarNodoDesdeColumna(int fila, NodoMatriz<T> *nodo) {
    if (estaVacia()) {
        primero = nodo;
        ultimo = nodo;
        tamaño++;
        return false;
    }
    if (fila < *primero->getFila()) {
        primero->setArriba(nodo);
        nodo->setAbajo(primero);
        primero = nodo;
        tamaño++;
        return intentarConectarDesdeColumna(fila, nodo);
    }
    if (fila > *ultimo->getColumna()) {
        ultimo->setAbajo(nodo);
        nodo->setArriba(ultimo);
        ultimo = nodo;
        tamaño++;
        return intentarConectarDesdeColumna(fila, nodo);
    }
    int mitadTamaño = tamaño / 2;
    bool buscarDesdeInicio = fila > mitadTamaño;
    bool agregado = false;
    NodoMatriz<T> *nodoAuxiliar = buscarDesdeInicio ? primero : ultimo;
    do {
        if (buscarDesdeInicio && *nodoAuxiliar->getFila() > fila) {
            nodoAuxiliar->getArriba()->setAbajo(nodo);
            nodo->setArriba(nodoAuxiliar->getArriba());
            nodo->setAbajo(nodoAuxiliar);
            nodoAuxiliar->setArriba(nodo);
            agregado = true;
        } else if (!buscarDesdeInicio && *nodoAuxiliar->getFila() < fila) {
            nodoAuxiliar->getAbajo()->setArriba(nodo);
            nodo->setAbajo(nodoAuxiliar->getAbajo());
            nodo->setArriba(nodoAuxiliar);
            nodoAuxiliar->setAbajo(nodo);
            agregado = true;
        }
    }while (!agregado);
    tamaño++;
    return intentarConectarDesdeColumna(fila, nodo);
}

template<typename T>
void ListaMatriz<T>::actualizarUltimoYPrimero() {
    if (*fila != 0) {
        while (primero->getArriba() != nullptr) {
            primero->getArriba();
        }
        while (ultimo->getAbajo() != nullptr) {
            ultimo = ultimo->getAbajo();
        }
    } else {
        while (primero->getIzquierda() != nullptr) {
            primero = primero->getIzquierda();
        }
        while (ultimo->getDerecha() != nullptr) {
            ultimo = ultimo->getDerecha();
        }
    }
}

template<typename T>
ListaMatriz<T>::~ListaMatriz() {
    if (*fila != 0) {
        delete primero;
    } else {
        delete derecha;
    }
    std::cout << "eliminando fila: " << *fila << ", columna: " << *columna << std::endl;
    delete fila;
    delete columna;
}

#endif