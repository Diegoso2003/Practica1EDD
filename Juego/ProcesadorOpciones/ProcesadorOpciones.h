//
// Created by rafael-cayax on 25/8/25.
//

#ifndef PRACTICA1EDD_PROCESADOROPCIONES_H
#define PRACTICA1EDD_PROCESADOROPCIONES_H

class TotitoChino;

class ProcesadorOpciones {
private:
    TotitoChino *totitoChino;
    bool PasarUltimo = true;
    bool seguirJugando = true;
    void procesarOpcion(int opcion);
public:
    ProcesadorOpciones(TotitoChino *totitoChino);
    void mostrarOpciones();
    void conectarLineas();
    bool getSeguirJugando() const {return seguirJugando;}
};


#endif //PRACTICA1EDD_PROCESADOROPCIONES_H