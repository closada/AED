#include "polig.h"
#include <iostream>
#include <cassert>

double VALOR{100};
int main () { 

/*std::ifstream inpol;
inpol.open("datos_polig.txt");


std::ofstream outpol;
outpol.open("salida.txt");*/

Punto p;
Poligono pol;

	while( ExtraerPoligono(std::cin,pol) ) 
		if(GetPerimetro(pol) > VALOR) /*VALOR es una variable global*/
		GuardarPoligono(std::cout,pol);


}
