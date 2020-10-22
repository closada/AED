#include <iostream>
#include <fstream>
#include <cstdint>
#include <array>
#include "poligcc.h"

bool ExtraerPunto(std::istream& in, Punto& p){
	char c; //coma, numeral
	in >> p.x;
	in.get(c);
	in >> p.y;
	in.get(c);
	return (bool) in;
}

void MostrarPunto(std::ostream& out,Punto p){
	out << "(" << p.x << ";" << p.y << ")\n";
}

void MostrarPoligono(std::ostream& out,Poligono& pol){
out << "RGB(" << std::to_string(pol.color.R) << "," << std::to_string(pol.color.G) << "," << std::to_string(pol.color.B) << ") Puntos:\n";
for (unsigned i=0;i<pol.cant_puntos;i++)
MostrarPunto(out,pol.Puntos.at(i));
}

bool ExtraerPoligono(std::istream& in, Poligono& p){

	ExtraerColor(in, p.color);

in >> p.cant_puntos;
in.get();
	
	ExtraerPuntos(in, p);
	
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

for(int i = 0 ;i < pol.cant_puntos ;i++ ){
		ExtraerPunto(in, p);
		AgregarPunto(pol, p, i);
	}

	
	return (bool) in;
}


void AgregarPunto(Poligono& pol, Punto p, unsigned pos) {
pol.Puntos.at(pos) = p;
}
