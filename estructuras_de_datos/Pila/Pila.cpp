//
// Created by rafael-cayax on 17/8/25.
//
#ifndef PRACTICA1EDD_PILA_CPP
#define PRACTICA1EDD_PILA_CPP

#include "Pila.h"
template<typename T>
Pila<T>::Pila() {
    this->primeroEnSalir = nullptr;
    this->tamaño = 0;
}

template<typename T>
Pila<T>::~Pila() {
    NodoSimple<T> *aux = nullptr;
    do {
        aux = primeroEnSalir->getSiguiente();
        T* elemento = primeroEnSalir->getElemento();
        delete elemento;
        delete primeroEnSalir;
        primeroEnSalir = aux;
    }while (primeroEnSalir != nullptr);
}

template<typename T>
bool Pila<T>::estaVacia() const {
    return tamaño == 0;
}

template<typename T>
void Pila<T>::apilar(T *elemento) {
    primeroEnSalir = new NodoSimple<T>(elemento, primeroEnSalir);
    tamaño++;
}

template<typename T>
T *Pila<T>::desapilar() {
    if (estaVacia()) {
        return nullptr;
    }
    T* elemento = primeroEnSalir->getElemento();
    NodoSimple<T> *aux = primeroEnSalir->getSiguiente();
    delete primeroEnSalir;
    primeroEnSalir = aux;
    tamaño--;
    return elemento;
}

template<typename T>
int Pila<T>::getTamaño() const {
    return tamaño;
}

#endif