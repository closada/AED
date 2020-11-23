/* 20201002
Camila Victoria Losada */

#include <iostream>
#include <fstream>
#include <cstdint>
#include <array>
#include <cassert>
#include <cmath>


struct Punto {double x,y;};

struct Color {uint8_t R,G,B;};

struct Poligono {
    unsigned cant_puntos;
    std::array <Punto,30> Puntos; //como maximo, puede tratarse de un Triacontagono
    Color color;
};

bool ExtraerPoligono(std::istream&, Poligono&);
bool ExtraerColor(std::istream&, Color&);
bool ExtraerPuntos(std::istream&, Poligono&);
bool ExtraerPunto(std::istream&,Punto&);
void AgregarPunto(Poligono&, Punto, unsigned);


void GuardarPunto(const Punto,std::ostream&);
void GuardarPoligono (const Poligono&,std::ostream&);
void GuardarColor (const Color&,std::ostream&);
void GuardarPuntos( const Poligono&, std::ostream&);
double GetPerimetro (const Poligono&);
double GetDistancia (Punto,Punto);
void borrarDatosPoligono(Poligono&);


void CopiarPoligonosConPerimetrosMayoresA(double,std::string,std::string);