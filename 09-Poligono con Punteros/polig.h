#include <fstream>
#include <cstdint>
#include <array>
#include <iostream>
#include <cassert>
#include <cmath>
#include <sstream>
#include <iomanip>



struct Punto {double x,y;};

struct Color {uint8_t R,G,B;};

struct Nodo;

struct Poligono {
    unsigned cant_puntos{0};
    Nodo* primerNodo;
    Color color;
};

void AddVerticeFront (Poligono&, Punto);
void AddVerticeEnd (Poligono&, Punto);

void RemoveVerticeEnd (Poligono&);
void RemoveVerticeFront (Poligono&);

void ImprimirPunto(Punto);
void ImprimirPoligono (Poligono&);
unsigned GetCantidadLados (const Poligono&);
double GetDistancia (Punto,Punto);
double CalculoAnguloInteriorPoligono (const Poligono&);

bool IsIgualPunto (Punto, Punto);
void SetVertice (Poligono&, Punto, unsigned); // Poligono, punto nuevo, posicion en array de poligono
Punto GetVertice (const Poligono&, unsigned); // devuelve el vertice en la posicion que se le pasa del punto, ejemplo punto pos 1 es at(0) en el poligono
double GetPerimetro (const Poligono&);

void LiberarEspacio (Poligono&);

bool ExtraerPunto(std::istream&,Punto&);
bool ExtraerPoligono(std::istream&, Poligono&);
bool ExtraerColor(std::istream&, Color&);
bool ExtraerPuntos(std::istream&, Poligono&);
void GuardarPoligono(std::ostream&,Poligono&);

void CopiarPoligonosConPerimetrosMayoresA(double,std::string,std::string);

void ImprimirColor (const Color&);
void CambiarColor (Poligono&, Color); 
Color const rojo {255,0,0}, azul{0,0,255}, verde{0,255,0}, cyan{0,255,255}, magenta{255,0,255}, amarillo{255,255,0}, negro{0,0,0}, blanco{255,255,255};
