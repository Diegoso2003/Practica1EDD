//
// Created by rafael-cayax on 23/8/25.
//

#include "NuevasTierras.h"

#include <regex>

#include "../../Conversor/Auxiliar.h"
#include "../../Linea/Linea.h"

NuevasTierras::NuevasTierras() : PowerUp(8){

}

void NuevasTierras::realizarAccion(TotitoChino *juego) {
    this->totito = juego;
    pedirPunto();
    Jugador *jugador = juego->getJugadores()->eliminar(1);
    juego->getJugadores()->agregar(jugador);
}

void NuevasTierras::pedirPunto() {
    bool hayError = false;
    do {
        if (hayError) {
            std::cout << "Ingresar punto valido:" << std::endl;
        }
        std::cout << "Ingrese el punto de la siguiente forma" << std::endl;
        std::cout << "fila, columna" << std::endl;
        std::string datos;
        std::getline(std::cin, datos);
        hayError = !validarEntrada(datos);
    }while (hayError || !validarPunto());
    if (direccionesDisponibles > 1) {
        pedirDireccion();
    }
    calcularNuevasCoordenadas();
}

bool NuevasTierras::validarEntrada(std::string &datos) {
    std::regex patron(R"(\s*(\d+)\s*,\s*(\d+)\s*)");

    if (std::regex_match(datos, patron)) {
        std::smatch coincidencias;
        std::regex_search(datos, coincidencias, patron);
        fila = std::stoi(coincidencias[1]);
        columna = std::stoi(coincidencias[2]);
        return true;
    }
    return false;
}

bool NuevasTierras::validarPunto() {
    fila = Auxiliar::coordenadaR(fila);
    columna = Auxiliar::coordenadaR(columna);
    NodoMatriz<Casilla> *casilla = totito->getTableroJuego()->getNodo(fila, columna);
    fila = Auxiliar::numeroI(fila);
    columna = Auxiliar::numeroI(columna);
    verDireccion(casilla->getArriba(), arriba, true);
    verDireccion(casilla->getAbajo(), abajo, true);
    verDireccion(casilla->getDerecha(), derecha, false);
    verDireccion(casilla->getIzquierda(), izquierda, false);
    return direccionesDisponibles > 0;
}

void NuevasTierras::verDireccion(NodoMatriz<Casilla> *casilla, bool &direccion, bool vertical) {
    if (hayConeccion(casilla, vertical)) {
        direccionesDisponibles--;
        direccion = false;
    }
}


bool NuevasTierras::hayConeccion(NodoMatriz<Casilla> *casilla, bool vertical) {
    if (casilla == nullptr || casilla->esNodoCabecera()) {
        return false;
    }
    if (casilla->getElemento()->esLinea()) {
        return true;
    }
    int fila1 = Auxiliar::numeroI(*casilla->getFila());
    int columna1 = Auxiliar::numeroI(*casilla->getColumna());
    if (vertical) {
        return columna == columna1 && std::abs(fila - fila1) == 1;
    }
    return fila == fila1 && std::abs(columna - columna1) == 1;
}

void NuevasTierras::pedirDireccion() {
    bool hayError = false;
    do {
        if (hayError) {
            std::cout << "Ingresar una direccion valida:" << std::endl;
        }
        direccion = "";
        std::cout << "Ingresar la direccion de la linea" << std::endl;
        std::getline(std::cin, direccion);
        direccion = Auxiliar::trim(direccion);
        hayError = esDireccionInvalida();
    }while (hayError);
}

bool NuevasTierras::esDireccionInvalida() {
    return direccion.empty() || (direccion == "derecha" && !derecha) || (direccion == "izquierda" && !izquierda)
        || (direccion == "abajo" && !abajo) || (direccion == "arriba" && !arriba);
}

void NuevasTierras::calcularNuevasCoordenadas() {
    int nuevasCasillas[6] = {0, 0, 0, 0, 0, 0};
    abajo = abajo && (direccionesDisponibles == 1 || direccion == "abajo");
    arriba = arriba && (direccionesDisponibles == 1 || direccion == "arriba");
    derecha = derecha && (direccionesDisponibles == 1 || direccion == "derecha");
    izquierda = izquierda && (direccionesDisponibles == 1 || direccion == "izquierda");
    if (abajo || arriba) {
        nuevasCasillas[0] = arriba ? fila: fila + 1;
        nuevasCasillas[1] = columna == 1 ? columna + 1: columna;
        nuevasCasillas[2] = arriba ? fila: fila + 1;
        nuevasCasillas[3] = columna == 1 ? columna+2: columna+1;
        nuevasCasillas[4] = arriba ? fila : fila + 1;
        nuevasCasillas[5] = columna == 1 ? columna: columna - 1;
        if (columna == 1) {
            totito->getTableroJuego()->desplazarColumnas();
        }
        if (arriba) {
            totito->getTableroJuego()->desplazarFilas();
        }
    } else if (derecha || izquierda) {
        nuevasCasillas[0] = fila == 1 ? fila + 1: fila;
        nuevasCasillas[1] = izquierda ? columna : columna + 1;
        nuevasCasillas[2] = fila == 1 ? fila + 2 : fila + 1;
        nuevasCasillas[3] = izquierda ? columna : columna + 1;
        nuevasCasillas[4] = fila == 1 ? fila : fila - 1;
        nuevasCasillas[5] = izquierda ? columna : columna + 1;
        if (fila == 1) {
            totito->getTableroJuego()->desplazarFilas();
        }
        if (izquierda) {
            totito->getTableroJuego()->desplazarColumnas();
        }
    }
    colocarPuntos(nuevasCasillas);
}

void NuevasTierras::colocarPuntos(int coordenadas[6]) {
    for (int i = 0; i < 6; i+=2) {
        Casilla *casilla = new Casilla();
        int fila = Auxiliar::coordenadaR(coordenadas[i]);
        int columna = Auxiliar::coordenadaR(coordenadas[i+1]);
        NodoMatriz<Casilla> *nodo = totito->getTableroJuego()->getNodo(fila, columna);
        if (i == 0) {
            int filaLinea;
            int columnaLinea;
            if (arriba || abajo) {
                filaLinea = arriba ? fila + 1: fila - 1;
                columnaLinea = columna;
            } else {
                columnaLinea = derecha ? columna - 1: columna + 1;
                filaLinea = fila;
            }
            Linea *linea = new Linea((arriba || abajo), totito->getJugadores()->obtener(1));
            Casilla *casilla2 = new Casilla(linea);
            totito->getTableroJuego()->agregar(casilla2, filaLinea, columnaLinea);
        }
        if (nodo == nullptr) {
            totito->getTableroJuego()->agregar(casilla, fila, columna);
            nodo = totito->getTableroJuego()->getNodo(fila, columna);
            verificarConeccionesNuevoNodos(nodo);
        }
    }
}

void NuevasTierras::verificarConeccionesNuevoNodos(NodoMatriz<Casilla> *casilla) {
    direccionesDisponibles = 4;
    verDireccion(casilla->getArriba(), arriba, true);
    verDireccion(casilla->getAbajo(), abajo, true);
    verDireccion(casilla->getDerecha(), derecha, false);
    verDireccion(casilla->getIzquierda(), izquierda, false);
    if (direccionesDisponibles < 3) {
        int nuevosCuadros = 0;
        if (direccionesDisponibles == 2) {
            nuevosCuadros = 1;
        } else if (direccionesDisponibles == 1) {
            nuevosCuadros = 2;
        } else {
            nuevosCuadros = 4;
        }
        totito->incrementarCuadros(nuevosCuadros);
    }
}
