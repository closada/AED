#include "Punto.h"
#include <cassert>
#include <iostream>

int main () {
    Punto p1 {2,2}, p2{-5,2.2};
assert  (IsIgual(GetPunto(2,2),p1));
assert  (IsIgual(GetPunto(-5,2.2),p2));

assert (9 == GetDistancia({-4,0},{5,0}));
assert (0 == GetDistancia({7,-5},{7,-5}));

assert (4 == GetDistanciaAlOrigen({-4,0}));
assert (5 == GetDistanciaAlOrigen({0,5}));

assert (IsIgual({2,2},{2,2}));

Mover(p1,-1,5);
Mover(p2,0,0);

assert (IsIgual(p1,{1,7}));
assert (IsIgual(p2,{-5,2.2}));
    
assert (Cuadrante::c1 == GetCuadrante({1,2}));
assert (Cuadrante::c2 == GetCuadrante({-3,2}));
assert (Cuadrante::c3 == GetCuadrante({-3,-11}));
assert (Cuadrante::c4 == GetCuadrante({3,-22}));
assert (Cuadrante::NC == GetCuadrante({0,2}));

assert (Eje::EX == GetEje({0,-3.5}));
assert (Eje::EY == GetEje({2,0}));
assert (Eje::ORIGEN == GetEje({0,0}));

};
