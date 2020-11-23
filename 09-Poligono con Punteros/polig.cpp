#include "polig.h"

struct Nodo {
    Punto p;
    Nodo* next{nullptr};
};

/************ funciones ADD *********************/

void AddVerticeEnd (Poligono& pol, Punto p) {
auto nuevo = new Nodo;
nuevo->p = p;
pol.cant_puntos++;
// LISTA VACIA

if (pol.primerNodo == nullptr){ // pregunta si el primer nodo es un puntero nulo (sin datos)
    pol.primerNodo = nuevo;
       
	return;}

// LISTA NO VACIA

auto aux = pol.primerNodo;
while (aux->next != nullptr)    // mientras que el nodo siguente no sea null, redefinir aux como el siguiente nodo
aux = aux->next;  				//aux seria el ultimo nodo con el ultimo puntero

aux->next = nuevo;

}

void AddVerticeFront (Poligono& pol, Punto p) {
auto aux = new Nodo;
aux->p = p;
aux->next = pol.primerNodo;
pol.primerNodo = aux;
pol.cant_puntos++;}

/********************* funciones GUARDAR *******************/

void GuardarPoligono (const Poligono& pol,std::ostream& out){
GuardarColor(pol.color, out);
GuardarPuntos(pol,out);
}

void GuardarColor (const Color& c, std::ostream& out){
out << "RGB(" << (unsigned) c.R << "," << (unsigned) c.G << "," << (unsigned) c.B << ") ";
}

void GuardarPuntos (const Poligono& pol,std::ostream& out){
out << pol.cant_puntos << " Puntos: ";
for (auto aux = pol.primerNodo; aux ; aux = aux->next)
GuardarPunto(aux->p, out);
out << "\n";
}

void GuardarPunto(const Punto p,std::ostream& out) {
       out << "(" << p.x << "," << p.y << ") ";
}

/********************** funciones REMOVE ************************/

void RemoveVerticeEnd (Poligono& pol){
auto aux = pol.primerNodo;
Nodo * ant;
while (aux->next != nullptr){
ant = aux;
aux = aux->next;}
delete aux;
ant->next = nullptr;
pol.cant_puntos --;
}

void RemoveVerticeFront (Poligono& pol){
if (pol.primerNodo != nullptr){
auto aux = pol.primerNodo;
pol.primerNodo = pol.primerNodo->next;
delete aux;
pol.cant_puntos --;}
}

/***************** funciones GET *************************/

unsigned GetCantidadLados (const Poligono& p){
return p.cant_puntos;
}

double GetDistancia (Punto p1, Punto p2){
return sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2));
}

Punto GetVertice (const Poligono& p, unsigned posicion){
auto aux = p.primerNodo;
for (unsigned i = 1; i < posicion;i++) 
aux = aux->next;              

return aux->p;
}

double GetPerimetro (const Poligono& p){
double per {0};

for (unsigned i=1;i<p.cant_puntos; i++)
per = per + GetDistancia(GetVertice(p,i),GetVertice(p,i+1));

per = per + GetDistancia(GetVertice(p,GetCantidadLados(p)),GetVertice(p,1));

return per;
}

/*************** funciones EXTRAS **********************/
void CambiarColor (Poligono& pol, Color c){
pol.color = c;
}

bool IsIgualPuntos (Punto p1, Punto p2){
return (p1.x == p2.x) and (p1.y == p2.y);
}

void SetVertice (Poligono& pol, Punto p, unsigned x){
auto aux = pol.primerNodo;
for (unsigned i = 1; i < x;i++) 
aux = aux->next;              

aux->p = p;
}

void LiberarEspacio (Poligono& p) {
unsigned cantidad = p.cant_puntos;
for (unsigned i=0;i<=cantidad;i++)
RemoveVerticeFront(p);

}

/************************* funciones EXTRAER *****************************/

bool ExtraerPunto(std::istream& in, Punto& p){
	char c; //coma, numeral
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


while(c != ';'){
		
		ExtraerPunto(in, p);
        AddVerticeEnd(pol,p);
		in.get(c);
		
	}
	
	return (bool) in;
}

/****************** funcion CONDICION_GUARDAR_POLIGONOS ***************/

void CopiarPoligonosConPerimetrosMayoresA(double x,std::string nombrein,std::string nombreout) {
std::ifstream inpol;
inpol.open(nombrein);


std::ofstream outpol;
outpol.open(nombreout);

Poligono pol{0};

	while( ExtraerPoligono(inpol,pol) ){
		if(GetPerimetro(pol) > x) 
		GuardarPoligono(pol,outpol);
		LiberarEspacio(pol);
	}
inpol.close();
outpol.close();
}
