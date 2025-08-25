//
// Created by rafael-cayax on 20/8/25.
//
#ifndef PRACTICA1EDD_MATRIZ_CPP
#define PRACTICA1EDD_MATRIZ_CPP
#include "Matriz.h"
#include "BuscadorMatriz/BuscadorMatriz.h"
#include "AgregarMatriz/AgregadorMatriz.h"

template<typename T>
Matriz<T>::Matriz() {
    cabecera = new NodoMatriz<T>(nullptr,new int(0), new int(0));
    fila = 0;
    columna = 0;
    ultimaColumna = cabecera;
    ultimaFila = cabecera;
    buscador = new BuscadorMatriz<T>(this);
    agregador = new AgregadorMatriz<T>(this);
}

template<typename T>
void Matriz<T>::llenarMatriz(ListaDobleEnlazada<T> *lista) {
    if (lista == nullptr  || lista->getTamaño() < fila*columna) {
        std::cout << "Ingrese correctamente los datos de la matriz" << std::endl;
        return;
    }
    fila = fila * 2 - 1;
    columna = columna * 2 - 1;
    NodoMatriz<T> *primeraColumna = nullptr;
    NodoMatriz<T> *ultimoNodoAgregado = nullptr;
    NodoMatriz<T> *nodoAuxiliar = nullptr;
    for (int i = 0; i <= fila; i++) {
        if (i != 0) {
            agregador->agregarNuevaFilaAbajo(i);
            ultimoNodoAgregado = ultimaFila;
            i++;
        }
        for (int j = 1; j <= columna; j+=2) {
            if (i == 0) {
                agregador->agregarNuevaColumnaDerecha(j);
                if (j == 1) {
                    primeraColumna = ultimaColumna;
                }
            } else {
                T *elemento = lista->eliminar(1);
                int *fila = ultimaFila->getFila();
                int *columna = nodoAuxiliar->getColumna();
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
    buscador = new BuscadorMatriz<T>(this);
    agregador = new AgregadorMatriz<T>(this);
    llenarMatriz(lista);
}

template<typename T>
Matriz<T>::~Matriz() {
    NodoMatriz<T> *auxiliar = ultimaFila;
    while (auxiliar != nullptr) {
        ultimaFila = ultimaFila->getArriba();
        delete auxiliar;
        auxiliar = ultimaFila;
    }
    delete agregador;
    delete buscador;
}

template<typename T>
void Matriz<T>::agregar(T *elemento, int fila, int columna) {
    NodoMatriz<T> *nodoColumna = buscador->buscarColumna(columna, true);
    NodoMatriz<T> *nuevoNodo = new NodoMatriz<T>(elemento);
    nuevoNodo->setColumna(nodoColumna->getColumna());
    if (!agregador->agregarDesdeColumna(fila, nuevoNodo, nodoColumna)) {
        NodoMatriz<T> *nodoFila = buscador->buscarFila(fila, true);
        nuevoNodo->setFila(nodoFila->getFila());
        agregador->agregarDesdeFila(columna, nuevoNodo, nodoFila);
    }
}

template<typename T>
T *Matriz<T>::getElemento(int fila, int columna) {
    NodoMatriz<T> *nodoColumna = buscador->buscarColumna(columna, false);
    if (nodoColumna == nullptr) {return nullptr;}
    while (nodoColumna->getAbajo() != nullptr && *nodoColumna->getFila() < fila) {
        nodoColumna = nodoColumna->getAbajo();
    }
    return *nodoColumna->getFila() == fila ? nodoColumna->getElemento() : nullptr;
}

#endif