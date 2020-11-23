#include "polig.h"


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
	char c; //coma, espacio
	in >> p.x;
	in.get(c);
	in >> p.y;
	return (bool) in;
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
assert (pol.Puntos.at(pos).x == p.x); // prueba
assert (pol.Puntos.at(pos).y == p.y); // prueba
}


void borrarDatosPoligono(Poligono& pol){
pol.cant_puntos = 0;
}


void GuardarPoligono (const Poligono& pol,std::ostream& out){
GuardarColor(pol.color, out);
GuardarPuntos(pol,out);

}

void GuardarColor (const Color& c, std::ostream& out){
out << "RGB(" << (unsigned) c.R << "," << (unsigned) c.G << "," << (unsigned) c.B << ") ";
}

void GuardarPuntos (const Poligono& pol,std::ostream& out){
out << pol.cant_puntos << " Puntos: ";
for (unsigned i = 0; i<pol.cant_puntos ; i++)
GuardarPunto(pol.Puntos.at(i), out);
out << "\n";
}

void GuardarPunto(const Punto p,std::ostream& out) {
       out << "(" << p.x << "," << p.y << ") ";
}


void CopiarPoligonosConPerimetrosMayoresA(double x,std::string nombrein,std::string nombreout) {
std::ifstream inpol;
inpol.open(nombrein);


std::ofstream outpol;
outpol.open(nombreout);

Poligono pol;

	while( ExtraerPoligono(inpol,pol) ) 
		if(GetPerimetro(pol) > x) {
		GuardarPoligono(pol,outpol);
		borrarDatosPoligono(pol);}
		
inpol.close();
outpol.close();

}