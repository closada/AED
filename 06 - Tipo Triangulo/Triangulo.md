# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Triangulo*

**Hipótesis del problema:**  

Generar un tipo de dato Triangulo conformado por tres puntos donde el mismo posee un color (en formato RGB y con valores de 0 a 255). Los puntos son cartesianos y pueden tomar cualquier valor (real).

**Léxico:**  

![Funcion Triangulo](https://github.com/closada/AED/blob/master/Imgs/TRIANGULOV02.JPG)  

**Definición en C++:**  

struct Punto {  
   double x, y;  
};  

struct Color {uint8_t R,G,B;};  

struct Triangulo {  
    Punto a,b,c;  
    Color color; //color designado con formato RGB (--,--,--) numeros del 0 al 255  

};  

enum struct TipoTriangulo {Escaleno, Isosceles, Equilatero, otro};  

**Conjunto de Operaciones:**  

El conjunto de operaciones son las funciones descriptas en el apartado Prototipo de funciones.  

**Conjunto de Valores:**  

Los valores que puede tomar son todas las combinaciones posibles entre los tres puntos mencionados y su color; dichos puntos individualmente considerados como una combinación cartesiana de valores reales, es decir, "infinitos" (en informática, los tipos de dato reales -double- poseen un máximo de representación).

**Prototipos de funciones:**  

double GetDistancia (Punto,Punto);  
void CambiarColor (Triangulo&, const Color&);  
void DefPuntos (Triangulo&, const Punto&,const Punto&,const Punto&);  
std::string ImprimirPuntos (const Triangulo&);  
double GetPerimetro (const Triangulo&);  
void CambiarPuntoEnPos (Triangulo&,Punto, unsigned); // triangulo, nuevo punto, posicion punto a reemplazar en el array Puntos  
double GetArea (const Triangulo&);  
bool IsEscaleno (const Triangulo&);  
bool IsEquilatero (const Triangulo&);  
bool IsIsosceles (const Triangulo&);  
TipoTriangulo GetTipo (const Triangulo&);  
Punto GetCentro (const Triangulo&);  

**Modelos IPO de las funciones:**  

Punto x Punto -> GetDistancia -> real  
Triangulo x Color -> CambiarColor -> Triangulo*  
Triangulo x Punto x Punto x Punto -> DefPuntos -> Triangulo*  
Triangulo -> ImprimirPuntos -> string (cadena)  
Triangulo -> GetPerimetro -> real  
Triangulo x Punto x Natural -> CambiarPuntoEnPos -> Triangulo*  
Triangulo -> GetArea -> real  
Triangulo -> IsEscaleno -> booleano  
Triangulo -> IsEquilatero -> booleano  
Triangulo -> IsIsosceles -> booleano  
Triangulo -> GetTipo -> TipoTriangulo  
Triangulo -> GetCentro -> Punto  

NOTA: Triangulo* significa que el Triangulo que ingresa a la funcion sale modificado; es decir, en estos casos Triangulo es parámetro inout.  


**Definición matemática de algunas funciones:**  

![Funcion GetDistancia](https://github.com/closada/AED/blob/master/Imgs/GetDistancia.JPG)  

![Funcion GetPerimetro](https://github.com/closada/AED/blob/master/Imgs/GetPerimetro.JPG)  

![Funcion IsEquilatero](https://github.com/closada/AED/blob/master/Imgs/IsEquilatero.JPG)  


**Pruebas:**  

CambiarColor(t1,blanco);  
assert (t1.color.R == 255);  
assert (t1.color.G == 255);  
assert (t1.color.B == 255);  

DefPuntos(t,{2,1},{-3,0},{0,0});  
assert(t.a.x == 2);  
assert(t.a.y == 1);  
assert(t.b.x == -3);  
assert(t.b.y == 0);  
assert(t.c.x == 0);  
assert(t.c.y == 0);  

assert (3.9 <= GetArea(t1) and GetArea(t1) <= 4.1);  

DefPuntos(t1,{1,3},{3,-1},{4,2});  

assert (10.7 <= GetPerimetro(t1) and GetPerimetro(t1) <= 10.8);  

assert (not IsEscaleno(t1));  
assert (IsIsosceles(t1));  
assert (IsEscaleno(t));  

assert (TipoTriangulo::Isosceles == GetTipo(t1));  
assert (TipoTriangulo::Escaleno == GetTipo(t));  


prueba = GetCentro(t1);  
assert (prueba.x == 8);  
assert (prueba.y == 4);  

prueba = GetCentro(t);  
assert(prueba.x == -1);  
assert(prueba.y == 1);  
