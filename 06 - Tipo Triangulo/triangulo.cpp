/* Camila Victoria Losada
20200831
Tipo de dato Triangulo */

#include <iostream>
#include <array>
#include <cmath>
#include <cassert>

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

int main () {
Triangulo t, t1 {
 {2,2}, {0,0}, {-2,2},
{0,0,255}};

Color blanco {255,255,255};

Punto prueba;

CambiarColor(t1,blanco);
assert (t1.color.R == 255);
assert (t1.color.G == 255);
assert (t1.color.B == 255);

DefPuntos(t,{2,1},{-3,0},{0,0});
assert(t.a.x == 2);
assert(t.a.y == 1);
assert(t.b.x == -3);
assert(t.b.y == 0);
assert(t.c.x == 0);
assert(t.c.y == 0);


//std::cout << GetArea(t1) << "\n";
assert (3.9 <= GetArea(t1) and GetArea(t1) <= 4.1);

DefPuntos(t1,{1,3},{3,-1},{4,2});
//std::cout << GetPerimetro(t1) << "\n";
assert (10.7 <= GetPerimetro(t1) and GetPerimetro(t1) <= 10.8);

assert (not IsEscaleno(t1));
assert (IsIsosceles(t1));
assert (IsEscaleno(t));

assert (TipoTriangulo::Isosceles == GetTipo(t1));
assert (TipoTriangulo::Escaleno == GetTipo(t));


prueba = GetCentro(t1);
assert (prueba.x == 8);
assert (prueba.y == 4);

prueba = GetCentro(t);
assert(prueba.x == -1);
assert(prueba.y == 1);


}

double GetDistancia (Punto p1, Punto p2){
return sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2));
};

void CambiarColor (Triangulo& t, const Color& c){
t.color.R = c.R;
t.color.G = c.G;
t.color.B = c.B;
};

void DefPuntos (Triangulo& t,const Punto& p1,const Punto& p2,const Punto& p3){
t.a.x = p1.x;
t.a.y = p1.y;
t.b.x = p2.x;
t.b.y = p2.y;
t.c.x = p3.x;
t.c.y = p3.y;
};

std::string ImprimirPuntos (const Triangulo& t){
return "Punto 1: (" + std::to_string(t.a.x) + "," + std::to_string(t.a.y) + ")\n" + "Punto 2: (" + std::to_string(t.b.x) + "," + std::to_string(t.b.y) + ")\n" + "Punto 3: (" + std::to_string(t.c.x) + "," + std::to_string(t.c.y) + ")\n";
};

double GetPerimetro (const Triangulo& t){
return GetDistancia(t.a,t.b) + GetDistancia (t.b,t.c) + GetDistancia (t.c,t.a);
};

void CambiarPuntoEnPos (Triangulo& t,Punto p, unsigned x){
if (x == 1) {
t.a.x = p.x;
t.a.y = p.y;    
};
if (x == 2) {
t.b.x = p.x;
t.b.y = p.y;    
};
if (x == 3) {
t.c.x = p.x;
t.c.y = p.y;    
};
};

double GetArea (const Triangulo& t){
double S, h;
S = (GetDistancia(t.a,t.b) + GetDistancia(t.b,t.c) + GetDistancia(t.c,t.a))/ 2;
h = 2/GetDistancia(t.a,t.b)*(sqrt(S*(S-GetDistancia(t.b,t.c))*(S-GetDistancia(t.c,t.a))*(S- GetDistancia(t.a,t.b))));
return (GetDistancia(t.a,t.b)*h)/2;
};
bool IsEscaleno (const Triangulo& t){
return (GetDistancia(t.a,t.b) != GetDistancia(t.b,t.c)) and (GetDistancia(t.a,t.b) != GetDistancia(t.c,t.a)) and (GetDistancia(t.b,t.c) != GetDistancia(t.c,t.a));
};
bool IsEquilatero (const Triangulo& t){
return (GetDistancia(t.a,t.b) == GetDistancia(t.b,t.c)) and (GetDistancia(t.a,t.b) == GetDistancia(t.c,t.a));
};
bool IsIsosceles (const Triangulo& t){
return (GetDistancia(t.a,t.b) == GetDistancia(t.b,t.c)) or (GetDistancia(t.a,t.b) == GetDistancia(t.c,t.a)) or (GetDistancia(t.b,t.c) == GetDistancia(t.c,t.a));
};

TipoTriangulo GetTipo (const Triangulo& t){
return IsEscaleno(t) ? TipoTriangulo::Escaleno :
IsEquilatero(t) ? TipoTriangulo::Equilatero :
IsIsosceles(t) ? TipoTriangulo::Isosceles :
TipoTriangulo::otro;
}

Punto GetCentro (const Triangulo& t){

return {(t.a.x + t.b.x + t.c.x),(t.a.y + t.b.y + t.c.y)};
};
