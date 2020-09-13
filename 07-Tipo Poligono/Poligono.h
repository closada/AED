/* Camila Victoria Losada
20200831
Tipo de dato Poligono */

#include <iostream>
#include <array>
#include <cstdint>



struct Punto {
   double x, y;
};

struct Color {uint8_t R,G,B;};

struct Poligono {
    unsigned cant_puntos;
    std::array <Punto,30> Puntos; //como maximo, puede tratarse de un Triacontagono
    Color color;
};

double GetDistancia (Punto,Punto);
void AddVertice (Poligono&, Punto);
void SetVertice (Poligono&, Punto, unsigned); // Poligono, punto nuevo, posicion en array de poligono
void RemoveVerticeEnd (Poligono&);
Punto GetVertice (const Poligono&, unsigned); // devuelve el vertice en la posicion que se le pasa del punto, ejemplo punto pos 1 es at(0) en el poligono
unsigned GetCantidadLados (const Poligono&);
double GetPerimetro (const Poligono&);
void CambiarColor (Poligono&, Color); 
bool IsIgualPunto (Punto, Punto);
void DefPuntosPoligono (Poligono&,unsigned); 
void ImprimirPuntos (const Poligono&);
double CalculoAnguloInteriorPoligono (const Poligono&);