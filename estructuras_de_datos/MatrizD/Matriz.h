//
// Created by rafael-cayax on 20/8/25.
//

#ifndef PRACTICA1EDD_MATRIZ_H
#define PRACTICA1EDD_MATRIZ_H
#include "../../Iteradores/IteradorMatriz/IteradorMatriz.h"
#include "../ListaEnlazadaDoble/ListaDobleEnlazada.h"
#include "AgregarMatriz/AgregadorMatriz.h"
#include "BuscadorMatriz/BuscadorMatriz.h"

template<typename T>
class Matriz {
private:
    NodoMatriz<T> *cabecera;
    NodoMatriz<T> *ultimaFila;
    NodoMatriz<T> *ultimaColumna;
    BuscadorMatriz<T> *buscador;
    AgregadorMatriz<T> *agregador;
    int fila;
    int columna;
    int tamaño = 0;
    void llenarMatriz(ListaDobleEnlazada<T> *lista);
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
    NodoMatriz<T> * getUltimaFila() const {return ultimaFila;}
    NodoMatriz<T> * getUltimaColumna() const {return ultimaColumna;}
    NodoMatriz<T> * getCabecera() const {return cabecera;}
    void setUltimaFila(NodoMatriz<T> *ultima_fila) {ultimaFila = ultima_fila;}
    void setUltimaColumna(NodoMatriz<T> *ultima_columna) {ultimaColumna = ultima_columna;}
    BuscadorMatriz<T> * getBuscador() const {return buscador;}
    AgregadorMatriz<T> * getAgregador() const {return agregador;}
};

#include "Matriz.cpp"
#endif //PRACTICA1EDD_MATRIZ_H