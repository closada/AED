/* Camila Victoria Losada
2020
Triangulo*/

#include <iostream>
#include <cassert>
#include <array>

struct Punto {double x,y;}; /*ESTRUCTURA*/
struct Triangulo {Punto p1,p2,p3;}; /*TUPLA*/
using TipoTriangulo = std::array<Punto,3>; /*ARRAY TRIANGULO -- yo voy a usar este en el resto del programa*/

/*FUNCIONES*/
void MostrarTriangulo(TipoTriangulo); 
TipoTriangulo leerTriangulo();


int main () {
TipoTriangulo T1 {{ {3,-12} , {-3,3} , {3.4,0} }};

MostrarTriangulo(T1);
MostrarTriangulo(leerTriangulo());
}

void MostrarTriangulo (TipoTriangulo t){
std::cout << "(" << t.at(0).x << "," << t.at(0).y << ")"<< "," << "(" << t.at(1).x << "," << t.at(1).y << ")" << "," << "(" << t.at(2).x << "," << t.at(2).y << ")" << "\n"; 

}

TipoTriangulo leerTriangulo() {
    TipoTriangulo t1;
    std::cin >> t1.at(0).x;
    std::cin >> t1.at(0).y;
    std::cin >> t1.at(1).x;
    std::cin >> t1.at(1).y;
    std::cin >> t1.at(2).x;
    std::cin >> t1.at(2).y;
    return t1;
}