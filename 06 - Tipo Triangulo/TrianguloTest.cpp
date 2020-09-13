#include "Triangulo.h"
#include <cassert>

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
