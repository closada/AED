
#include "color.h"
#include <cassert>
#include <iostream>

int main () {
assert (IsIgual(rojo,Sumar(rojo,rojo)));
assert(IsIgual({255,0,255},Restar(amarillo,cyan)));

assert (IsIgual(MezclarDosColoresenPIguales(negro,blanco),{127,127,127}));
assert (IsIgual(MezclarDosColoresenPIguales(azul,amarillo),{127,127,127}));

assert(IsIgual(MezclarDosColoresProporcion(azul,100,amarillo,100),{127,127,127}));
assert (IsIgual(MezclarDosColoresProporcion(azul,80,amarillo,20), {25,25,102}));

assert (IsIgual(GetComplementario(rojo), {0,255,255}));
assert (IsIgual(GetComplementario(negro),blanco));

//std::cout << GetHtmlHex(verde) << "\n";

assert( "#0000ff" == GetHtmlHex(azul));
assert ("#ff0000" == GetHtmlHex(rojo));
assert ("#000000" == GetHtmlHex(negro));


//std::cout << GetHtmlRgb(GetHtmlHex(verde)) << "\n";

assert("rgb(0,0,255)" == GetHtmlRgb(GetHtmlHex(azul)));
assert("rgb(0,255,0)" == GetHtmlRgb(GetHtmlHex(verde)));
assert("rgb(255,255,255)" == GetHtmlRgb(GetHtmlHex(blanco)));

CrearSvgConTextoEscritoEnAltoContr("mensajever", "A ver si esto funciona bien!!",blanco);
CrearSvgConTextoEscritoEnAltoContr("mensaje", "Veo todo bien! :)",amarillo);

assert (not IsIgual(amarillo,negro));
assert (IsIgual(blanco, {255,255,255}));

}
