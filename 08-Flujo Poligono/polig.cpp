#include "polig.h"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cassert>
#include <array>
#include <cmath>




double GetDistancia (Punto p1, Punto p2){
return sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2));
}


double GetPerimetro (const Poligono& p){
double per {0};
for (unsigned i=0;i<p.cant_puntos; i++)
{i < p.cant_puntos - 1 ? per = per + GetDistancia(p.Puntos.at(i),p.Puntos.at(i+1)) :
per = per + GetDistancia(p.Puntos.at(i),p.Puntos.at(0));
};
return per;
}

bool ExtraerPunto(std::istream& in, Punto& p){
	char c; //coma, numeral
	in >> p.x;
	in.get(c);
	in >> p.y;
	return (bool) in;
}


void GuardarPoligono(std::ostream& out,Poligono& pol){
out << "RGB(" << std::to_string(pol.color.R) << "," << std::to_string(pol.color.G) << "," << std::to_string(pol.color.B) << ") Puntos: ";
for (unsigned i=0;i<pol.cant_puntos;i++)
out << "(" << pol.Puntos.at(i).x << ";" << pol.Puntos.at(i).y << ") ";
out << "\n";
}

bool ExtraerPoligono(std::istream& in, Poligono& p){

	if ( not ExtraerColor(in, p.color)) return false;
	if ( not ExtraerPuntos(in, p)) return false;
	
	return (bool) in;
}

bool ExtraerColor(std::istream& in, Color& c){
	char caracter;
	unsigned ver;
	in >> ver;
	c.R = (uint8_t) ver;
	assert(c.R == (uint8_t) ver); //prueba
	in.get(caracter);
	in >> ver;
	c.G = (uint8_t) ver;
	assert(c.G == (uint8_t) ver); // prueba
	in.get(caracter);
	in >> ver;
	c.B = (uint8_t) ver;
	assert(c.B == (uint8_t) ver); // prueba
	in.get(caracter);
	return (bool) in;
}
bool ExtraerPuntos(std::istream& in, Poligono& pol){
Punto p;
char c{'n'};
int i{0};

while(c != ';'){
		
		ExtraerPunto(in, p);
		AgregarPunto(pol, p, i);
		i++;
		in.get(c);
	}
pol.cant_puntos = i;
	return (bool) in;
}


void AgregarPunto(Poligono& pol, Punto p, unsigned pos) {
pol.Puntos.at(pos) = p;
assert (pol.Puntos.at(pos).x == p.x); // prueba
assert (pol.Puntos.at(pos).y == p.y); // prueba
}

void CopiarPoligonosConPerimetrosMayoresA(double x,std::string nombrein,std::string nombreout) {
std::ifstream inpol;
inpol.open(nombrein);


std::ofstream outpol;
outpol.open(nombreout);

Poligono pol;

	while( ExtraerPoligono(inpol,pol) ) 
		if(GetPerimetro(pol) > x) 
		GuardarPoligono(outpol,pol);


}