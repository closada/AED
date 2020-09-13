/* Camila Victoria Losada
20200831
Tipo de dato Color */


#include <iostream>

struct Color {uint8_t R,G,B;};

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


Color const rojo {255,0,0}, azul{0,0,255}, verde{0,255,0}, cyan{0,255,255}, magenta{255,0,255}, amarillo{255,255,0};
Color const negro = Restar(azul,azul);
Color const blanco = Sumar(Sumar(rojo,verde),azul);
