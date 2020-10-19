#include "poligsc.h"
#include <iostream>
#include <cassert>

int main () { 

/*std::ifstream inp;
inp.open("datos_entrada_punto.txt");

std::ifstream inpol;
inpol.open("datos_entrada_poligono.txt");

std::ofstream outp;
outp.open("datos_salida_punto.txt");

std::ofstream outpol;
outpol.open("datos_salida_poligono.txt");*/

Punto p;
Poligono pol;

assert (not std::cin.eof());
	while( ExtraerPoligono(std::cin,pol) )
		MostrarPoligono(std::cout,pol);
assert (not std::cout.eof());

}
