#include "polig.h"

struct Nodo {
    Punto p;
    Nodo* next{nullptr};
};


void AddVerticeEnd (Poligono& pol, Punto p) {
auto nuevo = new Nodo;
nuevo->p = p;
pol.cant_puntos++;
// LISTA VACIA

if (pol.primerNodo == nullptr){ // pregunta si el primer nodo es un puntero nulo (sin datos)
    pol.primerNodo = nuevo;
    //pol.primerNodo->p = p;      // -> operador desreferencia!!!
    
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

void ImprimirPoligono (Poligono& pol){
ImprimirColor(pol.color);
for (auto aux = pol.primerNodo; aux ; aux = aux->next)
ImprimirPunto(aux->p);
}

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
pol.cant_puntos --;
}
}


void ImprimirPunto(Punto p) {
       std::cout << "Punto: (" << p.x << "," << p.y << ")\n";
}

unsigned GetCantidadLados (const Poligono& p){
return p.cant_puntos;
}

double GetDistancia (Punto p1, Punto p2){
return sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2));
}

void CambiarColor (Poligono& pol, Color c){
pol.color.R = c.R;
pol.color.G = c.G;
pol.color.B = c.B;
}

double CalculoAnguloInteriorPoligono (const Poligono& pol){

return 180 - (360 / pol.cant_puntos);
}

bool IsIgualPunto (Punto p1, Punto p2){
return (p1.x == p2.x) and (p1.y == p2.y);
}

void SetVertice (Poligono& pol, Punto p, unsigned x){
auto aux = pol.primerNodo;
for (unsigned i = 1; i < x;i++) 
aux = aux->next;              

aux->p = p;
}

Punto GetVertice (const Poligono& p, unsigned posicion){
auto aux = p.primerNodo;
for (unsigned i = 1; i < posicion;i++) 
aux = aux->next;              

return aux->p;
}

double GetPerimetro (const Poligono& p){
double per {0};
auto aux = p.primerNodo;
for (unsigned i=1;i<p.cant_puntos; i++){
per = per + GetDistancia(aux->p,aux->next->p);
aux = aux->next;              
};
per = per + GetDistancia(aux->p,p.primerNodo->p);
return per;
}

void LiberarEspacio (Poligono& p) {

for (auto aux = p.primerNodo; aux; aux = p.primerNodo){
p.primerNodo = p.primerNodo->next;
delete aux;};
p.cant_puntos = 0;
}

/************************* funciones plus poligono *****************************/

bool ExtraerPunto(std::istream& in, Punto& p){
	char c; //coma, numeral
	in >> p.x;
	in.get(c);
	in >> p.y;
	return (bool) in;
}


void GuardarPoligono(std::ostream& out,Poligono& pol){
out << "RGB(" << std::to_string(pol.color.R) << "," << std::to_string(pol.color.G) << "," << std::to_string(pol.color.B) << ") Puntos: ";
for (unsigned i=1;i<=pol.cant_puntos;i++)
out << "(" << GetVertice(pol,i).x << ";" << GetVertice(pol,i).y << ") ";
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


while(c != ';'){
		
		ExtraerPunto(in, p);
        AddVerticeEnd(pol,p);
		in.get(c);
	}

	return (bool) in;
}

void CopiarPoligonosConPerimetrosMayoresA(double x,std::string nombrein,std::string nombreout) {
std::ifstream inpol;
inpol.open(nombrein);


std::ofstream outpol;
outpol.open(nombreout);

Poligono pol{0};

	while( ExtraerPoligono(inpol,pol) ){
		if(GetPerimetro(pol) > x) 
		GuardarPoligono(outpol,pol);
		LiberarEspacio(pol);
	}

}


/****************************** funciones de Color *********************************/


void ImprimirColor (const Color& c){
std::cout << "RGB(" << std::to_string(c.R) << "," << std::to_string(c.G) << "," << std::to_string(c.B) << ")\n";
}

