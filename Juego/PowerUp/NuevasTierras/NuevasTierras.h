//
// Created by rafael-cayax on 23/8/25.
//

#ifndef PRACTICA1EDD_NUEVASTIERRAS_H
#define PRACTICA1EDD_NUEVASTIERRAS_H
#include "../PowerUp.h"


class NuevasTierras : public PowerUp{
private:
    TotitoChino *totito = nullptr;
    bool arriba = true;
    bool derecha = true;
    bool izquierda = true;
    bool abajo = true;
    int direccionesDisponibles = 4;
    int fila = -1;
    int columna = -1;
    std::string direccion = "";
    void pedirPunto();
    void pedirDireccion();
    bool validarEntrada(std::string &datos);
    bool validarPunto();
    bool esDireccionInvalida();
    bool hayConeccion(NodoMatriz<Casilla> *casilla, bool vertical);
    void verDireccion(NodoMatriz<Casilla> *casilla, bool &direccion, bool vertical);
    void calcularNuevasCoordenadas();
    void colocarPuntos(int coordenadas[6]);
    void verificarConeccionesNuevoNodos(NodoMatriz<Casilla> *casilla);
public:
    NuevasTierras();
    void realizarAccion(TotitoChino *juego) override;
};


#endif //PRACTICA1EDD_NUEVASTIERRAS_H