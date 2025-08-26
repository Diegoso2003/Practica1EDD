//
// Created by rafael-cayax on 24/8/25.
//
#ifndef PRACTICA1EDD_BUSCADORMATRIZ_CPP
#define PRACTICA1EDD_BUSCADORMATRIZ_CPP
#include "BuscadorMatriz.h"

template<typename T>
NodoMatriz<T> *BuscadorMatriz<T>::buscarColumna(int columna, bool crear) {
    if (columna > this->matriz->getColumna()) {
        if (crear) {
            this->matriz->getAgregador()->agregarNuevaColumnaDerecha(columna);
            this->matriz->setColumna(columna);
            return this->matriz->getUltimaColumna();
        }
        return nullptr;
    }
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
                auxiliar->getIzquierda()->setDerecha(nodoNuevo);
                nodoNuevo->setIzquierda(auxiliar->getIzquierda());
                nodoNuevo->setDerecha(auxiliar);
                auxiliar->setIzquierda(nodoNuevo);
                return nodoNuevo;
            }
            return nullptr;
        }
        if (!buscarInicio && columnaActual < columna) {
            if (crear) {
                NodoMatriz<T> *nuevoNodo = new NodoMatriz<T>(nullptr, new int(0), new int(columna));
                auxiliar->getDerecha()->setIzquierda(nuevoNodo);
                nuevoNodo->setDerecha(auxiliar->getDerecha());
                nuevoNodo->setIzquierda(auxiliar);
                auxiliar->setDerecha(nuevoNodo);
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
    if (fila > this->matriz->getFila()) {
        if (!crear) {
            matriz->getAgregador()->agregarNuevaFilaAbajo(fila);
            this->matriz->setFila(fila);
            return this->matriz->getUltimaFila();
        }
        return nullptr;
    }
    int numero = this->matriz->getFila() / 2;
    bool buscarInicio = numero > fila;
    NodoMatriz<T> *auxiliar = buscarInicio ? this->matriz->getCabecera() : this->matriz->getUltimaFila();
    while (auxiliar != nullptr) {
        int filaActual = *auxiliar->getFila();
        if (filaActual == fila) {
            return auxiliar;
        }
        if (buscarInicio && filaActual > fila) {
            if (crear) {
                NodoMatriz<T> *nodoNuevo = new NodoMatriz<T>(nullptr, new int(fila), new int(0));
                auxiliar->getArriba()->setAbajo(nodoNuevo);
                nodoNuevo->setArriba(auxiliar->getArriba());
                nodoNuevo->setAbajo(auxiliar);
                auxiliar->setArriba(nodoNuevo);
                return nodoNuevo;
            }
            return nullptr;
        }
        if (!buscarInicio && filaActual < fila) {
            if (crear) {
                NodoMatriz<T> *nodoNuevo = new NodoMatriz<T>(nullptr, new int(fila), new int(0));
                auxiliar->getAbajo()->setArriba(nodoNuevo);
                nodoNuevo->setAbajo(auxiliar->getAbajo());
                nodoNuevo->setArriba(auxiliar);
                auxiliar->setAbajo(nodoNuevo);
                return nodoNuevo;
            }
            return nullptr;
        }
        auxiliar = buscarInicio ? auxiliar->getAbajo() : auxiliar->getArriba();
    }
    return nullptr;
}

#endif