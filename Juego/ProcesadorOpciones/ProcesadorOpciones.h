//
// Created by rafael-cayax on 25/8/25.
//

#ifndef PRACTICA1EDD_PROCESADOROPCIONES_H
#define PRACTICA1EDD_PROCESADOROPCIONES_H
#include "../ExtractorCoordenadas/ExtractorCoordenadas.h"

class TotitoChino;

class ProcesadorOpciones {
private:
    TotitoChino *totitoChino;
    ExtractorCoordenadas *e;
    bool PasarUltimo = true;
    bool seguirJugando = true;
    void procesarOpcion(int opcion);
public:
    explicit ProcesadorOpciones(TotitoChino *totitoChino);
    ~ProcesadorOpciones();
    void mostrarOpciones();
    void conectarLineas();
    bool getSeguirJugando() const {return seguirJugando;}
};


#endif //PRACTICA1EDD_PROCESADOROPCIONES_H