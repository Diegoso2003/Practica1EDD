//
// Created by rafael-cayax on 26/8/25.
//

#include "Auxiliar.h"

#include <algorithm>
#include <cctype>

int Auxiliar::coordenadaR(int numero) {
    return numero * 2 - 1;
}

int Auxiliar::numeroI(int numero) {
    return (numero + 1) / 2;
}

std::string Auxiliar::trim(std::string &entrada) {
    auto start = std::find_if_not(entrada.begin(), entrada.end(), ::isspace);
    auto end = std::find_if_not(entrada.rbegin(), entrada.rend(), ::isspace).base();

    if (start >= end) {
        return "";
    }

    return std::string(start, end);
}
