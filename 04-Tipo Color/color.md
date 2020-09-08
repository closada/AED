# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Color*

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


**Pruebas:**  

pruebas = MezclarDosColoresenPIguales(azul,amarillo);  
assert (pruebas.R == 127);  
assert (pruebas.G == 127);  
assert (pruebas.B == 127);  
pruebas = MezclarDosColoresProporcion(azul,100,amarillo,100);  
assert (pruebas.R == 127);  
assert (pruebas.G == 127);  
assert (pruebas.B == 127);  
pruebas = MezclarDosColoresProporcion(azul,80,amarillo,20);  
assert (pruebas.R == 25);  
assert (pruebas.G == 25);  
assert (pruebas.B == 102);  
pruebas = GetComplementario(rojo);  
assert (pruebas.R == 0);  
assert (pruebas.G == 255);  
assert (pruebas.B == 255);  

//std:: cout << GetHtmlHex (rojo);  
assert( "#0000FF" == GetHtmlHex(azul));  
assert ("#FF0000" == GetHtmlHex(rojo));  

//std:: cout << GetHtmlRgb (GetHtmlHex(azul));  
assert("rgb(0,0,255)" == GetHtmlRgb(GetHtmlHex(azul)));  
assert("rgb(0,255,0)" == GetHtmlRgb(GetHtmlHex(verde)));  

CrearSvgConTextoEscritoEnAltoContr("mensajever", "A ver si esto funciona bien!!",blanco);  
CrearSvgConTextoEscritoEnAltoContr("mensaje", "Veo todo bien! :)",amarillo);  

assert (not IsIgual(amarillo,negro));  
assert (IsIgual(blanco, {255,255,255}));  
