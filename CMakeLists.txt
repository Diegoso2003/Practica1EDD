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
)
