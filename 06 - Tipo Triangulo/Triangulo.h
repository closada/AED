/* Camila Victoria Losada
20200831
Tipo de dato Triangulo */

#include <iostream>
#include <cstdint>

struct Punto {
   double x, y;
};

struct Color {uint8_t R,G,B;};

struct Triangulo {
    Punto a,b,c;
    Color color; //color designado con formato RGB (--,--,--) numeros del 0 al 255

};

enum struct TipoTriangulo {Escaleno, Isosceles, Equilatero, otro};

double GetDistancia (Punto,Punto);
void CambiarColor (Triangulo&, const Color&);
void DefPuntos (Triangulo&, const Punto&,const Punto&,const Punto&);
std::string ImprimirPuntos (const Triangulo&);
double GetPerimetro (const Triangulo&);
void CambiarPuntoEnPos (Triangulo&,Punto, unsigned); // triangulo, nuevo punto, posicion punto a reemplazar en el array Puntos
double GetArea (const Triangulo&);
bool IsEscaleno (const Triangulo&);
bool IsEquilatero (const Triangulo&);
bool IsIsosceles (const Triangulo&);
TipoTriangulo GetTipo (const Triangulo&);
Punto GetCentro (const Triangulo&);
