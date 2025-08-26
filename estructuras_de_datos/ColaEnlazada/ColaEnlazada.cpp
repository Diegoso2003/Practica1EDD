//
// Created by rafael-cayax on 26/8/25.
//
#ifndef PRACTICA1EDD_COLAENLAZADA_CPP
#define PRACTICA1EDD_COLAENLAZADA_CPP
#include "ColaEnlazada.h"

template<typename T>
void ColaEnlazada<T>::agregar(T *elemento) {
    NodoSimple<T> *nodo = new NodoSimple<T>(elemento);
    if (estaVacia()) {
        primeroEnlaCola = nodo;
        ultimoEnlaCola = nodo;
    } else {
        ultimoEnlaCola->setSiguiente(nodo);
        ultimoEnlaCola = nodo;
    }
    tamaño++;
}

template<typename T>
T *ColaEnlazada<T>::desencolar() {
    T *elemento = primeroEnlaCola->getElemento();
    NodoSimple<T> *aux = primeroEnlaCola->getSiguiente();
    delete primeroEnlaCola;
    primeroEnlaCola = aux;
    return elemento;
}

template<typename T>
ColaEnlazada<T>::~ColaEnlazada() {
    while (!estaVacia()) {
        NodoSimple<T> *aux = primeroEnlaCola->getSiguiente();
        T *elemento = primeroEnlaCola->getElemento();
        delete elemento;
        delete primeroEnlaCola;
        primeroEnlaCola = aux;
        tamaño--;
    }
}

#endif