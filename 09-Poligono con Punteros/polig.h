#include <fstream>
#include <cstdint>
#include <array>
#include <iostream>
#include <cassert>
#include <cmath>
#include <sstream>
#include <iomanip>

double VALOR{100};

struct Punto {double x,y;};

struct Color {uint8_t R,G,B;};

struct Nodo {
    Punto p;
    Nodo* next{nullptr};
};


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
void CambiarColor (Poligono&, Color); 
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




Color GetColor (void);
Color MezclarDosColoresenPIguales (const Color&,const Color&);
Color MezclarDosColoresProporcion (const Color&, unsigned, const Color&, unsigned); // se asume los unsigned son las proporciones
Color GetComplementario (const Color&);
Color Sumar (const Color&,const Color&);
Color Restar (const Color&,const Color&);
std::string GetHtmlHex (const Color&);
std::string GetHtmlRgb (std::string);
void CrearSvgConTextoEscritoEnAltoContr(std::string, std::string, const Color&);
bool IsIgual (const Color&, const Color&);
void ImprimirColor (const Color&);

Color const rojo {255,0,0}, azul{0,0,255}, verde{0,255,0}, cyan{0,255,255}, magenta{255,0,255}, amarillo{255,255,0};
Color const negro = Restar(azul,azul);
Color const blanco = Sumar(Sumar(rojo,verde),azul);
