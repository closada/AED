# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Punto*

**Hipótesis del problema:**  

Generar un tipo de dato Punto compuesto por lo ejes cartesianos (los mismos del tipo real) x e y.

**Léxico:**  

![Funcion Punto](https://github.com/closada/AED/blob/master/Imgs/PUNTO.JPG)  

**Definición en C++:**  

struct Punto {  
   double x, y;  
};  

**Conjunto de Operaciones:**  

El conjunto de operaciones son las funciones descriptas en el apartado Prototipo de funciones.  

**Conjunto de Valores:**  

Los valores que puede tomar este tipo son todos los reales que pueden ser los componentes cartesianos x e y; es decir valores "infinitos".


**Prototipos de funciones:**  

void ImprimirPunto(Punto);  
Punto GetPunto(double,double);  
Cuadrante GetCuadrante (Punto);  
Eje GetEje (Punto);  
bool IsIgual (Punto, Punto);  
double GetDistancia (Punto,Punto);  
double GetDistanciaAlOrigen(Punto);  
void Mover (Punto&, double, double);  

**Modelos IPO de las funciones:**  
Punto -> ImprimirPunto -> vacío  
real x real -> GetPunto -> Punto  
Punto -> GetCuadrante -> Cuadrante*(enumeración)  
Punto -> GetEje -> Eje*(enumeración)  
Punto x punto -> IsIgual -> booleano  
Punto x Punto -> GetDistancia -> real (double)  
Punto -> GetDistanciaAlOrigen -> real (double)  
Punto x real x real -> Mover -> Punto*  

NOTA: Punto* significa que el Punto que ingresa a la funcion sale modificado; es decir, en estos casos Punto es parámetro inout.  


**Definición matemática de algunas funciones:**  

![Funcion GetDistancia](https://github.com/closada/AED/blob/master/Imgs/GetDistancia.JPG)  

![Funcion IsIgual](https://github.com/closada/AED/blob/master/Imgs/IsIgualPunto.JPG)  


**Pruebas:**  

assert  (IsIgual(GetPunto(2,2),p1));  
assert  (IsIgual(GetPunto(-5,2.2),p2));  

assert (9 == GetDistancia({-4,0},{5,0}));  
assert (0 == GetDistancia({7,-5},{7,-5}));  

assert (4 == GetDistanciaAlOrigen({-4,0}));  
assert (5 == GetDistanciaAlOrigen({0,5}));  

assert (IsIgual({2,2},{2,2}));  

Mover(p1,-1,5);  
Mover(p2,0,0);  

assert (p1.x == 1);  
assert (p1.y == 7);  
assert (p2.x == -5);  
assert (p2.y == 2.2);  

assert (Cuadrante::c1 == GetCuadrante({1,2}));  
assert (Cuadrante::c2 == GetCuadrante({-3,2}));  
assert (Cuadrante::c3 == GetCuadrante({-3,-11}));  
assert (Cuadrante::c4 == GetCuadrante({3,-22}));  
assert (Cuadrante::NC == GetCuadrante({0,2}));  

assert (Eje::EX == GetEje({0,-3.5}));  
assert (Eje::EY == GetEje({2,0}));  
assert (Eje::ORIGEN == GetEje({0,0}));  
