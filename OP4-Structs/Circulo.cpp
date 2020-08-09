/* Camila Victoria Losada
2020
Circulo*/

#include <iostream>
#include <cassert>

struct Punto {double x,y;}; /*ESTRUCTURA*/

struct Circulo {double radio; Punto centro;}; /*ESTRUCTURA*/

/*FUNCIONES*/
void MostrarCirculo(Circulo); 
Circulo leerCirculo();
double Perimetro (Circulo);
double Area (Circulo);
double Diametro (Circulo);


int main () {
Circulo circ{4,0,0};

MostrarCirculo({23,5.6,8});
MostrarCirculo(circ);
MostrarCirculo(leerCirculo());

assert (25.12 == Perimetro(circ));
assert (12.56 == Perimetro({2,2,2}));
assert (50.24 == Area(circ));
assert (12.56 == Area({2,2,45}));
assert (8 == Diametro(circ));
assert (32.6 == Diametro({16.3,4,567}));
}

void MostrarCirculo(Circulo c1) {

std::cout << "(" << c1.radio << "," << "(" << c1.centro.x << "," << c1.centro.y << ")" << ")" << "\n"; 

}


Circulo leerCirculo() {
    Circulo c;
    std::cin >> c.radio;
    std::cin >> c.centro.x;
    std::cin >> c.centro.y;
    return c;

}


double Perimetro (Circulo c2) {return 2*3.14*c2.radio;}

double Area (Circulo c3) {return 3.14*c3.radio*c3.radio;}

double Diametro (Circulo c4) {return 2*c4.radio;}
