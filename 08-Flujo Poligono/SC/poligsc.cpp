#include "poligsc.h"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <array>

bool ExtraerPunto(std::istream& in, Punto& p){
	char c; //coma, numeral
	in >> p.x;
	in.get(c);
	in >> p.y;
	return (bool) in;
}


void MostrarPoligono(std::ostream& out,Poligono& pol){
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
	in.get(caracter);
	in >> ver;
	c.G = (uint8_t) ver;
	in.get(caracter);
	in >> ver;
	c.B = (uint8_t) ver;
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

}