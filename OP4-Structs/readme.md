# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Punto*

**Léxico:**  

![Funcion Punto](https://github.com/closada/AED/blob/master/Imgs/PUNTO.JPG)  

**Definición en C++:**  

struct Punto {double x,y;};  


### *Definicion Circulo*

**Léxico:**  

![Funcion Circulo](https://github.com/closada/AED/blob/master/Imgs/CIRCULO.JPG)  

**Definición en C++:**  

struct Punto {double x,y;}; /*ESTRUCTURA*/  

struct Circulo {double radio; Punto centro;}; /*ESTRUCTURA*/   


### *Definicion Triangulo*

**Léxico:**  

![Funcion Triangulo](https://github.com/closada/AED/blob/master/Imgs/TRIANGULO.JPG)  

**Definiciones en C++:**  

struct Punto {double x,y;}; /*ESTRUCTURA*/  
struct Triangulo {Punto p1,p2,p3;}; /*TUPLA*/  
using TipoTriangulo = std::array<Punto,3>; /*ARRAY TRIANGULO */  


### *Definicion Rectangulo*

**Léxico:**  

![Funcion Rectangulo](https://github.com/closada/AED/blob/master/Imgs/RECTANGULO.JPG)  

**Definiciones en C++:**  

struct Punto {double x,y;}; /*ESTRUCTURA*/  
struct Rv01 {Punto p1,p2,p3,p4;}; /*TUPLA*/  
using Rv02 = std::array<Punto,4>; /*ARRAY Rectangulo*/   
struct Rv03 {double base, altura;}; /* ESTRUCTURA con base y altura */  
