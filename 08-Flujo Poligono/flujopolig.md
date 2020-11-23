# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Flujo Poligonos*


**Prototipos de funciones:**  

bool ExtraerPunto(std::istream&,Punto&);  
bool ExtraerPoligono(std::istream&, Poligono&);  
bool ExtraerColor(std::istream&, Color&);  
bool ExtraerPuntos(std::istream&, Poligono&);  
void AgregarPunto(Poligono&, Punto, unsigned);  

void GuardarPunto(const Punto,std::ostream&);  
void GuardarPoligono (const Poligono&,std::ostream&);  
void GuardarColor (const Color&,std::ostream&);  
void GuardarPuntos( const Poligono&, std::ostream&);  
double GetPerimetro (const Poligono&);  
double GetDistancia (Punto,Punto);  
void borrarDatosPoligono(Poligono&);  
void CopiarPoligonosConPerimetrosMayoresA(double,std::string,std::string);  



**Modelos IPO de las funciones:**  

Flujo de entrada x Punto -> ExtraerPunto -> booleano x Punto*  
Flujo de entrada x Poligono -> ExtraerPoligono -> booleano x Poligono*  
Flujo de entrada x Color -> ExtraerColor -> booleano x Color*  
Flujo de entrada x Poligono -> ExtraerPuntos -> booleano x Poligono*  
Poligono x Punto x unsigned -> AgregarPunto -> Poligono*  
Punto x Flujo de salida -> GuardarPunto -> vacío (nos interesa su efecto de lado)  
Poligono x Flujo de salida -> GuardarPoligono -> vacío (nos interesa su efecto de lado)  
Color x Flujo de salida -> GuardarColor -> vacío (nos interesa su efecto de lado)  
Poligono x Flujo de salida -> GuardarPuntos -> vacío (nos interesa su efecto de lado)  
Poligono -> GetPerimetro -> double  
Punto x Punto -> GetDistancia -> double  
Poligono -> borrarDatosPoligono -> vacío (nos interesa su efecto de lado)  
double x string x string -> CopiarPoligonosConPerimetrosMayoresA -> void (nos interesa su efecto de lado)  

NOTA: Poligono* y Punto* significa que los mismos que ingresan a la funcion salen modificados; es decir, en estos casos Poligono  y Punto son parámetros inout.  


**Pruebas:**  

CopiarPoligonosConPerimetrosMayoresA(250,"datos_polig.txt","salida.txt");

