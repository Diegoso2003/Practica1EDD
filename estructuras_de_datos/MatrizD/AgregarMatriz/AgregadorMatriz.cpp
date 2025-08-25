//
// Created by rafael-cayax on 24/8/25.
//
#ifndef PRACTICA1EDD_AGREGADOR_MATRIZ_CPP
#define PRACTICA1EDD_AGREGADOR_MATRIZ_CPP

#include "AgregadorMatriz.h"
#include "../NodoMatriz/NodoMatriz.h"

template<typename T>
void AgregadorMatriz<T>::agregarNuevaFilaAbajo(int fila) {
    auto *nodo = new NodoMatriz<T>(nullptr,new int(fila),new int(0));
    matriz->getUltimaFila()->setAbajo(nodo);
    nodo->setArriba(matriz->getUltimaFila());
    matriz->setUltimaFila(nodo);
}

template<typename T>
void AgregadorMatriz<T>::agregarNuevaColumnaDerecha(int columna) {
    auto *nodo = new NodoMatriz<T>(nullptr,  new int(0), new int(columna));
    matriz->getUltimaColumna()->setDerecha(nodo);
    nodo->setIzquierda(matriz->getUltimaColumna());
    matriz->setUltimaColumna(nodo);
}

template<typename T>
bool AgregadorMatriz<T>::agregarDesdeColumna(int fila, NodoMatriz<T> *nodo, NodoMatriz<T> *nodoColumna) {
    while (nodoColumna->getAbajo() != nullptr && *nodoColumna->getFila() < fila) {
        nodoColumna = nodoColumna->getAbajo();
    }
    if (*nodoColumna->getFila() > fila) {
        if (nodoColumna->getArriba() != nullptr) {
            nodoColumna->getArriba()->setAbajo(nodo);
            nodo->setArriba(nodoColumna->getArriba());
        }
        nodoColumna->setArriba(nodo);
        nodo->setAbajo(nodoColumna);
    } else {
        nodoColumna->setAbajo(nodo);
        nodo->setArriba(nodoColumna);
    }
    return intentarAgregarDesdeColumna(fila, nodo);
}

template<typename T>
void AgregadorMatriz<T>::agregarDesdeFila(int columna, NodoMatriz<T> *nodo, NodoMatriz<T> *nodoFila) {
    while (nodoFila->getDerecha() != nullptr && *nodoFila->getColumna() < columna) {
        nodoFila = nodoFila->getDerecha();
    }
    if (*nodoFila->getColumna() > columna) {
        if (nodoFila->getIzquierda() != nullptr) {
            nodoFila->getIzquierda()->setDerecha(nodo);
            nodo->setIzquierda(nodoFila->getIzquierda());
        }
        nodoFila->setIzquierda(nodo);
        nodo->setDerecha(nodoFila);
    } else {
        nodoFila->setDerecha(nodo);
        nodo->setIzquierda(nodoFila);
    }
}

template<typename T>
bool AgregadorMatriz<T>::intentarConectarDerecha(int fila, NodoMatriz<T> *nodo, NodoMatriz<T> *nodoActual, bool arriba) {
    nodoActual = nodoActual->getDerecha();
    if (nodoActual != nullptr) {
        nodoActual = arriba ? nodoActual->getArriba() : nodoActual->getAbajo();
    }
    if (nodoActual == nullptr) { return false;}
    if (*nodoActual->getFila() == fila) {
        nodo->setFila(nodoActual->getFila());
        while (*nodoActual->getColumna() > *nodo->getColumna()) {
            nodoActual = nodoActual->getIzquierda();
        }
        nodoActual->getDerecha()->setIzquierda(nodo);
        nodo->setDerecha(nodoActual->getDerecha());
        nodoActual->setDerecha(nodo);
        nodo->setIzquierda(nodoActual);
        return true;
    }
    return false;
}

template<typename T>
bool AgregadorMatriz<T>::intentarConectarIzquierda(int fila, NodoMatriz<T> *nodo, NodoMatriz<T> *nodoActual, bool arriba) {
    nodoActual = nodoActual->getIzquierda();
    if (nodoActual != nullptr) {
        nodoActual = arriba ? nodoActual->getArriba() : nodoActual->getAbajo();
    }
    if (nodoActual == nullptr) { return false;}
    if (*nodoActual->getFila() == fila) {
        nodo->setFila(nodoActual->getFila());
        while (nodoActual->getDerecha() != nullptr && *nodoActual->getColumna() < *nodo->getColumna()) {
            nodoActual = nodoActual->getDerecha();
        }
        if (*nodoActual->getColumna() > *nodo->getColumna()) {
            nodoActual->getIzquierda()->setDerecha(nodo);
            nodo->setIzquierda(nodoActual->getIzquierda());
            nodoActual->setIzquierda(nodo);
            nodo->setDerecha(nodoActual);
        } else {
            nodoActual->setDerecha(nodo);
            nodo->setIzquierda(nodoActual);
        }
        return true;
    }
    return false;
}


template<typename T>
bool AgregadorMatriz<T>::intentarAgregarDesdeColumna(int fila, NodoMatriz<T> *nodo) {
    NodoMatriz<T> *aux = nodo;
    bool agregado = false;
    if (aux->getArriba() != nullptr) {
        agregado = intentarConectarDerecha(fila, nodo, aux->getArriba(),false) ||
            intentarConectarIzquierda(fila, nodo, aux->getArriba(), false);
    }
    if (!agregado && aux->getAbajo() != nullptr) {
        agregado = intentarConectarDerecha(fila, nodo, aux->getAbajo(), true) ||
            intentarConectarIzquierda(fila, nodo, aux->getAbajo(), true);
    }
    return agregado;
}

#endif