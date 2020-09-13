/*CAMILA VICTORIA LOSADA
20200902
Tipo de Dato PUNTO*/

#include <iostream>

/***** structs ******/

struct Punto {
   double x, y;
};


enum struct Cuadrante {c1, c2, c3, c4, NC};
enum struct Eje {EX, EY, ORIGEN, NC};

/***** funciones *****/
void ImprimirPunto(Punto);
Punto GetPunto(double,double);
Cuadrante GetCuadrante (Punto);
Eje GetEje (Punto);
bool IsIgual (Punto, Punto);
double GetDistancia (Punto,Punto);
double GetDistanciaAlOrigen(Punto);
void Mover (Punto&, double, double);