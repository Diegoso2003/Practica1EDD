//
// Created by rafael-cayax on 26/8/25.
//

#ifndef PRACTICA1EDD_VERIFICADORCUADROS_H
#define PRACTICA1EDD_VERIFICADORCUADROS_H
#include "../../estructuras_de_datos/MatrizD/NodoMatriz/NodoMatriz.h"

class Casilla;
class VerificadorCuadros {
private:
    bool arriba = true;
    bool derecha = true;
    bool esNodoAceptado(NodoMatriz<Casilla> *nodo);
    bool verificarConeccionHorizonal(NodoMatriz<Casilla> *punto, NodoMatriz<Casilla> *punto2, bool arriba);
    bool verificarConeccionVertical(NodoMatriz<Casilla> *punto, NodoMatriz<Casilla> *punto2, bool derecha);
public:
    bool verificarConeccion(NodoMatriz<Casilla> *punto, NodoMatriz<Casilla> *punto2, bool vertical);
    bool esDerecha() {return derecha;}
    bool esArriba() {return arriba;}
};


#endif //PRACTICA1EDD_VERIFICADORCUADROS_H