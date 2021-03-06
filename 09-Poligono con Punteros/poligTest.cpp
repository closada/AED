#include "polig.h"
double MAX{100};

int main (){

Poligono p1{0},p2{0};

AddVerticeFront(p1,{2,2});
assert(IsIgualPuntos(GetVertice(p1,1),{2,2}));


AddVerticeFront(p1,{3,3});
assert(IsIgualPuntos(GetVertice(p1,1),{3,3}));

AddVerticeFront(p1,{-3,0});
assert(IsIgualPuntos(GetVertice(p1,1),{-3,0}));

AddVerticeFront(p1,{3.14,127});
assert(IsIgualPuntos(GetVertice(p1,1),{3.14,127}));

AddVerticeFront(p1,{0,0});
assert(IsIgualPuntos(GetVertice(p1,1),{0,0}));

AddVerticeFront(p1,{0.15,-8});
assert(IsIgualPuntos(GetVertice(p1,1),{0.15,-8}));

AddVerticeFront(p1,{-3,1});
assert(IsIgualPuntos(GetVertice(p1,1),{-3,1}));

//ImprimirPoligono(p1);

CambiarColor(p1,rojo);
assert(p1.color.R == rojo.R);
assert(p1.color.G == rojo.G);
assert(p1.color.B == rojo.B);

RemoveVerticeFront(p1);
assert( not IsIgualPuntos(GetVertice(p1,1),{-3,1}));

RemoveVerticeFront(p1);
assert(not IsIgualPuntos(GetVertice(p1,1),{0.15,-8}));

//ImprimirPoligono(p1);

SetVertice(p1,{-2,2},3);
assert(IsIgualPuntos(GetVertice(p1,3),{-2,2}));

assert(IsIgualPuntos(GetVertice(p1,GetCantidadLados(p1)),{2,2}));

assert (GetPerimetro(p1) > 261.3 and GetPerimetro(p1) < 261.5);

CambiarColor(p2,verde);
AddVerticeFront(p2,{1,1});
assert(IsIgualPuntos(GetVertice(p2,1),{1,1}));

AddVerticeFront(p2,{2,2});
assert(IsIgualPuntos(GetVertice(p2,1),{2,2}));

AddVerticeEnd(p2,{3,3});
assert(IsIgualPuntos(GetVertice(p2,GetCantidadLados(p2)),{3,3}));


RemoveVerticeFront(p2);
assert(IsIgualPuntos(GetVertice(p2,1),{1,1}));

RemoveVerticeEnd(p2);
assert(IsIgualPuntos(GetVertice(p2,GetCantidadLados(p2)),{1,1}));


//ImprimirPoligono(p2);
LiberarEspacio(p1);
LiberarEspacio(p2);

/************** prueba con flujos **********************/

CopiarPoligonosConPerimetrosMayoresA(250,"datos_polig.txt","salida.txt");

}