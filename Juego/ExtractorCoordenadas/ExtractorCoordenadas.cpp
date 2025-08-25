//
// Created by rafael-cayax on 25/8/25.
//

#include "ExtractorCoordenadas.h"

#include <string>
#include <regex>

bool ExtractorCoordenadas::extraerDatos(std::string &datos) {
    std::regex patron(R"(\s*(\d+)\s*,\s*(\d+)\s*->\s*(\d+)\s*,\s*(\d+)\s*)");

    if (std::regex_match(datos, patron)) {
        std::smatch coincidencias;
        std::regex_search(datos, coincidencias, patron);

        fila1 = std::stoi(coincidencias[1]);
        columna1 = std::stoi(coincidencias[2]);
        fila2 = std::stoi(coincidencias[3]);
        columna2 = std::stoi(coincidencias[4]);
        return true;
    }
    return false;
}
