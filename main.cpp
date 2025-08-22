#include <iostream>

#include "estructuras_de_datos/Cola/ColaConArreglo.h"
#include "estructuras_de_datos/MatrizD/Matriz.h"
#include "Juego/TotitoChino.h"
#include "Juego/Jugador/Jugador.h"

int main() {
    std::cout << "\033[38;5;214m•──•──•  •" << "\n";
    std::cout << "│D │E │NT " << std::endl;
    std::cout << "•──•──•  •" << std::endl;
    std::cout << " NT│T │   " << std::endl;
    std::cout << "•  •  •  •" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "•  •  •  •" << std::endl;
    TotitoChino *juego = new TotitoChino();
    juego->iniciarJuego();
    delete juego;
    return 0;
}
