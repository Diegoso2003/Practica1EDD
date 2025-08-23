//
// Created by rafael-cayax on 22/8/25.
//

#ifndef PRACTICA1EDD_LINEA_H
#define PRACTICA1EDD_LINEA_H
#include <string>
#include <iostream>
#include "../Jugador/Jugador.h"
class Punto;

class Linea {
private:
    static constexpr std::string lineaVertical = "│";
    static constexpr std::string lineaHorizontal = "──";
    const std::string *linea;
    Punto *punto1;
    Punto *punto2;
    Jugador *dueño;
    //poder linea
public:
    Linea(bool vertical,Punto *punto1,Punto *punto2, Jugador *dueño);
    Punto *getPunto1(){return punto1;}
    Punto *getPunto2(){return punto2;}
    void imprimir();
};


#endif //PRACTICA1EDD_LINEA_H