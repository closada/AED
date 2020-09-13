#include "Poligono.h"
#include <cmath>
#include <iostream>

void AddVertice (Poligono& pol, Punto p) { 
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
std::cout <<"(" << pol.Puntos.at(i).x << "," << pol.Puntos.at(i).y << ") , ";
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
return p.Puntos.at(posicion - 1);
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

bool IsIgualPunto (Punto p1, Punto p2){
return (p1.x == p2.x) and (p1.y == p2.y);
};