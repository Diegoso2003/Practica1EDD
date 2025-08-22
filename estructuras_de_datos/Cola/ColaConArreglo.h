//
// Created by rafael-cayax on 13/8/25.
//

#ifndef PRACTICA1EDD_PILACONARREGLO_H
#define PRACTICA1EDD_PILACONARREGLO_H

template <typename T>
class ColaConArreglo {
private:
    T** elementos;
    int inicio;
    int final;
    int capacidad;
    int tamaño;
    void imprimir(int principio, int final);
public:
    ColaConArreglo(int capacidad);
    ~ColaConArreglo();
    void agregarALaCola(T *elemento);
    T* SacarAlPrimero();
    void mostrarCola();
    int getCapacidad() const;
    int getTamaño() const;
    T** getElementos() const;
};

#include "ColaConArreglo.cpp"
#endif //PRACTICA1EDD_PILACONARREGLO_H