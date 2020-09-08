/*CAMILA VICTORIA LOSADA
20200902
Tipo de Dato PUNTO*/

#include <iostream>
#include <array>
#include <cmath>
#include <cassert>

/***** structs ******/

struct Punto {
   double x, y;
};


enum struct Cuadrante {c1, c2, c3, c4, origen, EjeX, EjeY};

/***** funciones *****/
void ImprimirPunto(Punto);
Punto GetPunto(double,double);
Cuadrante GetCuadrante (Punto);
bool IsIgual (Punto, Punto);
double GetDistancia (Punto,Punto);
double GetDistanciaAlOrigen(Punto);
void Mover (Punto&, double, double);

int main () {
    Punto p1 {2,2}, p2{-5,2.2};
assert (9 == GetDistancia({-4,0},{5,0}));
assert (0 == GetDistancia({7,-5},{7,-5}));

assert (4 == GetDistanciaAlOrigen({-4,0}));
assert (5 == GetDistanciaAlOrigen({0,5}));

assert (IsIgual({2,2},{2,2}));

Mover(p1,-1,5);
Mover(p2,0,0);

assert (p1.x == 1);
assert (p1.y == 7);
assert (p2.x == -5);
assert (p2.y == 2.2);

assert (Cuadrante::c1 == GetCuadrante({1,2}));
assert (Cuadrante::c2 == GetCuadrante({-3,2}));
assert (Cuadrante::c3 == GetCuadrante({-3,-11}));
assert (Cuadrante::c4 == GetCuadrante({3,-22}));
assert (Cuadrante::origen == GetCuadrante({0,0}));

};



void ImprimirPunto (Punto P){
std::cout << "(" << P.x << "," << P.y << ")\n"; 

};

Punto GetPunto(double c1, double c2) {
    Punto Ps;
    Ps.x = c1;
    Ps.y = c2;
    return Ps;
};

Cuadrante GetCuadrante (Punto pd) {
    return  (pd.x>0) and (pd.y>0) ? Cuadrante::c1 :
            (pd.x<0) and (pd.y>0) ? Cuadrante::c2 :
            (pd.x<0) and (pd.y<0) ? Cuadrante::c3 :
            (pd.x>0) and (pd.y<0) ? Cuadrante::c4 : 
            (pd.x == 0) and (pd.y != 0) ? Cuadrante::EjeX :
            (pd.x != 0) and (pd.y == 0) ? Cuadrante::EjeY :
            Cuadrante::origen;
};

bool IsIgual (Punto p1, Punto p2){
return (p1.x == p2.x) and (p1.y == p2.y);
};

double GetDistancia (Punto p1, Punto p2){
return sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2));


};

double GetDistanciaAlOrigen(Punto p) {
return sqrt((p.x*p.x) + (p.y*p.y));
};

void Mover (Punto& p, double cant_x, double cant_y){
p.x = p.x + cant_x;
p.y = p.y + cant_y;

};