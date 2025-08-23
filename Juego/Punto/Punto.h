//
// Created by rafael-cayax on 22/8/25.
//

#ifndef PRACTICA1EDD_PUNTO_H
#define PRACTICA1EDD_PUNTO_H
#include <string>

class Linea;

class Punto {
private:
    static constexpr std::string punto = "•";
    Linea *lineaArriba;
    Linea *lineaAbajo;
    Linea *lineaIzquierda;
    Linea *lineaDerecha;
public:
    Punto();
    void setLineaArriba(Linea *lineaArriba) { this->lineaArriba = lineaArriba;}
    void setLineaAbajo(Linea *lineaAbajo) { this->lineaAbajo = lineaAbajo;}
    void setLineaDerecha(Linea *lineaDerecha) { this->lineaDerecha = lineaDerecha;}
    void setLineaIzquierda(Linea *lineaIzquierda) { this->lineaIzquierda = lineaIzquierda;}
    void imprimir();

};


#endif //PRACTICA1EDD_PUNTO_H