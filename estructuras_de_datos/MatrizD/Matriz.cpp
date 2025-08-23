//
// Created by rafael-cayax on 20/8/25.
//
#ifndef PRACTICA1EDD_MATRIZ_CPP
#define PRACTICA1EDD_MATRIZ_CPP
#include "Matriz.h"

template<typename T>
Matriz<T>::Matriz() {
    cabecera = new NodoMatriz<T>(nullptr,new int(0), new int(0));
    fila = 0;
    columna = 0;
    ultimaColumna = cabecera;
    ultimaFila = cabecera;
}

template<typename T>
void Matriz<T>::agregarNuevaColumnaDerecha(int columna) {
    auto *nodo = new NodoMatriz<T>(nullptr,  new int(0), new int(columna));
    ultimaColumna->setDerecha(nodo);
    nodo->setIzquierda(ultimaColumna);
    ultimaColumna = nodo;
}

template<typename T>
void Matriz<T>::agregarNuevaFilaAbajo(int fila) {
    auto *nodo = new NodoMatriz<T>(nullptr,new int(fila),new int(0));
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
            agregarNuevaFilaAbajo(i);
            ultimoNodoAgregado = ultimaFila;
        }
        for (int j = 1; j <= columna; j++) {
            if (i == 0) {
                agregarNuevaColumnaDerecha(j);
                if (j == 1) {
                    primeraColumna = ultimaColumna;
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
NodoMatriz<T> *Matriz<T>::buscarColumna(int columna, bool crear) {
    int numero = this->columna / 2;
    bool buscarInicio = numero > columna;
    NodoMatriz<T> *auxiliar = buscarInicio ? cabecera : ultimaColumna;
    while (auxiliar != nullptr) {
        int columnaActual = *auxiliar->getColumna();
        if (columnaActual == columna) {
            return auxiliar;
        }
        if (buscarInicio && columnaActual > columna) {
            if (crear) {
                NodoMatriz<T> *nodoNuevo = new NodoMatriz<T>(nullptr, new int(0), new int(columna));
                NodoMatriz<T> auxiliar2 = auxiliar->getIzquierda();
                auxiliar2->setDerecha(nodoNuevo);
                nodoNuevo->setIzquierda(auxiliar2);
                auxiliar->setIzquierda(nodoNuevo);
                nodoNuevo->setDerecha(auxiliar);
            }
            return nullptr;
        }
        if (!buscarInicio && columnaActual < columna) {
            if (crear) {
                if (columna > this->columna) {
                    agregarNuevaColumnaDerecha(columna);
                    columna++;
                    return ultimaColumna;
                }
                NodoMatriz<T> *nuevoNodo = new NodoMatriz<T>(nullptr, new int(0), new int(columna));
                NodoMatriz<T> *auxiliar2 = auxiliar->getDerecha();
                auxiliar->setDerecha(nuevoNodo);
                nuevoNodo->setIzquierda(auxiliar);
                auxiliar2->setIzquierda(nuevoNodo);
                nuevoNodo->setDerecha(auxiliar2);
                return nuevoNodo;
            }
            return nullptr;
        }
        auxiliar = buscarInicio ? auxiliar->getDerecha() : auxiliar->getIzquierda();
      }
    return nullptr;
}

template<typename T>
NodoMatriz<T> *Matriz<T>::buscarFila(int fila, bool crear) {
    int numero = this->fila / 2;
    bool buscarInicio = numero > fila;
    NodoMatriz<T> auxiliar = buscarInicio ? cabecera : ultimaFila;
    while (auxiliar != nullptr) {
        int filaActual = *auxiliar->getFila();
        if (filaActual == fila) {
            return auxiliar;
        }
        if (buscarInicio && filaActual > fila) {
            if (crear) {
                NodoMatriz<T> *nodoNuevo = new NodoMatriz<T>(nullptr, new int(fila), new int(0));
                NodoMatriz<T> *auxiliar2 = auxiliar->getArriba();
                nodoNuevo->setArriba(auxiliar2);
                auxiliar2->setAbajo(nodoNuevo);
                auxiliar->setArriba(nodoNuevo);
                nodoNuevo->setAbajo(auxiliar);
            }
            return nullptr;
        }
        if (!buscarInicio && filaActual < fila) {
            if (crear) {
                if (fila > this->fila) {
                    agregarNuevaFilaAbajo(fila);
                    fila++;
                    return ultimaFila;
                }
                NodoMatriz<T> *nodoNuevo = new NodoMatriz<T>(nullptr, new int(fila), new int(0));
                NodoMatriz<T> *auxiliar2 = auxiliar->getArriba();
                nodoNuevo->setAbajo(auxiliar2);
                auxiliar2->setArriba(nodoNuevo);
                auxiliar->setAbajo(nodoNuevo);
                nodoNuevo->setArriba(auxiliar);
            }
            return nullptr;
        }
        auxiliar = buscarInicio ? auxiliar->getAbajo() : auxiliar->getArriba();
    }
}


template<typename T>
void Matriz<T>::agregar(T *elemento, int fila, int columna) {
}

template<typename T>
T *Matriz<T>::getElemento(int fila, int columna) {
    return nullptr;
}

#endif