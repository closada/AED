/* 20201002
Camila Victoria Losada */

#include <iostream>
#include <fstream>
#include <cstdint>
#include <array>

struct Punto {double x,y;};

struct Color {uint8_t R,G,B;};

struct Poligono {
    unsigned cant_puntos;
    std::array <Punto,30> Puntos; //como maximo, puede tratarse de un Triacontagono
    Color color;
};

bool ExtraerPunto(std::istream&,Punto&);
bool ExtraerPoligono(std::istream&, Poligono&);
bool ExtraerColor(std::istream&, Color&);
bool ExtraerPuntos(std::istream&, Poligono&);
void MostrarPunto(std::ostream&, Punto);
void AgregarPunto(Poligono&, Punto, unsigned);
void MostrarPoligono(std::ostream&,Poligono&);
