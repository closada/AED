/*CAMILA VICTORIA LOSADA
20200902
Tipo de Dato PUNTO*/

#include <iostream>
#include <array>
#include <cmath>
#include <cassert>

/***** structs ******/
struct Punto {
   std::array <double,2> Coord; 
};

enum struct Cuadrante {c1, c2, c3, c4, origen};

/***** funciones *****/
void MostrarPunto(Punto);
Punto GetPunto();
Cuadrante GetCuadrante (const Punto&);
bool IsIgual (const Punto&, const Punto&);
double GetDistancia (const Punto&, const Punto&);
double GetDistanciaAlOrigen(const Punto&);
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

assert (p1.Coord.at(0) == 1);
assert (p1.Coord.at(1) == 7);
assert (p2.Coord.at(0) == -5);
assert (p2.Coord.at(1) == 2.2);

assert (Cuadrante::c1 == GetCuadrante({1,2}));
assert (Cuadrante::c2 == GetCuadrante({-3,2}));
assert (Cuadrante::c3 == GetCuadrante({-3,-11}));
assert (Cuadrante::c4 == GetCuadrante({3,-22}));
assert (Cuadrante::origen == GetCuadrante({0,0}));

};



void MostrarPunto (Punto P){
std::cout << "(" << P.Coord.at(0) << "," << P.Coord.at(1) << ")\n"; 

};

Punto GetPunto() {
    Punto Ps;
    std::cout << "Por favor, escriba el valor de X del punto: ";
    std::cin >> Ps.Coord.at(0);
    std::cout << "Por favor, escriba el valor de Y del punto: ";
    std::cin >> Ps.Coord.at(1);
    return Ps;
};

Cuadrante GetCuadrante (const Punto& pd) {
    return  (pd.Coord.at(0)>0) and (pd.Coord.at(1)>0) ? Cuadrante::c1 :
            (pd.Coord.at(0)<0) and (pd.Coord.at(1)>0) ? Cuadrante::c2 :
            (pd.Coord.at(0)<0) and (pd.Coord.at(1)<0) ? Cuadrante::c3 :
            (pd.Coord.at(0)>0) and (pd.Coord.at(1)<0) ? Cuadrante::c4 : 
            Cuadrante::origen;
};

bool IsIgual (const Punto& p1, const Punto& p2){
return (p1.Coord.at(0) == p2.Coord.at(0)) and (p1.Coord.at(1) == p2.Coord.at(1)) ? true : false;
};

double GetDistancia (const Punto& p1, const Punto& p2){
return sqrt(((p2.Coord.at(0) - p1.Coord.at(0))*(p2.Coord.at(0) - p1.Coord.at(0))) + ((p2.Coord.at(1) - p1.Coord.at(1))*(p2.Coord.at(1) - p1.Coord.at(1))));

};

double GetDistanciaAlOrigen(const Punto& p) {
return sqrt((p.Coord.at(0)*p.Coord.at(0)) + (p.Coord.at(1)*p.Coord.at(1)));
};

void Mover (Punto& p, double cant_x, double cant_y){
p.Coord.at(0) += cant_x;
p.Coord.at(1) += cant_y;

};