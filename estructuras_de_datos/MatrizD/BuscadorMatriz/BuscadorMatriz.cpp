//
// Created by rafael-cayax on 24/8/25.
//
#ifndef PRACTICA1EDD_BUSCADORMATRIZ_CPP
#define PRACTICA1EDD_BUSCADORMATRIZ_CPP
#include "BuscadorMatriz.h"
#include "../Matriz.h"
template<typename T>
NodoMatriz<T> *BuscadorMatriz<T>::buscarColumna(int columna, bool crear) {
    int numero = this->matriz->getColumna() / 2;
    bool buscarInicio = numero > columna;
    NodoMatriz<T> *auxiliar = buscarInicio ? this->matriz->getCabecera() : this->matriz->getUltimaColumna();
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
                if (columna > this->matriz->columna()) {
                    this->matriz->getAgregador()->agregarNuevaColumnaDerecha(columna);
                    columna++;
                    return this->matriz->getUltimaColumna();
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
NodoMatriz<T> *BuscadorMatriz<T>::buscarFila(int fila, bool crear) {
    int numero = this->matriz->getFila() / 2;
    bool buscarInicio = numero > fila;
    NodoMatriz<T> auxiliar = buscarInicio ? this->matriz->getCabecera() : this->matriz->getUltimaFila();
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
                if (fila > this->matriz->fila) {
                    matriz->getAgregador()->agregarNuevaFilaAbajo(fila);
                    fila++;
                    return this->matriz->getUltimaFila();
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

#endif