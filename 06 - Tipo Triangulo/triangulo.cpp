/* Camila Victoria Losada
20200831
Tipo de dato Triangulo */

#include <iostream>
#include <array>
#include <cmath>
#include <cassert>

struct Punto {
   std::array <double,2> Coord; 
};
struct Triangulo {
    std::array <Punto,3> Puntos;
    std::array<unsigned,3> Color; //color designado con formato RGB (--,--,--) numeros del 0 al 255
};

void CambiarColor (Triangulo&, unsigned, unsigned, unsigned);
void DefPuntos (Triangulo&, const Punto&,const Punto&,const Punto&);
void ImprimirPuntos (const Triangulo&);
double GetPerimetro (const Triangulo&);
void CambiarPuntoEnPos (Triangulo&,Punto, unsigned); // triangulo, nuevo punto, posicion punto a reemplazar en el array Puntos
double GetArea (const Triangulo&);
bool IsEscaleno (const Triangulo&);
bool IsEquilatero (const Triangulo&);
bool IsIsosceles (const Triangulo&);

int main () {
Triangulo t, t1 {
{  {{2,2}, {0,0}, {-2,2}}, },
{{0,0,255}}

};
CambiarColor(t1, 127,56,0);
assert (t1.Color.at(0) == 127);
assert (t1.Color.at(1) == 56);
assert (t1.Color.at(2) == 0);

DefPuntos(t,{{2,1}},{{-3,0}},{{0,0}});
assert(t.Puntos.at(0).Coord.at(0) == 2);
assert(t.Puntos.at(0).Coord.at(1) == 1);
assert(t.Puntos.at(1).Coord.at(0) == -3);
assert(t.Puntos.at(1).Coord.at(1) == 0);
assert(t.Puntos.at(2).Coord.at(0) == 0);
assert(t.Puntos.at(2).Coord.at(1) == 0);


//std::cout << GetArea(t1) << "\n";
//assert (4.0 == GetArea(t1));

DefPuntos(t1,{{1,3}},{{3,-1}},{{4,2}});
//std::cout << GetPerimetro(t1) << "\n";
// assert (10.7967 == GetPerimetro(t1));

assert (not IsEscaleno(t1));
assert (IsIsosceles(t1));


}

void CambiarColor (Triangulo& t, unsigned red, unsigned green, unsigned blue){
t.Color.at(0) = red;
t.Color.at(1) = green;
t.Color.at(2) = blue;
};

void DefPuntos (Triangulo& t,const Punto& p1,const Punto& p2,const Punto& p3){
t.Puntos.at(0).Coord.at(0) = p1.Coord.at(0);
t.Puntos.at(0).Coord.at(1) = p1.Coord.at(1);
t.Puntos.at(1).Coord.at(0) = p2.Coord.at(0);
t.Puntos.at(1).Coord.at(1) = p2.Coord.at(1);
t.Puntos.at(2).Coord.at(0) = p3.Coord.at(0);
t.Puntos.at(2).Coord.at(1) = p3.Coord.at(1);
};

void ImprimirPuntos (const Triangulo& t){
std::cout << "Punto 1: (" << t.Puntos.at(0).Coord.at(0) << "," << t.Puntos.at(0).Coord.at(1) << ")\n";
std::cout << "Punto 2: (" << t.Puntos.at(1).Coord.at(0) << "," << t.Puntos.at(1).Coord.at(1) << ")\n";
std::cout << "Punto 3: (" << t.Puntos.at(2).Coord.at(0) << "," << t.Puntos.at(2).Coord.at(1) << ")\n";
};

double GetPerimetro (const Triangulo& t){
double lado1,lado2,lado3;
lado1 = sqrt(((t.Puntos.at(1).Coord.at(0) - t.Puntos.at(0).Coord.at(0))*(t.Puntos.at(1).Coord.at(0) - t.Puntos.at(0).Coord.at(0))) + ((t.Puntos.at(1).Coord.at(1) - t.Puntos.at(0).Coord.at(1))*(t.Puntos.at(1).Coord.at(1) - t.Puntos.at(0).Coord.at(1))));
lado2 = sqrt(((t.Puntos.at(2).Coord.at(0) - t.Puntos.at(1).Coord.at(0))*(t.Puntos.at(2).Coord.at(0) - t.Puntos.at(1).Coord.at(0))) + ((t.Puntos.at(2).Coord.at(1) - t.Puntos.at(1).Coord.at(1))*(t.Puntos.at(2).Coord.at(1) - t.Puntos.at(1).Coord.at(1))));
lado3 = sqrt(((t.Puntos.at(0).Coord.at(0) - t.Puntos.at(2).Coord.at(0))*(t.Puntos.at(0).Coord.at(0) - t.Puntos.at(2).Coord.at(0))) + ((t.Puntos.at(0).Coord.at(1) - t.Puntos.at(2).Coord.at(1))*(t.Puntos.at(0).Coord.at(1) - t.Puntos.at(2).Coord.at(1))));

return lado1 + lado2 + lado3;
};

void CambiarPuntoEnPos (Triangulo& t,Punto p, unsigned x){
t.Puntos.at(x - 1).Coord.at(0) = p.Coord.at(0);
t.Puntos.at(x - 1).Coord.at(1) = p.Coord.at(1);
};

double GetArea (const Triangulo& t){
double ladoAB,ladoBC,ladoCA, S, h;
ladoAB = sqrt(((t.Puntos.at(1).Coord.at(0) - t.Puntos.at(0).Coord.at(0))*(t.Puntos.at(1).Coord.at(0) - t.Puntos.at(0).Coord.at(0))) + ((t.Puntos.at(1).Coord.at(1) - t.Puntos.at(0).Coord.at(1))*(t.Puntos.at(1).Coord.at(1) - t.Puntos.at(0).Coord.at(1))));
ladoBC = sqrt(((t.Puntos.at(2).Coord.at(0) - t.Puntos.at(1).Coord.at(0))*(t.Puntos.at(2).Coord.at(0) - t.Puntos.at(1).Coord.at(0))) + ((t.Puntos.at(2).Coord.at(1) - t.Puntos.at(1).Coord.at(1))*(t.Puntos.at(2).Coord.at(1) - t.Puntos.at(1).Coord.at(1))));
ladoCA = sqrt(((t.Puntos.at(0).Coord.at(0) - t.Puntos.at(2).Coord.at(0))*(t.Puntos.at(0).Coord.at(0) - t.Puntos.at(2).Coord.at(0))) + ((t.Puntos.at(0).Coord.at(1) - t.Puntos.at(2).Coord.at(1))*(t.Puntos.at(0).Coord.at(1) - t.Puntos.at(2).Coord.at(1))));
S = (ladoAB + ladoBC + ladoCA)/ 2;
h = 2/ladoAB*(sqrt(S*(S-ladoBC)*(S-ladoCA)*(S- ladoAB)));
return (ladoAB*h)/2;
};
bool IsEscaleno (const Triangulo& t){
double lado1,lado2,lado3;
lado1 = sqrt(((t.Puntos.at(1).Coord.at(0) - t.Puntos.at(0).Coord.at(0))*(t.Puntos.at(1).Coord.at(0) - t.Puntos.at(0).Coord.at(0))) + ((t.Puntos.at(1).Coord.at(1) - t.Puntos.at(0).Coord.at(1))*(t.Puntos.at(1).Coord.at(1) - t.Puntos.at(0).Coord.at(1))));
lado2 = sqrt(((t.Puntos.at(2).Coord.at(0) - t.Puntos.at(1).Coord.at(0))*(t.Puntos.at(2).Coord.at(0) - t.Puntos.at(1).Coord.at(0))) + ((t.Puntos.at(2).Coord.at(1) - t.Puntos.at(1).Coord.at(1))*(t.Puntos.at(2).Coord.at(1) - t.Puntos.at(1).Coord.at(1))));
lado3 = sqrt(((t.Puntos.at(0).Coord.at(0) - t.Puntos.at(2).Coord.at(0))*(t.Puntos.at(0).Coord.at(0) - t.Puntos.at(2).Coord.at(0))) + ((t.Puntos.at(0).Coord.at(1) - t.Puntos.at(2).Coord.at(1))*(t.Puntos.at(0).Coord.at(1) - t.Puntos.at(2).Coord.at(1))));
return lado1 != lado2 and lado1 != lado3 and lado2 != lado3? true : false;
};
bool IsEquilatero (const Triangulo& t){
double lado1,lado2,lado3;
lado1 = sqrt(((t.Puntos.at(1).Coord.at(0) - t.Puntos.at(0).Coord.at(0))*(t.Puntos.at(1).Coord.at(0) - t.Puntos.at(0).Coord.at(0))) + ((t.Puntos.at(1).Coord.at(1) - t.Puntos.at(0).Coord.at(1))*(t.Puntos.at(1).Coord.at(1) - t.Puntos.at(0).Coord.at(1))));
lado2 = sqrt(((t.Puntos.at(2).Coord.at(0) - t.Puntos.at(1).Coord.at(0))*(t.Puntos.at(2).Coord.at(0) - t.Puntos.at(1).Coord.at(0))) + ((t.Puntos.at(2).Coord.at(1) - t.Puntos.at(1).Coord.at(1))*(t.Puntos.at(2).Coord.at(1) - t.Puntos.at(1).Coord.at(1))));
lado3 = sqrt(((t.Puntos.at(0).Coord.at(0) - t.Puntos.at(2).Coord.at(0))*(t.Puntos.at(0).Coord.at(0) - t.Puntos.at(2).Coord.at(0))) + ((t.Puntos.at(0).Coord.at(1) - t.Puntos.at(2).Coord.at(1))*(t.Puntos.at(0).Coord.at(1) - t.Puntos.at(2).Coord.at(1))));
return lado1 == lado2 and lado1 == lado3 ? true : false;
};
bool IsIsosceles (const Triangulo& t){
double lado1,lado2,lado3;
lado1 = sqrt(((t.Puntos.at(1).Coord.at(0) - t.Puntos.at(0).Coord.at(0))*(t.Puntos.at(1).Coord.at(0) - t.Puntos.at(0).Coord.at(0))) + ((t.Puntos.at(1).Coord.at(1) - t.Puntos.at(0).Coord.at(1))*(t.Puntos.at(1).Coord.at(1) - t.Puntos.at(0).Coord.at(1))));
lado2 = sqrt(((t.Puntos.at(2).Coord.at(0) - t.Puntos.at(1).Coord.at(0))*(t.Puntos.at(2).Coord.at(0) - t.Puntos.at(1).Coord.at(0))) + ((t.Puntos.at(2).Coord.at(1) - t.Puntos.at(1).Coord.at(1))*(t.Puntos.at(2).Coord.at(1) - t.Puntos.at(1).Coord.at(1))));
lado3 = sqrt(((t.Puntos.at(0).Coord.at(0) - t.Puntos.at(2).Coord.at(0))*(t.Puntos.at(0).Coord.at(0) - t.Puntos.at(2).Coord.at(0))) + ((t.Puntos.at(0).Coord.at(1) - t.Puntos.at(2).Coord.at(1))*(t.Puntos.at(0).Coord.at(1) - t.Puntos.at(2).Coord.at(1))));
return lado1 == lado2 or lado1 == lado3 or lado2 == lado3 ? true : false;
};