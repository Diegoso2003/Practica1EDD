//
// Created by rafael-cayax on 13/8/25.
#ifndef COLA_CON_ARREGLO_CPP
#define COLA_CON_ARREGLO_CPP

#include "ColaConArreglo.h"
#include <iostream>
using namespace std;

template<typename T>
ColaConArreglo<T>::ColaConArreglo(int capacidad){
    this->elementos = new T*[capacidad];
    for (int i = 0; i < capacidad; i++) {
        this->elementos[i] = nullptr;
    }
    this->capacidad = capacidad;
    this->inicio = 0;
    this->final = 0;
    this->tamaño = 0;
}

template<typename T>
ColaConArreglo<T>::~ColaConArreglo() {
    for (int i = 0; i < this->capacidad; i++) {
        if (this->elementos[i] != nullptr) {
            delete this->elementos[i];
        }
    }
    delete[] this->elementos;
    this->elementos = nullptr;
    cout << "Cola destruida" << endl;
}

template<typename T>
void ColaConArreglo<T>::agregarALaCola(T *elemento) {
    if (tamaño < this->capacidad) {
        this->elementos[final++] = elemento;
        tamaño++;
        if (final == this->capacidad) {
            final = 0;
        }
    } else {
        cout << "Cola llena no se pudo agregar: " << elemento << endl;
    }
}

template<typename T>
T* ColaConArreglo<T>::SacarAlPrimero() {
    if (tamaño > 0) {
        tamaño--;
        T* elemento = elementos[inicio];
        this-elementos[inicio++] = nullptr;
        if (inicio == this->capacidad) {
            inicio = 0;
        }
        return elemento;
    }
    return nullptr;
}

template<typename T>
void ColaConArreglo<T>::imprimir(int principio, int final) {
    for (int i = principio; i < final; i++) {
        cout << this->elementos[i] << ", ";
    }
}

template<typename T>
void ColaConArreglo<T>::mostrarCola() {
    if (tamaño > 0) {
        if (inicio < final) {
            imprimir(inicio, final);
        } else {
            imprimir(inicio, capacidad);
            if (final != 0) {
                imprimir(0, final);
            }
        }
        cout << endl;
    } else {
        cout << "Cola vacia" << endl;
    }
}

template<typename T>
int ColaConArreglo<T>::getCapacidad() const {
    return capacidad;
}

template<typename T>
int ColaConArreglo<T>::getTamaño() const {
    return tamaño;
}

template<typename T>
T **ColaConArreglo<T>::getElementos() const {
    return elementos;
}

#endif