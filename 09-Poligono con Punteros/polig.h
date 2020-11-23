#include <fstream>
#include <cstdint>
#include <iostream>
#include <cassert>
#include <cmath>



struct Punto {double x,y;};

struct Color {uint8_t R,G,B;};

struct Nodo;

struct Poligono {
    unsigned cant_puntos{0};
    Nodo* primerNodo{nullptr};
    Color color;
};

Color const rojo {255,0,0}, azul{0,0,255}, verde{0,255,0}, cyan{0,255,255}, magenta{255,0,255}, amarillo{255,255,0}, negro{0,0,0}, blanco{255,255,255};

void AddVerticeFront (Poligono&, Punto);
void AddVerticeEnd (Poligono&, Punto);

void RemoveVerticeEnd (Poligono&);
void RemoveVerticeFront (Poligono&);

void GuardarPunto(const Punto,std::ostream&);
void GuardarPoligono (const Poligono&,std::ostream&);
void GuardarPuntos (const Poligono&,std::ostream&);
void GuardarColor (const Color&,std::ostream&);

unsigned GetCantidadLados (const Poligono&);
double GetDistancia (Punto,Punto);
Punto GetVertice (const Poligono&, unsigned); // devuelve el vertice en la posicion que se le pasa del punto, ejemplo punto pos 1 es at(0) en el poligono
double GetPerimetro (const Poligono&);


bool IsIgualPuntos (Punto, Punto);
void SetVertice (Poligono&, Punto, unsigned); // Poligono, punto nuevo, posicion en array de poligono
void LiberarEspacio (Poligono&);

bool ExtraerPunto(std::istream&,Punto&);
bool ExtraerPoligono(std::istream&, Poligono&);
bool ExtraerColor(std::istream&, Color&);
bool ExtraerPuntos(std::istream&, Poligono&);



void CopiarPoligonosConPerimetrosMayoresA(double,std::string,std::string);


void CambiarColor (Poligono&, Color); 

