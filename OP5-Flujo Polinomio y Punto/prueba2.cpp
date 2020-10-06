/* 20201002
Camila Victoria Losada */

#include <iostream>
#include <fstream>
#include <cstdint>
#include <array>
#include <sstream>
#include <string>

struct Punto {double x,y;};

struct Color {uint8_t R,G,B;};

struct Poligono {
    unsigned cant_puntos;
    std::array <Punto,30> Puntos; //como maximo, puede tratarse de un Triacontagono
    Color color;
};

bool ExtraerPunto(std::ifstream&,Punto&);
bool ExtraerPoligono(std::ifstream&, Poligono&);
bool ExtraerColor(std::ifstream&, Color&);
bool ExtraerPuntos(std::ifstream&, Poligono&);
void MostrarPunto(std::ofstream&, Punto);
void AgregarPunto(Poligono&, Punto, unsigned);
void MostrarPoligono(std::ofstream&,Poligono&);

int main () { 

std::ifstream inp;
inp.open("datos_entrada_punto.txt");

std::ifstream inpol;
inpol.open("datos_entrada_poligono2.txt");

std::ofstream outp;
outp.open("datos_salida_punto.txt");

std::ofstream outpol;
outpol.open("datos_salida_poligono2.txt");

Punto p;
Poligono pol;

	while( ExtraerPunto(inp,p) )
		MostrarPunto(outp,p);

	while( ExtraerPoligono(inpol,pol) )
		MostrarPoligono(outpol,pol);
}

bool ExtraerPunto(std::ifstream& in, Punto& p){
	char c; //coma, numeral
	in >> p.x;
	in.get(c);
	in >> p.y;
	in.get(c);
	return (bool) in;
}

void MostrarPunto(std::ofstream& out,Punto p){
	out << "(" << p.x << ";" << p.y << ")\n";
}

void MostrarPoligono(std::ofstream& out,Poligono& pol){
out << "RGB(" << std::to_string(pol.color.R) << "," << std::to_string(pol.color.G) << "," << std::to_string(pol.color.B) << ") Puntos: ";
for (unsigned i=0;i<pol.cant_puntos;i++)
out << "(" << pol.Puntos.at(i).x << ";" << pol.Puntos.at(i).y << ") ";
out << "\n";
}

bool ExtraerPoligono(std::ifstream& in, Poligono& p){
	ExtraerColor(in, p.color);
	ExtraerPuntos(in, p);
	return (bool) in;
}

bool ExtraerColor(std::ifstream& in, Color& c){
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
bool ExtraerPuntos(std::ifstream& in, Poligono& pol){
unsigned i{0};
Punto p;
//std::string s;
//std::getline(in,s);

	for(;(bool) in; ){
		ExtraerPunto(in,p);
		AgregarPunto(pol, p, i);
		pol.cant_puntos = i + 1;
		i++;
				
	}

	
	return (bool) in;
}


void AgregarPunto(Poligono& pol, Punto p, unsigned pos) {
pol.Puntos.at(pos).x = p.x;
pol.Puntos.at(pos).y = p.y;

}