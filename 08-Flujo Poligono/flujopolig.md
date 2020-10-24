# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Flujo Poligonos*

**Prototipos de funciones:**  

bool ExtraerPunto(std::istream&,Punto&);  
bool ExtraerPoligono(std::istream&, Poligono&);  
bool ExtraerColor(std::istream&, Color&);  
bool ExtraerPuntos(std::istream&, Poligono&);  
void AgregarPunto(Poligono&, Punto, unsigned);  
void GuardarPoligono(std::ostream&,Poligono&);  
double GetPerimetro (const Poligono&);  
double GetDistancia (Punto,Punto);  

**Modelos IPO de las funciones:**  

Flujo de entrada x Punto -> ExtraerPunto -> booleano x Punto*  
Flujo de entrada x Poligono -> ExtraerPoligono -> booleano x Poligono*  
Flujo de entrada x Color -> ExtraerColor -> booleano x Color*  
Flujo de entrada x Poligono -> ExtraerPuntos -> booleano x Poligono*  
Poligono x Punto x unsigned -> AgregarPunto -> Poligono*  
Flujo de salida x Poligono -> GuardarPoligono -> vacío (nos interesa su efecto de lado)   
Poligono -> GetPerimetro -> real (double)  
Punto x Punto -> GetDistancia -> real (double)  

NOTA: Poligono* y Punto* significa que los mismos que ingresan a la funcion salen modificados; es decir, en estos casos Poligono  y Punto son parámetros inout.  

**Pruebas (main):**

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
