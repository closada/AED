# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Poligono*

**Definición Matemática:**  

![Funcion Poligono](https://github.com/closada/AED/blob/master/Imgs/POLIGONO.JPG) 

**Definición en C++:**  

struct Punto {  
   double x, y;  
};  

struct Color {uint8_t R,G,B;};  

struct Poligono {  
    unsigned cant_puntos;  
    std::array <Punto,30> Puntos; //como maximo, puede tratarse de un Triacontagono  
    Color color;  
};  


**Prototipos de funciones:**  

double GetDistancia (Punto,Punto);  
void AddVertice (Poligono&, Punto);  
void SetVertice (Poligono&, Punto, unsigned); // Poligono, punto nuevo, posicion en array de poligono  
void RemoveVerticeEnd (Poligono&);  
Punto GetVertice (const Poligono&, unsigned); // devuelve el vertice en la posicion que se le pasa del punto, ejemplo punto pos 1 es at(0) en el poligono  
unsigned GetCantidadLados (const Poligono&);  
double GetPerimetro (const Poligono&);  
void CambiarColor (Poligono&, Color);   

void DefPuntosPoligono (Poligono&,unsigned);   
void ImprimirPuntos (const Poligono&);  
double CalculoAnguloInteriorPoligono (const Poligono&);  


**Pruebas:**  

CambiarColor(p1,negro);  
assert (p1.color.R == 0);  
assert (p1.color.G == 0);  
assert (p1.color.B == 0);  

AddVertice(p1, {13,-2.3});  
assert (GetCantidadLados(p1) == 4);  
assert (p1.Puntos.at(p1.cant_puntos - 1).x == 13);  
assert (p1.Puntos.at(p1.cant_puntos - 1).y == -2.3);  

RemoveVerticeEnd(p1);  
assert (GetCantidadLados(p1) == 3);  
assert (p1.Puntos.at(p1.cant_puntos - 1).x == -2);  
assert (p1.Puntos.at(p1.cant_puntos - 1).y == 2);  

assert (60 == CalculoAnguloInteriorPoligono(p1));  

assert (9.7 > GetPerimetro(p1) and GetPerimetro(p1) > 9.6);  

SetVertice(p1,{3,-5},2);  
assert(p1.Puntos.at(1).x == 3);  
assert(p1.Puntos.at(1).y == -5);  

assert (GetVertice(p1,1).x == 2);  
assert (GetVertice(p1,1).y == 2);  
