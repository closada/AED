#include "polig.h"

void AddVerticeEnd (Poligono& pol, Punto p) {
if (pol.primerNodo == nullptr){ // pregunta si el primer nodo es un punto nulo (sin datos)
    pol.primerNodo = new Nodo;
    pol.primerNodo->p = p;      // -> operador desreferencia!!!
    pol.cant_puntos++;} else {
auto aux = pol.primerNodo;
while (aux->next != nullptr)    // mientras que el nodo siguente no sea null, redefinir aux como el siguiente nodo
aux = aux->next;                //aux seria el ultimo nodo con el ultimo punto

aux->next = new Nodo;
aux->next->p = p;
pol.cant_puntos++;};
}

void AddVerticeFront (Poligono& pol, Punto p) {
auto aux = new Nodo;
aux->p = p;
aux->next = pol.primerNodo;
pol.primerNodo = aux;
pol.cant_puntos++;};

void ImprimirPoligono (Poligono& pol){
std::cout << "Color: (" << std::to_string(pol.color.R) << "," << std::to_string(pol.color.G) << "," << std::to_string(pol.color.B) << ")\n";
for (auto aux = pol.primerNodo; aux ; aux = aux->next)
ImprimirPunto(aux->p);
};

void RemoveVerticeEnd (Poligono& pol){
auto aux = pol.primerNodo;
Nodo * ant;
while (aux->next != nullptr){
ant = aux;
aux = aux->next;}
delete aux;
ant->next = nullptr;
pol.cant_puntos --;
};

void RemoveVerticeFront (Poligono& pol){
if (pol.primerNodo != nullptr){
auto aux = pol.primerNodo;
pol.primerNodo = pol.primerNodo->next;
delete aux;
pol.cant_puntos --;
}
};


void ImprimirPunto(Punto p) {
       std::cout << "Punto: (" << p.x << "," << p.y << ")\n";
};

unsigned GetCantidadLados (const Poligono& p){
return p.cant_puntos;
};

double GetDistancia (Punto p1, Punto p2){
return sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2));
};

void CambiarColor (Poligono& pol, Color c){
pol.color.R = c.R;
pol.color.G = c.G;
pol.color.B = c.B;
};

double CalculoAnguloInteriorPoligono (const Poligono& pol){

return 180 - (360 / pol.cant_puntos);
};

bool IsIgualPunto (Punto p1, Punto p2){
return (p1.x == p2.x) and (p1.y == p2.y);
};

void SetVertice (Poligono& pol, Punto p, unsigned x){
auto aux = pol.primerNodo;
for (unsigned i = 1; i < x;i++) 
aux = aux->next;              

aux->p = p;
};

Punto GetVertice (const Poligono& p, unsigned posicion){
auto aux = p.primerNodo;
for (unsigned i = 1; i < posicion;i++) 
aux = aux->next;              

return aux->p;
};

double GetPerimetro (const Poligono& p){
double per {0};
auto aux = p.primerNodo;
for (unsigned i=1;i<p.cant_puntos; i++){
per = per + GetDistancia(aux->p,aux->next->p);
aux = aux->next;              
};
per = per + GetDistancia(aux->p,p.primerNodo->p);
return per;
};

void LiberarEspacio (Poligono& p) {

for (auto aux = p.primerNodo; aux; aux = p.primerNodo){
p.primerNodo = p.primerNodo->next;
delete aux;};
p.cant_puntos = 0;
};

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
int i{0};

while(c != ';'){
		
		ExtraerPunto(in, p);
        AddVerticeFront(pol,p);
		i++;
		in.get(c);
	}
pol.cant_puntos = i;
	return (bool) in;
}



/****************************** funciones de Color *********************************/

Color GetColor (void){
Color col;
for (unsigned i=0; i<3;i++)
std::cin >> col.R >> col.G >> col.B;
return col;
}


Color MezclarDosColoresenPIguales (const Color& col1,const Color& col2){
Color Final;
Final.R = (col1.R + col2.R) / 2;
Final.G = (col1.G + col2.G) / 2;
Final.B = (col1.B + col2.B) / 2;
return Final;
};

void ImprimirColor (const Color& c){
std::cout << "RGB(" << std::to_string(c.R) << "," << std::to_string(c.G) << "," << std::to_string(c.B) << ")\n";
};

Color MezclarDosColoresProporcion (const Color& c1, unsigned p1, const Color& c2, unsigned p2){
Color Final;
((p1*c1.R/100) + (p2*c2.R/100)) / 2 > 255 ? Final.R = 255 : Final.R = ((p1*c1.R/100) + (p2*c2.R/100)) / 2;
((p1*c1.G/100) + (p2*c2.G/100)) / 2 > 255 ? Final.G = 255 : Final.G = ((p1*c1.G/100) + (p2*c2.G/100)) / 2;
((p1*c1.B/100) + (p2*c2.B/100)) / 2 > 255 ? Final.B = 255 : Final.B = ((p1*c1.B/100) + (p2*c2.B/100)) / 2;
return Final;
};

Color GetComplementario (const Color& c){
Color comp;
comp.R = 255 - c.R;
comp.G = 255 - c.G;
comp.B = 255 - c.B;
return comp;
};

Color Sumar (const Color& c1,const Color& c2){
Color Suma;
c1.R + c2.R > 255 ? Suma.R = 255 : Suma.R = c1.R + c2.R;
c1.G + c2.G > 255 ? Suma.G = 255 : Suma.G = c1.G + c2.G;
c1.B + c2.B > 255 ? Suma.B = 255 : Suma.B = c1.B + c2.B;
return Suma;
};

Color Restar (const Color& c1,const Color& c2) {
Color Resta;
c1.R - c2.R < 0 ? Resta.R = c2.R - c1.R :
Resta.R = c1.R - c2.R;

c1.G - c2.G < 0 ? Resta.G = c2.G - c1.G :
Resta.G = c1.G - c2.G;

c1.B - c2.B < 0 ? Resta.B = c2.B - c1.B :
Resta.B = c1.B - c2.B;

return Resta;
};

std::string GetHtmlHex (const Color& c1){
std::stringstream ver;
ver << "#" << std::hex <<  std::setfill('0') << std::setw(2) << int(c1.R)  <<  std::setfill('0') << std::setw(2) << int(c1.G) <<  std::setfill('0') << std::setw(2) << int(c1.B) ;
return ver.str();
};

std::string GetHtmlRgb (std::string s){
std::stringstream num1,num2,num3,ver;
int r,g,b;
num1 << std::hex << s.substr(1,2);
num1 >> r;
num2 << std::hex << s.substr(3,2);
num2 >> g;
num3 << std::hex << s.substr(5,2);
num3 >> b;
ver << "rgb(" << r << "," << g <<  "," << b << ")";
return ver.str();
};

void CrearSvgConTextoEscritoEnAltoContr(std::string nombre, std::string mensaje, const Color& c){
std::ofstream file;
file.open(nombre + ".svg");
file << "<svg xmlns='http://www.w3.org/2000/svg'>\n";
file << "<rect x='0' y='0' height='100' width='500' style='fill: " << GetHtmlHex(GetComplementario(c)) << "'/> \n";
file << "<text x='5' y='18' style='fill: " << GetHtmlRgb(GetHtmlHex(c)) << ";background-color: "<<GetHtmlHex(GetComplementario(c)) <<"#ff0000'>\n";
file << mensaje << "\n";
file << "</text>\n</svg>\n";
file.close();
};

bool IsIgual (const Color& c1, const Color& c2){
return (c1.R == c2.R) and (c1.G == c2.G) and (c1.B == c2.B);
};