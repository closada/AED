# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Poligono*

**Hipótesis del problema:**  

Generar un tipo de dato Poligono que representa polígonos con color en el plano. Tomamos el mismo con máximo de 30 vértices -puntos-, siendo su máxima representación un Triacontagono. El color se define el formato RGB con valores de 0 a 255. Los puntos se definen como coordenadas cartesianas.


**Definición Matemática:**  

![Funcion Poligono](https://github.com/closada/AED/blob/master/Imgs/POLIGONOV02.JPG) 

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


**Conjunto de Operaciones:**  

El conjunto de operaciones son las funciones descriptas en el apartado Prototipo de funciones.  

**Conjunto de Valores:**  

Los valores que puede tomar este tipo de dato se componen en las combinaciones de números reales de los puntos, con un máximo de 30 de ellos y un color con un rango de 0 a 255.

**Prototipos de funciones:**  

double GetDistancia (Punto,Punto);  
void AddVertice (Poligono&, Punto);  
void SetVertice (Poligono&, Punto, unsigned); // Poligono, punto nuevo, posicion en array de poligono  
void RemoveVerticeEnd (Poligono&);  
Punto GetVertice (const Poligono&, unsigned); // devuelve el vertice en la posicion que se le pasa del punto, ejemplo punto pos 1 es at(0) en el poligono  
unsigned GetCantidadLados (const Poligono&);  
double GetPerimetro (const Poligono&);  
void CambiarColor (Poligono&, Color);   
bool IsIgualPunto (Punto, Punto);  
void DefPuntosPoligono (Poligono&,unsigned);   
void ImprimirPuntos (const Poligono&);  
double CalculoAnguloInteriorPoligono (const Poligono&);  


**Modelos IPO de las funciones:**  

Punto x Punto -> GetDistancia -> real  
Poligono x Punto -> AddVertice -> Poligono*  
Poligono x Punto x Natural -> SetVertice -> Poligono*  
Poligono -> RemoveVerticeEnd -> Poligono*  
Poligono x Natural -> GetVertice -> Punto  
Poligono -> GetCantidadLados -> natural  
Poligono -> GetPerimetro -> real  
Poligono x Color -> CambiarColor -> Poligono*  
Punto x Punto -> IsIgualPunto -> booleano  
Poligono x Natural -> DefPuntosPoligono -> Poligono*  
Poligono -> ImprimirPuntos -> vacío  
Poligono -> CalculoAnguloInteriorPoligono -> real  


**Definición matemática de algunas funciones:**  

![Funcion GetDistancia](https://github.com/closada/AED/blob/master/Imgs/GetDistancia.JPG)  

![Funcion GetCantidadLados](https://github.com/closada/AED/blob/master/Imgs/GetCantidadLados.JPG)  

![Funcion CalcularAnguloInteriorPoligono](https://github.com/closada/AED/blob/master/Imgs/CalculoAnguloInteriorPoligono.JPG)  


**Pruebas:**  


CambiarColor(p1,negro);  
assert (p1.color.R == 0);  
assert (p1.color.G == 0);  
assert (p1.color.B == 0);  

AddVertice(p1, {13,-2.3});  
assert (IsIgualPunto(GetVertice(p1,p1.cant_puntos),{13,-2.3}));  
assert (GetCantidadLados(p1) == 4);  

RemoveVerticeEnd(p1);  
assert (GetCantidadLados(p1) == 3);  
assert (IsIgualPunto(GetVertice(p1,p1.cant_puntos),{-2,2}));  


assert (60 == CalculoAnguloInteriorPoligono(p1));  

assert (9.7 > GetPerimetro(p1) and GetPerimetro(p1) > 9.6);  

SetVertice(p1,{3,-5},2);  
assert (IsIgualPunto(GetVertice(p1,2),{3,-5}));  
