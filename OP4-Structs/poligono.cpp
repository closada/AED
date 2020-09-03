/* Camila Victoria Losada
20200831
Tipo de dato Poligono */

#include <iostream>
#include <array>

struct Punto {
   std::array <double,2> Coord; 
};
struct Poligono {
    unsigned cant_puntos;
    std::array <Punto,30> Puntos; //como maximo, puede tratarse de un Triacontagono
    std::array<unsigned,3> Color; //color designado con formato RGB (--,--,--) numeros del 0 al 255
};

void AgregarPuntoalFinal (Poligono&);
void ModifPuntoenPos (Poligono&, Punto, unsigned); // Poligono, punto nuevo, posicion en array de poligono
void SacarPuntoDelFinal (Poligono&);
void CambiarColor (Poligono&);
void DefPuntos (Poligono&);
void ImprimirPuntos (const Poligono&);
double CalculoAnguloInteriorPoligono (const Poligono&);

int main () {
Poligono p1;

DefPuntos(p1);
CambiarColor(p1);
ImprimirPuntos(p1);
AgregarPuntoalFinal(p1);
ImprimirPuntos(p1);
SacarPuntoDelFinal(p1);
ImprimirPuntos(p1);
std::cout << CalculoAnguloInteriorPoligono(p1);


}

void AgregarPuntoalFinal (Poligono& pol) {
std::cout << "Escriba el valor de x del punto: ";
std::cin >> pol.Puntos.at(pol.cant_puntos).Coord.at(0);
std::cout << "Escriba el valor de y del punto: ";
std::cin >> pol.Puntos.at(pol.cant_puntos).Coord.at(1);
pol.cant_puntos ++;
};

void SacarPuntoDelFinal (Poligono& pol){

pol.Puntos.at(pol.cant_puntos - 1).Coord.at(0) = 0;
pol.Puntos.at(pol.cant_puntos - 1).Coord.at(1) = 0;
pol.cant_puntos --;

};

void DefPuntos (Poligono& pol) {
std::cout << "Cantidad de puntos del poligono: ";
std::cin >> pol.cant_puntos;
for (unsigned i=0;i<pol.cant_puntos; i++)
{
std::cout << "Escriba el valor de x del punto " << i + 1 << ": ";
std::cin >> pol.Puntos.at(i).Coord.at(0);
std::cout << "Escriba el valor de y del punto " << i + 1 << ": ";
std::cin >> pol.Puntos.at(i).Coord.at(1);
};
};

void ImprimirPuntos (const Poligono& pol) {
for (unsigned i=0;i<pol.cant_puntos; i++)
{
std::cout << "Punto " << i + 1 <<": (" << pol.Puntos.at(i).Coord.at(0) << "," << pol.Puntos.at(i).Coord.at(1) << ") , ";
};
}


void ModifPuntoenPos (Poligono& pol, Punto p, unsigned x){
pol.Puntos.at(x).Coord.at(0) = p.Coord.at(0);
pol.Puntos.at(x).Coord.at(1) = p.Coord.at(1);
};

void CambiarColor (Poligono& pol){
std::cout << "Escriba el valor de RED: ";
std::cin >> pol.Color.at(0);
std::cout << "Escriba el valor de GREEN: ";
std::cin >> pol.Color.at(1);
std::cout << "Escriba el valor de BLUE: ";
std::cin >> pol.Color.at(2);
};

double CalculoAnguloInteriorPoligono (const Poligono& pol){

return 180 - (360 / pol.cant_puntos);
};