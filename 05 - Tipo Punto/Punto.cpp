#include "Punto.h"
#include <iostream>
#include <cmath>


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
            Cuadrante::NC;
};

Eje GetEje (Punto p) {
return  p.x == 0 and p.y != 0 ? Eje::EX :
        p.x != 0 and p.y == 0 ? Eje::EY :
        p.x == 0 and p.y == 0 ? Eje::ORIGEN :
        Eje::NC;
};

bool IsIgual (Punto p1, Punto p2){
return (p1.x == p2.x) and (p1.y == p2.y);
};

double GetDistancia (Punto p1, Punto p2){
return sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2));


};

double GetDistanciaAlOrigen(Punto p) {
return GetDistancia({0,0},p);
};

void Mover (Punto& p, double cant_x, double cant_y){
p.x = p.x + cant_x;
p.y = p.y + cant_y;

};
