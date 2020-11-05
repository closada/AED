#include <fstream>
#include <cstdint>
#include <array>
#include <iostream>
#include <cassert>
#include <cmath>

struct Punto {double x,y;};

struct Color {uint8_t R,G,B;};

struct Nodo {
    Punto p;
    Nodo* next = nullptr;
};

struct Poligono {
    unsigned cant_puntos = 0;
    Nodo* primerNodo = nullptr;
    Color color;
};

void AddVertice (Poligono&, Punto);
void RemoveVerticeEnd (Poligono&);
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


Color rojo{255,0,0}, blanco{255,255,255};

int main (){
Poligono p1;

AddVertice(p1,{2,2});
AddVertice(p1,{3,3});
AddVertice(p1,{-3,0});
AddVertice(p1,{3.14,127});
AddVertice(p1,{0,0});
AddVertice(p1,{0.15,-8});
AddVertice(p1,{-3,1});

ImprimirPoligono(p1);

CambiarColor(p1,rojo);
RemoveVerticeEnd(p1);
RemoveVerticeEnd(p1);

ImprimirPoligono(p1);

SetVertice(p1,{-2,2},3);
ImprimirPoligono(p1);

ImprimirPunto(GetVertice(p1,3));
ImprimirPunto(GetVertice(p1,1));
ImprimirPunto(GetVertice(p1,GetCantidadLados(p1)));


std::cout << "\n" << GetPerimetro(p1);
}

void AddVertice (Poligono& pol, Punto p) {
if (pol.primerNodo == nullptr){ // pregunta si el primer nodo es un punto nulo (sin datos)
    pol.primerNodo = new Nodo;
    pol.primerNodo->p = p;      // -> operador desreferencia!!!
    pol.cant_puntos++;} else {
Nodo* aux = pol.primerNodo;
while (aux->next != nullptr)    // mientras que el nodo siguente no sea null, redefinir aux como el siguiente nodo
aux = aux->next;                //aux seria el ultimo nodo con el ultimo punto

aux->next = new Nodo;
aux->next->p = p;
pol.cant_puntos++;};
} 

void ImprimirPoligono (Poligono& pol){
std::cout << "Color: (" << std::to_string(pol.color.R) << "," << std::to_string(pol.color.G) << "," << std::to_string(pol.color.B) << ")\n";
for (Nodo* aux = pol.primerNodo; aux != nullptr; aux = aux->next)
ImprimirPunto(aux->p);
};

void RemoveVerticeEnd (Poligono& pol){
Nodo* aux = pol.primerNodo;
Nodo * ant;
while (aux->next != nullptr){
ant = aux;
aux = aux->next;}
delete aux;
ant->next = nullptr;
pol.cant_puntos --;
};

void ImprimirPunto(Punto p) {
       std::cout << "Punto: (" << p.x << "," << p.y << ")\n";
};

unsigned GetCantidadLados (const Poligono& p){
return p.cant_puntos;
};

double GetDistancia (Punto p1, Punto p2){
return sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2));
};

void CambiarColor (Poligono& pol, Color c){
pol.color.R = c.R;
pol.color.G = c.G;
pol.color.B = c.B;
};

double CalculoAnguloInteriorPoligono (const Poligono& pol){

return 180 - (360 / pol.cant_puntos);
};

bool IsIgualPunto (Punto p1, Punto p2){
return (p1.x == p2.x) and (p1.y == p2.y);
};

void SetVertice (Poligono& pol, Punto p, unsigned x){
Nodo* aux = pol.primerNodo;
for (unsigned i = 1; i < x;i++) 
aux = aux->next;              

aux->p = p;
};

Punto GetVertice (const Poligono& p, unsigned posicion){
Nodo* aux = p.primerNodo;
for (unsigned i = 1; i < posicion;i++) 
aux = aux->next;              

return aux->p;
};

double GetPerimetro (const Poligono& p){
double per {0};
Nodo* aux = p.primerNodo;
for (unsigned i=1;i<p.cant_puntos; i++){
per = per + GetDistancia(aux->p,aux->next->p);
aux = aux->next;              
};
per = per + GetDistancia(aux->p,p.primerNodo->p);
return per;
};