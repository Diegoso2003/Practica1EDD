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
NodoMatriz<T>::~NodoMatriz() {
    delete elemento;
    delete derecha;
}


template<typename T>
NodoMatriz<T> *NodoMatriz<T>::getAbajo() {
    return abajo;
}

template<typename T>
NodoMatriz<T> *NodoMatriz<T>::getIzquierda() {
    return izquierda;
}

template<typename T>
NodoMatriz<T> *NodoMatriz<T>::getArriba() {
    return arriba;
}

template<typename T>
NodoMatriz<T> *NodoMatriz<T>::getDerecha() {
    return derecha;
}

template<typename T>
void NodoMatriz<T>::setAbajo(NodoMatriz<T> *abajo) {
    this->abajo = abajo;
}

template<typename T>
void NodoMatriz<T>::setArriba(NodoMatriz<T> *arriba) {
    this->arriba = arriba;
}

template<typename T>
void NodoMatriz<T>::setIzquierda(NodoMatriz<T> *izquierda) {
    this->izquierda = izquierda;
}

template<typename T>
void NodoMatriz<T>::setDerecha(NodoMatriz<T> *derecha) {
    this->derecha = derecha;
}
#endif