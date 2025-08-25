//
// Created by rafael-cayax on 25/8/25.
//

#ifndef PRACTICA1EDD_EXTRACTORCOORDENADAS_H
#define PRACTICA1EDD_EXTRACTORCOORDENADAS_H
#include <string>

class ExtractorCoordenadas {
private:
    int fila1 = -1;
    int columna1 = -1;
    int fila2 = -1;
    int columna2 = -1;
public:
    int getFila1() const {return fila1;}
    int getColumna1() const {return columna1;}
    int getFila2() const {return fila2;}
    int getColumna2() const {return columna2;}
    bool extraerDatos(std::string &datos);
};


#endif //PRACTICA1EDD_EXTRACTORCOORDENADAS_H