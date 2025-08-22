//
// Created by rafael-cayax on 19/8/25.
//

#ifndef PRACTICA1EDD_COLORES_H
#define PRACTICA1EDD_COLORES_H
#include <string>


class Color {
public:
    enum class Tipo { ROJO, VERDE, AZUL, AMARILLO, MAGENTA, CYAN, BLANCO, NEGRO, NARANJA, RESET };

    static std::string codigo(Tipo c) {
        switch(c){
            case Tipo::ROJO: return "\033[31m";
            case Tipo::VERDE: return "\033[32m";
            case Tipo::AZUL: return "\033[34m";
            case Tipo::AMARILLO: return "\033[33m";
            case Tipo::MAGENTA: return "\033[35m";
            case Tipo::CYAN: return "\033[36m";
            case Tipo::BLANCO: return "\033[37m";
            case Tipo::NEGRO: return "\033[30m";
            case Tipo::NARANJA: return "\033[38;5;214m";
            case Tipo::RESET: return "\033[0m";
            default: return "\033[0m";
        }
    }

    static std::string name(Tipo c) {
        switch(c){
            case Tipo::ROJO: return "Rojo";
            case Tipo::VERDE: return "Verde";
            case Tipo::AZUL: return "Azul";
            case Tipo::AMARILLO: return "Amarillo";
            case Tipo::MAGENTA: return "Morado";
            case Tipo::CYAN: return "Cyan";
            case Tipo::BLANCO: return "Blanco";
            case Tipo::NEGRO: return "Negro";
            case Tipo::RESET: return "Reset";
            case Tipo::NARANJA: return "Naranja";
            default: return "desconocido";
        }
    }
private:
    Color(){};
};

#endif //PRACTICA1EDD_COLORES_H