/* Camila Victoria Losada
2020
Rectangulo*/

#include <iostream>
#include <cassert>
#include <array>

struct Punto {double x,y;}; /*ESTRUCTURA*/
struct Rv01 {Punto p1,p2,p3,p4;}; /*TUPLA*/
using Rv02 = std::array<Punto,4>; /*ARRAY Rectangulo*/
struct Rv03 {double base, altura;}; /* ESTRUCTURA con base y altura -- voy a usar este para las funciones; DEBEN SER + */

/*FUNCIONES*/
void MostrarRectangulo(Rv03); 
Rv03 leerRectangulo();
double Perimetro (Rv03);
double Area (Rv03);

int main () {
Rv03 rect1 {3,5};
MostrarRectangulo(leerRectangulo());
MostrarRectangulo({23,14.5});
MostrarRectangulo(rect1);

assert (16 == Perimetro(rect1));
assert (57 == Perimetro({13,15.5}));
assert (49 == Area({14,3.5}));
assert (24 == Area({12,2}));

}

void MostrarRectangulo(Rv03 r){
std::cout << "Base: " << r.base << ", altura: " << r.altura << "\n"; 

}

Rv03 leerRectangulo() {
    Rv03 r1;
    std::cin >> r1.base;
    std::cin >> r1.altura;
    return r1;
}

double Perimetro (Rv03 r2) {return (r2.base*2) + (r2.altura*2);}

double Area (Rv03 r3) {return r3.base*r3.altura;}