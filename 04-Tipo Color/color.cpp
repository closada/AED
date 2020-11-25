#include <iostream>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "color.h"

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
std::cout << "RGB(" << (unsigned) c.R << "," << (unsigned) c.G << "," << (unsigned) c.B << ")\n";
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
ver << "#" << std::hex <<  std::setfill('0') << std::setw(2) << (unsigned) c1.R  <<  std::setfill('0') << std::setw(2) << (unsigned) c1.G <<  std::setfill('0') << std::setw(2) << (unsigned)c1.B ;
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