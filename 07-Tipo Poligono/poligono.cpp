/* Camila Victoria Losada
20200831
Tipo de dato Poligono */

#include <iostream>
#include <array>
#include <cstdint>
#include <cmath>
#include <cassert>

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

void DefPuntosPoligono (Poligono&,unsigned); 
void ImprimirPuntos (const Poligono&);
double CalculoAnguloInteriorPoligono (const Poligono&);

int main () {
Poligono p1 {
 3,
 {{ {2,2}, {0,0}, {-2,2}   }},
 {127,0,45},
};

Color negro{0,0,0};


CambiarColor(p1,negro);
assert (p1.color.R == 0);
assert (p1.color.G == 0);
assert (p1.color.B == 0);

AddVertice(p1, {13,-2.3});
assert (GetCantidadLados(p1) == 4);
assert (p1.Puntos.at(p1.cant_puntos - 1).x == 13);
assert (p1.Puntos.at(p1.cant_puntos - 1).y == -2.3);

RemoveVerticeEnd(p1);
assert (GetCantidadLados(p1) == 3);
assert (p1.Puntos.at(p1.cant_puntos - 1).x == -2);
assert (p1.Puntos.at(p1.cant_puntos - 1).y == 2);

assert (60 == CalculoAnguloInteriorPoligono(p1));

assert (9.7 > GetPerimetro(p1) and GetPerimetro(p1) > 9.6);

SetVertice(p1,{3,-5},2);
assert(p1.Puntos.at(1).x == 3);
assert(p1.Puntos.at(1).y == -5);

assert (GetVertice(p1,1).x == 2);
assert (GetVertice(p1,1).y == 2);
}

void AddVertice (Poligono& pol, Punto p) { // agregar como arg
pol.Puntos.at(pol.cant_puntos).x = p.x;
pol.Puntos.at(pol.cant_puntos).y = p.y;
pol.cant_puntos ++;
};

void RemoveVerticeEnd (Poligono& pol){
pol.cant_puntos --;
};

void DefPuntosPoligono (Poligono& pol, unsigned n) {
pol.cant_puntos = n;
for (unsigned i=0;i<pol.cant_puntos; i++)
{
std::cout << "Escriba el valor de x del punto " << i + 1 << ": ";
std::cin >> pol.Puntos.at(i).x;
std::cout << "Escriba el valor de y del punto " << i + 1 << ": ";
std::cin >> pol.Puntos.at(i).y;
};
};

void ImprimirPuntos (const Poligono& pol) {
for (unsigned i=0;i<pol.cant_puntos; i++)
{
std::cout << "Punto " << i + 1 <<": (" << pol.Puntos.at(i).x << "," << pol.Puntos.at(i).y << ") , ";
};
}


void SetVertice (Poligono& pol, Punto p, unsigned x){
pol.Puntos.at(x - 1).x = p.x;
pol.Puntos.at(x - 1).y = p.y;
};

void CambiarColor (Poligono& pol, Color c){
pol.color.R = c.R;
pol.color.G = c.G;
pol.color.B = c.B;
};

double CalculoAnguloInteriorPoligono (const Poligono& pol){

return 180 - (360 / pol.cant_puntos);
};

Punto GetVertice (const Poligono& p, unsigned posicion){
Punto ret;

ret.x = p.Puntos.at(posicion - 1).x;
ret.y = p.Puntos.at(posicion - 1).y;
return ret;
};

unsigned GetCantidadLados (const Poligono& p){
return p.cant_puntos;
};

double GetDistancia (Punto p1, Punto p2){
return sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2));
};


double GetPerimetro (const Poligono& p){
double per {0};
for (unsigned i=0;i<p.cant_puntos; i++)
{i < p.cant_puntos - 1 ? per = per + GetDistancia(p.Puntos.at(i),p.Puntos.at(i+1)) :
per = per + GetDistancia(p.Puntos.at(i),p.Puntos.at(0));
};
return per;
};
