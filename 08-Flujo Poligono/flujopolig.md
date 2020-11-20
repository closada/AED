# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Flujo Poligonos*


**Prototipos de funciones:**  

bool ExtraerPunto(std::istream&,Punto&);  
bool ExtraerPoligono(std::istream&, Poligono&);  
bool ExtraerColor(std::istream&, Color&);  
bool ExtraerPuntos(std::istream&, Poligono&);  
void AgregarPunto(Poligono&, Punto, unsigned);  
void MostrarPoligono(std::ostream&,Poligono&);  


**Modelos IPO de las funciones:**  

Flujo de entrada x Punto -> ExtraerPunto -> booleano x Punto*  
Flujo de entrada x Poligono -> ExtraerPoligono -> booleano x Poligono*  
Flujo de entrada x Color -> ExtraerColor -> booleano x Color*  
Flujo de entrada x Poligono -> ExtraerPuntos -> booleano x Poligono*  
Poligono x Punto x unsigned -> AgregarPunto -> Poligono*  
Flujo de salida x Poligono -> MostrarPoligono -> vacío (nos interesa su efecto de lado)   

NOTA: Poligono* y Punto* significa que los mismos que ingresan a la funcion salen modificados; es decir, en estos casos Poligono  y Punto son parámetros inout.  


**Pruebas:**  

assert (not std::cin.eof());  
	while( ExtraerPoligono(std::cin,pol) )  
		MostrarPoligono(std::cout,pol);  
assert (not std::cout.eof());  
