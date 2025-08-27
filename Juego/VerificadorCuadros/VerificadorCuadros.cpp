//
// Created by rafael-cayax on 26/8/25.
//

#include "VerificadorCuadros.h"

#include "../Casilla/Casilla.h"

bool VerificadorCuadros::verificarConeccion(NodoMatriz<Casilla> *punto, NodoMatriz<Casilla> *punto2, bool vertical) {
    if (vertical) {
        return verificarConeccionVertical(punto, punto2, true);
    }
    return verificarConeccionHorizonal(punto, punto2, true);
}

bool VerificadorCuadros::verificarConeccionHorizonal(NodoMatriz<Casilla> *punto, NodoMatriz<Casilla> *punto2, bool arriba) {
    NodoMatriz<Casilla> *aux1 = arriba ? punto->getArriba() : punto->getAbajo();
    NodoMatriz<Casilla> *aux2 = arriba ? punto2->getArriba() : punto2->getAbajo();
    if (aux1 == nullptr || aux2 == nullptr || !esNodoAceptado(aux1) || !esNodoAceptado(aux2)) {
        this->arriba = false;
        return arriba ? verificarConeccionHorizonal(punto, punto2, false) : false;
    }
    aux1 = arriba ? aux1->getArriba() : aux1->getAbajo();
    if (*aux1->getColumna() < *aux2->getColumna()) {
        aux1 = aux1->getDerecha();
    } else {
        aux1 = aux1->getIzquierda();
    }
    return aux1->getElemento()->esLinea();
}

bool VerificadorCuadros::verificarConeccionVertical(NodoMatriz<Casilla> *punto, NodoMatriz<Casilla> *punto2, bool derecha) {
    NodoMatriz<Casilla> *aux1 = derecha ? punto->getDerecha() : punto->getIzquierda();
    NodoMatriz<Casilla> *aux2 = derecha ? punto2->getDerecha() : punto2->getIzquierda();
    if (aux1 == nullptr || aux2 == nullptr || !esNodoAceptado(aux1) || !esNodoAceptado(aux2)) {
        this->derecha = false;
        return derecha ? verificarConeccionVertical(punto, punto2, false) : false;
    }
    aux1 = derecha ? aux1->getDerecha() : aux1->getIzquierda();
    if (*aux1->getFila() < *aux2->getFila()) {
        aux1 = aux1->getAbajo();
    } else {
        aux1 = aux1->getArriba();
    }
    return aux1->getElemento()->esLinea();
}

bool VerificadorCuadros::esNodoAceptado(NodoMatriz<Casilla> *nodo) {
    if (nodo->esNodoCabecera()) {
        return false;
    }
    Casilla *casilla = nodo->getElemento();
    return casilla->esLinea();
}
