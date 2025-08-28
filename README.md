# Practica1EDD
EStructura:
Practica1EDD/
├── CMakeLists.txt
├── main.cpp
├── estructuras_de_datos/
├── Juego/
├── Iteradores/
└── (demás directorios)

Linux
crear el build usando:
    mkdir build
    cd build
configurar con
    cmake ..
compilar
    make
ejecutar
    ./Practica1EDD
    
Windows
crear el directorio
    mkdir build
    cd build
configurar con cmake
    # Para Visual Studio
    cmake .. -G "Visual Studio 17 2022"

    # Para MinGW
    cmake .. -G "MinGW Makefiles"
Compilar:
    # Para Visual Studio
    cmake --build . --config Release

    # Para MinGW
    make
ejecutar
    # Release
.\Release\Practica1EDD.exe

# Debug  
.\Debug\Practica1EDD.exe
