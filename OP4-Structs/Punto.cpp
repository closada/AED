/* Camila Victoria Losada
2020
Punto*/

#include <iostream>
#include <cassert>
struct Punto {double x,y;}; /*ESTRUCTURA*/

enum struct Cuadrante {c1, c2, c3, c4, origen}; /*ENUMERACION*/

/*FUNCIONES*/
void MostrarPunto(Punto); 
Punto leerPunto();
Cuadrante DefCuadrante (Punto);
Punto SumaPuntos (Punto,Punto);
Punto RestaPuntos (Punto,Punto);


int main () {
Punto p1{3.14,12};

MostrarPunto(p1);
MostrarPunto({3.14,0});
MostrarPunto(leerPunto());
MostrarPunto(SumaPuntos(leerPunto(),leerPunto()));
MostrarPunto(RestaPuntos({4,7},{-4,123}));

assert (Cuadrante::c1 == DefCuadrante({1,2}));
assert (Cuadrante::c2 == DefCuadrante({-3,2}));
assert (Cuadrante::c3 == DefCuadrante({-3,-11}));
assert (Cuadrante::c4 == DefCuadrante({3,-22}));
assert (Cuadrante::origen == DefCuadrante({0,0}));

}

void MostrarPunto (Punto P){
std::cout << "(" << P.x << "," << P.y << ")" << "\n"; 

}

Punto leerPunto() {
    Punto Ps;
    std::cin >> Ps.x;
    std::cin >> Ps.y;
    return Ps;
}

Cuadrante DefCuadrante (Punto pd) {
    return  (pd.x>0) and (pd.y>0) ? Cuadrante::c1 :
            (pd.x<0) and (pd.y>0) ? Cuadrante::c2 :
            (pd.x<0) and (pd.y<0) ? Cuadrante::c3 :
            (pd.x>0) and (pd.y<0) ? Cuadrante::c4 : 
            Cuadrante::origen;
}

Punto SumaPuntos (Punto p1,Punto p2) {
Punto presultado;
presultado.x = p1.x + p2.x;
presultado.y = p1.y + p2.y;
return presultado;
}


Punto RestaPuntos (Punto p1,Punto p2) {
Punto presultado;
presultado.x = p1.x - p2.x;
presultado.y = p1.y - p2.y;
return presultado;
}