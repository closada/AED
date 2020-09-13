#include "Triangulo.h"
#include <iostream>
#include <cmath>


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