# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Color*

**Hipótesis del problema:**  

Generar un tipo de dato Color en formato RGB; el mismo con cada uno de los tres componentes en uint8_t. Los valores de los componentes se encuentran en el rango de 0 a 255.

**Definición en C++:**  

struct Color {uint8_t R,G,B;};


**Conjunto de Operaciones:**  

El conjunto de operaciones son las funciones descriptas en el apartado Prototipo de funciones.  

**Conjunto de Valores:**  

Los valores que puede tomar este tipo son en formato (..,..,..); es decir, son todas las posibles combinaciones entre los 3 componentes de o a 255  
(son 256^3 = 16.777.216)  

**Prototipos de funciones:**  

Color MezclarDosColoresenPIguales (const Color&,const Color&);  
Color MezclarDosColoresProporcion (const Color&, unsigned, const Color&, unsigned); // se asume los unsigned son las proporciones  
Color GetComplementario (const Color&);  
Color Sumar (const Color&,const Color&);  
Color Restar (const Color&,const Color&);  
std::string GetHtmlHex (const Color&);  
std::string GetHtmlRgb (std::string);  
void CrearSvgConTextoEscritoEnAltoContr(std::string, std::string, const Color&);  
bool IsIgual (const Color&, const Color&);  
void ImprimirColor (const Color&);  


**Modelos IPO de las funciones:**  

Color x Color -> MezclarDosColoresenPIguales -> Color  
Color x Color x N x N -> MezclarDosColoresProporcion -> Color  
Color -> GetComplementario -> Color  
Color x Color -> Sumar -> Color  
Color x Color -> Restar -> Color  
Color -> GetHtmlHex -> string (cadena)  
string (cadena) -> GetHtmlRgb -> string (cadena)  
string x string x string x Color -> CrearSvgConTextoEscritoEnAltoContr -> vacío  
Color x Color -> IsIgual -> bool  
Color -> ImprimirColor -> vacío  


**Definición matemática de algunas funciones:**  

![Funcion GetComplementario](https://github.com/closada/AED/blob/master/Imgs/GetComplementario.JPG)  

![Funcion IsIgual](https://github.com/closada/AED/blob/master/Imgs/IsIgual.JPG)  

**Pruebas:**  

assert (IsIgual(rojo,Sumar(rojo,rojo)));  
assert(IsIgual({255,0,255},Restar(amarillo,cyan)));  

assert (IsIgual(MezclarDosColoresenPIguales(negro,blanco),{127,127,127}));  
assert (IsIgual(MezclarDosColoresenPIguales(azul,amarillo),{127,127,127}));  

assert(IsIgual(MezclarDosColoresProporcion(azul,100,amarillo,100),{127,127,127}));  
assert (IsIgual(MezclarDosColoresProporcion(azul,80,amarillo,20), {25,25,102}));  

assert (IsIgual(GetComplementario(rojo), {0,255,255}));  
assert (IsIgual(GetComplementario(negro),blanco));  


assert( "#0000ff" == GetHtmlHex(azul));  
assert ("#ff0000" == GetHtmlHex(rojo));  
assert ("#000000" == GetHtmlHex(negro));  



assert("rgb(0,0,255)" == GetHtmlRgb(GetHtmlHex(azul)));  
assert("rgb(0,255,0)" == GetHtmlRgb(GetHtmlHex(verde)));  
assert("rgb(255,255,255)" == GetHtmlRgb(GetHtmlHex(blanco)));  

CrearSvgConTextoEscritoEnAltoContr("mensajever", "A ver si esto funciona bien!!",blanco);  
CrearSvgConTextoEscritoEnAltoContr("mensaje", "Veo todo bien! :)",amarillo);  

assert (not IsIgual(amarillo,negro));  
assert (IsIgual(blanco, {255,255,255}));  
