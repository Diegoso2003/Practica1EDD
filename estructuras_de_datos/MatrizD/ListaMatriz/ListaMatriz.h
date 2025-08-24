//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_LISTAMATRIZ_H
#define PRACTICA1EDD_LISTAMATRIZ_H
#include "../NodoMatriz/NodoMatriz.h"

template <typename T>
class ListaMatriz {
private:
    NodoMatriz<T> *primero;
    NodoMatriz<T> *ultimo;
    ListaMatriz<T> *arriba;
    ListaMatriz<T> *abajo;
    ListaMatriz<T> *derecha;
    ListaMatriz<T> *izquierda;
    int tamaño;
    int *fila;
    int *columna;
    bool intentarConectarDesdeColumna(int fila, NodoMatriz<T> *nodo);
public:
    ListaMatriz(int *fila, int *columna);
    ~ListaMatriz();
    void agregarNodoDesdeFila(int columna, NodoMatriz<T> *nodo);
    bool agregarNodoDesdeColumna(int fila, NodoMatriz<T> *nodo);
    bool estaVacia() const{return tamaño == 0;}
    NodoMatriz<T> *getPrimero(){return primero;}
    NodoMatriz<T> *getUltimo(){return ultimo;}
    int *getFila(){return fila;}
    int *getColumna(){return columna;}
    int getTamaño(){return tamaño;}
    void actualizarUltimoYPrimero();
    void setArriba(ListaMatriz<T> *arriba) {this->arriba = arriba;}
    void setAbajo(ListaMatriz<T> *abajo) {this->abajo = abajo;}
    void setDerecha(ListaMatriz<T> *derecha) {this->derecha = derecha;}
    void setIzquierda(ListaMatriz<T> *izquierda) {this->izquierda = izquierda;}
    void incrementarTamaño() {tamaño++;}
    ListaMatriz<T> *getDerecha(){return derecha;}
    ListaMatriz<T> *getIzquierda(){return izquierda;}
    ListaMatriz<T> *getArriba(){return arriba;}
    ListaMatriz<T> *getAbajo(){return abajo;}
};

#include "ListaMatriz.cpp"
#endif //PRACTICA1EDD_LISTAMATRIZ_H