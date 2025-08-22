//
// Created by rafael-cayax on 20/8/25.
//
#ifndef PRACTICA1EDD_MATRIZ_CPP
#define PRACTICA1EDD_MATRIZ_CPP
#include "Matriz.h"

template<typename T>
Matriz<T>::Matriz() {
    cabecera = new NodoMatriz<T>(nullptr,new int(0), new int(0));
    ultimaColumna = cabecera;
    ultimaFila = cabecera;
}

template<typename T>
void Matriz<T>::agregarNuevaColumnaDerecha() {
    int columna = *ultimaColumna->getColumna();
    auto *nodo = new NodoMatriz<T>(nullptr,  new int(0), new int(++columna));
    ultimaColumna->setDerecha(nodo);
    nodo->setIzquierda(ultimaColumna);
    ultimaColumna = nodo;
}

template<typename T>
void Matriz<T>::agregarNuevaFilaAbajo() {
    int fila = *ultimaFila->getFila();
    auto *nodo = new NodoMatriz<T>(nullptr,new int(++fila),new int(0));
    ultimaFila->setAbajo(nodo);
    nodo->setArriba(ultimaFila);
    ultimaFila = nodo;
}


template<typename T>
void Matriz<T>::llenarMatriz(ListaDobleEnlazada<T> *lista) {
    if (lista == nullptr  || lista->getTamaño() < fila*columna) {
        std::cout << "Ingrese correctamente los datos de la matriz" << std::endl;
        return;
    }
    NodoMatriz<T> *primeraColumna = nullptr;
    NodoMatriz<T> *ultimoNodoAgregado = nullptr;
    NodoMatriz<T> *nodoAuxiliar = nullptr;
    for (int i = 0; i <= fila; i++) {
        if (i != 0) {
            agregarNuevaFilaAbajo();
            ultimoNodoAgregado = ultimaFila;
        }
        for (int j = 1; j <= columna; j++) {
            if (i == 0) {
                agregarNuevaColumnaDerecha();
                if (j == 1) {
                    primeraColumna = ultimaColumna;
                    nodoAuxiliar = primeraColumna;
                }
            } else {
                T* elemento = lista->eliminar(1);
                int* fila = ultimaFila->getFila();
                int* columna = nodoAuxiliar->getColumna();
                NodoMatriz<T> *nodoNuevo = new NodoMatriz<T>(elemento, fila, columna);
                ultimoNodoAgregado->setDerecha(nodoNuevo);
                nodoNuevo->setIzquierda(ultimoNodoAgregado);
                ultimoNodoAgregado = nodoNuevo;
                nodoAuxiliar->setAbajo(nodoNuevo);
                nodoNuevo->setArriba(nodoAuxiliar);
                nodoAuxiliar = nodoAuxiliar->getDerecha();
                if (j == 1) {
                    primeraColumna = nodoNuevo;
                }
                tamaño++;
            }
        }
        nodoAuxiliar = primeraColumna;
    }
}

template<typename T>
Matriz<T>::Matriz(int filas, int columnas, ListaDobleEnlazada<T>* lista) {
    this->fila = filas;
    this->columna = columnas;
    cabecera = new NodoMatriz<T>(nullptr,new int(0), new int(0));
    ultimaColumna = cabecera;
    ultimaFila = cabecera;
    llenarMatriz(lista);
}

template<typename T>
Matriz<T>::~Matriz() {
    NodoMatriz<T> *auxiliar = cabecera;
    while (auxiliar != nullptr) {
        cabecera = cabecera->getAbajo();
        delete auxiliar;
        auxiliar = cabecera;
    }
}

template<typename T>
void Matriz<T>::agregar(T *elemento, int fila, int columna) {

}

template<typename T>
T *Matriz<T>::getElemento(int fila, int columna) {
    return nullptr;
}

template<typename T>
void Matriz<T>::imprimir() {
    NodoMatriz<T> *filaActual = cabecera->getAbajo();
    while (filaActual != nullptr) {
        NodoMatriz<T> *elementoActual = filaActual->getDerecha();
        while (elementoActual != nullptr) {
            std::cout << *(elementoActual->getElemento()) << "  ";
            elementoActual = elementoActual->getDerecha();
        }
        std::cout << std::endl;
        filaActual = filaActual->getAbajo();
    }
}

#endif