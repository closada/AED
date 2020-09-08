# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Punto*

**Léxico:**  

![Funcion Punto](https://github.com/closada/AED/blob/master/Imgs/PUNTO.JPG)  

**Definición en C++:**  

struct Punto {  
   double x, y;  
};  

**Prototipos de funciones:**  

void ImprimirPunto(Punto);  
Punto GetPunto(double,double);  
Cuadrante GetCuadrante (Punto);  
bool IsIgual (Punto, Punto);  
double GetDistancia (Punto,Punto);  
double GetDistanciaAlOrigen(Punto);  
void Mover (Punto&, double, double);  


**Pruebas:**  
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
assert (Cuadrante::origen == GetCuadrante({0,0}));  
