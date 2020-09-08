/* Camila Victoria Losada
20200831
Tipo de dato Color */


#include <iostream>
#include <array>
#include <cassert>
#include <cstdint>
#include <fstream>

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


Color const rojo {255,0,0}, azul{0,0,255}, verde{0,255,0}, cyan{0,255,255}, magenta{255,0,255}, amarillo{255,255,0}, negro{0,0,0}, blanco{255,255,255};

int main () {

std::string hexa;
Color pruebas;
//ImprimirColor(MezclarDosColoresenPIguales(azul,amarillo));
//ImprimirColor(MezclarDosColoresProporcion(azul,80,amarillo,20));
//ImprimirColor(GetComplementario(rojo));

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
}


Color MezclarDosColoresenPIguales (const Color& col1,const Color& col2){
Color Final;
Final.R = (col1.R + col2.R) / 2;
Final.G = (col1.G + col2.G) / 2;
Final.B = (col1.B + col2.B) / 2;
return Final;
};

void ImprimirColor (const Color& c){
std::cout << "RGB(" << c.R << "," << c.G << "," << c.B << ")\n";
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
c1.R - c2.R > 255 ? Resta.R = 255 : Resta.R = c1.R - c2.R;
c1.G - c2.G > 255 ? Resta.G = 255 : Resta.G = c1.G - c2.G;
c1.B - c2.B > 255 ? Resta.B = 255 : Resta.B = c1.B - c2.B;
return Resta;
};

std::string GetHtmlHex (const Color& c1){
char hexa1[3], hexa2[3],hexa3[3];


sprintf(hexa1,"%.2X",c1.R);
sprintf(hexa2,"%.2X",c1.G);
sprintf(hexa3,"%.2X",c1.B);


return "#" + std::string(hexa1) + std::string(hexa2) + std::string(hexa3);
};

std::string GetHtmlRgb (std::string s){
int hexa1,hexa2,hexa3;

hexa1 = stoi(s.substr(1,2),0,16);
hexa2 = stoi(s.substr(3,2),0,16);
hexa3 = stoi(s.substr(5,2),0,16);

return "rgb(" + std::to_string(hexa1) + "," + std::to_string(hexa2) + "," + std::to_string(hexa3) + ")";
};

void CrearSvgConTextoEscritoEnAltoContr(std::string nombre, std::string mensaje, const Color& c){
std::ofstream file;
file.open("C:/CAMILA/UTN/AED 2020/TPS/" + nombre + ".svg");
file << "<svg xmlns='http://www.w3.org/2000/svg'>\n";
file << "<rect x='0' y='0' height='100' width='500' style='fill: " << GetHtmlHex(GetComplementario(c)) << "'/> \n";
file << "<text x='5' y='18' style='fill: " << GetHtmlRgb(GetHtmlHex(c)) << ";background-color: "<<GetHtmlHex(GetComplementario(c)) <<"#ff0000'>\n";
file << mensaje << "\n";
file << "</text>\n</svg>\n";
file.close();
};

bool IsIgual (const Color& c1, const Color& c2){
return (c1.R == c2.R) and (c1.G == c2.G) and (c1.B == c2.B);
}