/* Camila Victoria Losada
20200831
Tipo de dato Color */


#include <iostream>
#include <array>
#include <cassert>

struct Color {std::array <unsigned,3> RGB;};
Color MezclarDosColoresenPIguales (const Color&,const Color&);
Color MezclarDosColoresProporcion (const Color&, unsigned, const Color&, unsigned); // se asume los unsigned son las proporciones
Color GetComplementario (const Color&);
void ImprimirColor (const Color&);

int main () {
Color const rojo {{255,0,0}}, azul{{0,0,255}}, verde{{0,255,0}}, cyan{{0,255,255}}, magenta{{255,0,255}}, amarillo{{255,255,0}}, negro{{0,0,0}}, blanco{{255,255,255}};
std::string hexa;
Color pruebas;
//ImprimirColor(MezclarDosColoresenPIguales(azul,amarillo));
//ImprimirColor(MezclarDosColoresProporcion(azul,80,amarillo,20));
//ImprimirColor(GetComplementario(rojo));

pruebas = MezclarDosColoresenPIguales(azul,amarillo);
assert (pruebas.RGB.at(0) == 127);
assert (pruebas.RGB.at(1) == 127);
assert (pruebas.RGB.at(2) == 127);
pruebas = MezclarDosColoresProporcion(azul,100,amarillo,100);
assert (pruebas.RGB.at(0) == 127);
assert (pruebas.RGB.at(1) == 127);
assert (pruebas.RGB.at(2) == 127);
pruebas = MezclarDosColoresProporcion(azul,80,amarillo,20);
assert (pruebas.RGB.at(0) == 25);
assert (pruebas.RGB.at(1) == 25);
assert (pruebas.RGB.at(2) == 102);
pruebas = GetComplementario(rojo);
assert (pruebas.RGB.at(0) == 0);
assert (pruebas.RGB.at(1) == 255);
assert (pruebas.RGB.at(2) == 255);
}

Color MezclarDosColoresenPIguales (const Color& col1,const Color& col2){
Color Final;
Final.RGB.at(0) = (col1.RGB.at(0) + col2.RGB.at(0)) / 2;
Final.RGB.at(1) = (col1.RGB.at(1) + col2.RGB.at(1)) / 2;
Final.RGB.at(2) = (col1.RGB.at(2) + col2.RGB.at(2)) / 2;
return Final;
};

void ImprimirColor (const Color& c){
std::cout << "RGB(" << c.RGB.at(0) << "," << c.RGB.at(1) << "," << c.RGB.at(2) << ")\n";
};

Color MezclarDosColoresProporcion (const Color& c1, unsigned p1, const Color& c2, unsigned p2){
Color Final;
Final.RGB.at(0) = ((p1*c1.RGB.at(0)/100) + (p2*c2.RGB.at(0)/100)) / 2;
Final.RGB.at(1) = ((p1*c1.RGB.at(1)/100) + (p2*c2.RGB.at(1)/100)) / 2;
Final.RGB.at(2) = ((p1*c1.RGB.at(2)/100) + (p2*c2.RGB.at(2)/100)) / 2;
return Final;
};

Color GetComplementario (const Color& c){
Color comp;
comp.RGB.at(0) = 255 - c.RGB.at(0);
comp.RGB.at(1) = 255 - c.RGB.at(1);
comp.RGB.at(2) = 255 - c.RGB.at(2);
return comp;
};
