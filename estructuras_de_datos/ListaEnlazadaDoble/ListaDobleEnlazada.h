//
// Created by rafael-cayax on 17/8/25.
//

#ifndef PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#define PRACTICA1EDD_LISTA_DOBLE_ENLAZADA_H
#include "NodoDoble.h"

template<typename T>
class ListaDobleEnlazada {
private:
    int tamaño;
    NodoDoble<T>* primero;
    NodoDoble<T>* ultimo;
    NodoDoble<T>* obtenerDesdePrimero(int posicion);
    NodoDoble<T>* obtenerDesdeUltimo(int posicion);
    NodoDoble<T>* obtenerNodo(int posicion);
public:
    ListaDobleEnlazada();
    ~ListaDobleEnlazada();
    bool estaVacia() const;
    void agregar(T* elemento);
    T* obtener(int posicion);
    T* eliminar(int posicion);
};

#include "ListaDobleEnlazada.cpp"
#endif //PRACTICA1EDD_LISTADOBLEENLAZADA_H