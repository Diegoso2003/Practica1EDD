cmake_minimum_required(VERSION 4.0)
project(Practica1EDD)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practica1EDD main.cpp
        estructuras_de_datos/Cola/ColaConArreglo.cpp
        estructuras_de_datos/Cola/ColaConArreglo.h
        estructuras_de_datos/ListaEnlazadaDoble/NodoDoble.cpp
        estructuras_de_datos/ListaEnlazadaDoble/NodoDoble.h
        estructuras_de_datos/ListaEnlazadaDoble/ListaDobleEnlazada.cpp
        estructuras_de_datos/ListaEnlazadaDoble/ListaDobleEnlazada.h
        estructuras_de_datos/Pila/NodoSimple.cpp
        estructuras_de_datos/Pila/NodoSimple.h
        estructuras_de_datos/Pila/Pila.cpp
        estructuras_de_datos/Pila/Pila.h
        Juego/Jugador/Jugador.cpp
        Juego/Jugador/Jugador.h
        Juego/TotitoChino.cpp
        Juego/TotitoChino.h
        estructuras_de_datos/MatrizD/NodoMatriz/NodoMatriz.cpp
        estructuras_de_datos/MatrizD/NodoMatriz/NodoMatriz.h
        Juego/Color.h
        Juego/RegistroJugadores/RegistroJugadores.cpp
        Juego/RegistroJugadores/RegistroJugadores.h
        estructuras_de_datos/MatrizD/Matriz.cpp
        estructuras_de_datos/MatrizD/Matriz.h
        Iteradores/IteradorLED/IteradorLED.cpp
        Iteradores/IteradorLED/IteradorLED.h
        Iteradores/IteradorMatriz/IteradorMatriz.cpp
        Iteradores/IteradorMatriz/IteradorMatriz.h
        Juego/CreadorDeMatriz/CreadorDeMatriz.cpp
        Juego/CreadorDeMatriz/CreadorDeMatriz.h
        Juego/Punto/Punto.cpp
        Juego/Punto/Punto.h
        Juego/Linea/Linea.cpp
        Juego/Linea/Linea.h
)
