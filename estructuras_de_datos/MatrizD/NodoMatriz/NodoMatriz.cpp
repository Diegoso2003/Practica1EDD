//
// Created by rafael-cayax on 18/8/25.
//
#ifndef PRACTICA1EDD_NODO_MATRIZ_CPP
#define PRACTICA1EDD_NODO_MATRIZ_CPP
#include "NodoMatriz.h"

template<typename T>
NodoMatriz<T>::NodoMatriz(T *elemento, int *fila, int *columna) {
    this->elemento = elemento;
    this->fila = fila;
    this->columna = columna;
    this->abajo = nullptr;
    this->derecha = nullptr;
    this->izquierda = nullptr;
    this->arriba = nullptr;
}

template<typename T>
NodoMatriz<T>::NodoMatriz(T *elemento) {
    this->elemento = elemento;
    this->fila = nullptr;
    this->columna = nullptr;
    this->abajo = nullptr;
    this->derecha = nullptr;
    this->izquierda = nullptr;
    this->arriba = nullptr;
}

template<typename T>
NodoMatriz<T>::~NodoMatriz() {
    //std::cout << "Destruindo NodoMatriz: fila: " << *fila << " columna: "<< *columna << std::endl;
    delete elemento;
    delete derecha;
    if (elemento == nullptr) {
        delete fila;
        delete columna;
    }
}

#endif