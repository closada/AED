# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Triangulo*

**Léxico:**  

![Funcion Triangulo](https://github.com/closada/AED/blob/master/Imgs/TRIANGULO.JPG)  

**Definición en C++:**  

struct Punto {  
   std::array <double,2> Coord;   
};  
struct Triangulo {  
    std::array <Punto,3> Puntos;  
    std::array<unsigned,3> Color; //color designado con formato RGB (--,--,--) numeros del 0 al 255  
};  

**Prototipos de funciones:**  

void CambiarColor (Triangulo&, unsigned, unsigned, unsigned);  
void DefPuntos (Triangulo&, const Punto&,const Punto&,const Punto&);  
void ImprimirPuntos (const Triangulo&);  
double GetPerimetro (const Triangulo&);  
void CambiarPuntoEnPos (Triangulo&,Punto, unsigned); // triangulo, nuevo punto, posicion punto a reemplazar en el array Puntos  
double GetArea (const Triangulo&);  
bool IsEscaleno (const Triangulo&);  
bool IsEquilatero (const Triangulo&);  
bool IsIsosceles (const Triangulo&);  


**Pruebas:**  

CambiarColor(t1, 127,56,0);  
assert (t1.Color.at(0) == 127);  
assert (t1.Color.at(1) == 56);  
assert (t1.Color.at(2) == 0);  

DefPuntos(t,{{2,1}},{{-3,0}},{{0,0}});  
assert(t.Puntos.at(0).Coord.at(0) == 2);  
assert(t.Puntos.at(0).Coord.at(1) == 1);  
assert(t.Puntos.at(1).Coord.at(0) == -3);  
assert(t.Puntos.at(1).Coord.at(1) == 0);  
assert(t.Puntos.at(2).Coord.at(0) == 0);  
assert(t.Puntos.at(2).Coord.at(1) == 0);  


DefPuntos(t1,{{1,3}},{{3,-1}},{{4,2}});  

assert (not IsEscaleno(t1));  
assert (IsIsosceles(t1));  

