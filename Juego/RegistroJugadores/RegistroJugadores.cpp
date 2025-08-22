//
// Created by rafael-cayax on 19/8/25.
//

#include "RegistroJugadores.h"

RegistroJugadores::RegistroJugadores() {
    coloresDisponibles = new ListaDobleEnlazada<Color::Tipo>;
    inicializarColoresDisponibles();
}

RegistroJugadores::~RegistroJugadores() {
    delete coloresDisponibles;
}

Color::Tipo *RegistroJugadores::obtenerColorAleatorio(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, coloresDisponibles->getTamaño());
    int numeroAleatorio = dis(gen);
    return coloresDisponibles->eliminar(numeroAleatorio);
}

bool RegistroJugadores::caracterEstaApartado(char c) {
    Jugador** jugadores2 = jugadores->getElementos();
    for (int i = 0; i < jugadores->getTamaño(); i++) {
        if (jugadores2[i]->getInicial() == c) {
            return true;
        }
    }
    return false;
}

void RegistroJugadores::inicializarColoresDisponibles() {
    coloresDisponibles->agregar(new Color::Tipo(Color::Tipo::AMARILLO));
    coloresDisponibles->agregar(new Color::Tipo(Color::Tipo::AZUL));
    coloresDisponibles->agregar(new Color::Tipo(Color::Tipo::MAGENTA));
    coloresDisponibles->agregar(new Color::Tipo(Color::Tipo::ROJO));
    coloresDisponibles->agregar(new Color::Tipo(Color::Tipo::VERDE));
    coloresDisponibles->agregar(new Color::Tipo(Color::Tipo::NARANJA));
}

Jugador *RegistroJugadores::pedirDatosJugador() {
    std::string nombreJugador;
    std::string caracterJugador;
    bool hayError = false;
    do {
        if (hayError) {
            cout<< "Ingrese correctamente los datos solicitados" << endl;
        }
        cout<< "Ingrese nombre del jugador " << (jugadores->getTamaño()+1) << ":" <<endl ;
        cin >> nombreJugador;
        if (nombreJugador.empty()) {
            hayError = true;
            continue;
        }
        cout << "Ingrese la inicial para el jugador " << (jugadores->getTamaño()+1) << ":" <<endl;
        cin >> caracterJugador;
        if (caracterJugador.empty() || caracterJugador.size() > 1) {
            hayError = true;
            continue;
        }
        if (caracterEstaApartado(caracterJugador[0])) {
            hayError = true;
            cout << "¡Ya hay un jugador con esta letra!" << endl;
            continue;
        }
        Color::Tipo* colorJugador = obtenerColorAleatorio();
        return new Jugador(nombreJugador, caracterJugador[0], colorJugador);
    }while (hayError);
}


ColaConArreglo<Jugador> *RegistroJugadores::registrarJugadores() {
    pedirNumeroJugadores();
    for (int i = 0; i < jugadores->getCapacidad(); i++) {
        jugadores->agregarALaCola(pedirDatosJugador());
    }
    return jugadores;
}

void RegistroJugadores::pedirNumeroJugadores() {
    bool hayError = false;
    int numero = 0;
    std::string entrada;
    do {
        if (hayError) {
            std::cout << "Ingrese los datos solicitados correctamente" << std::endl;
        }
        std::cout << "Ingrese el numero de jugadores, max: 6, min: 2" << std::endl;
        std::getline(std::cin, entrada);

        try {
            numero = std::stoi(entrada);
            hayError = numero < minimoJugadores || numero > maximoJugadores;
        } catch (const std::exception& e) {
            hayError = true;
        }
    } while (hayError);
    jugadores = new ColaConArreglo<Jugador>(numero);
}