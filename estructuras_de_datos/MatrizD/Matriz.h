//
// Created by rafael-cayax on 20/8/25.
//

#ifndef PRACTICA1EDD_MATRIZ_H
#define PRACTICA1EDD_MATRIZ_H
#include "../../Iteradores/IteradorMatriz/IteradorMatriz.h"
#include "../ListaEnlazadaDoble/ListaDobleEnlazada.h"
#include "NodoMatriz/NodoMatriz.h"
#include <iostream>

template<typename T>
class Matriz {
private:
    NodoMatriz<T> *cabecera;
    NodoMatriz<T> *ultimaFila;
    NodoMatriz<T> *ultimaColumna;
    int fila;
    int columna;
    int tamaño = 0;
    void llenarMatriz(ListaDobleEnlazada<T> *lista);
    void agregarNuevaFilaAbajo(int fila);
    void agregarNuevaColumnaDerecha(int columna);
    NodoMatriz<T> *buscarFila(int fila, bool crear);
    NodoMatriz<T> *buscarColumna(int columna, bool crear);
public:
    Matriz();
    Matriz(int filas, int columnas, ListaDobleEnlazada<T> *lista);
    ~Matriz();
    bool estaVacia() const{return tamaño == 0;}
    T* getElemento(int fila, int columna);
    IteradorMatriz<T> *getIteradorMatriz(){return new IteradorMatriz<T>(cabecera);}
    void agregar(T *elemento, int fila, int columna);
    int getFila() const{return fila;}
    int getColumna() const{return columna;}
};

#include "Matriz.cpp"
#endif //PRACTICA1EDD_MATRIZ_H