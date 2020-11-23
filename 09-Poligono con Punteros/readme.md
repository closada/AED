# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Lista Enlazada de Poligonos*

**Hipótesis del problema:**  

Generar un programa que reciba un flujo de datos de entrada (stream) compuesto por polígonos e imprima (o guarde) en otro flujo de datos de salida los poligonos cuyo perímetro sea mayor a 'X' (valor definido como variable externa modificable).

El flujo de datos de entrada recibe el Color del mismo (delimitado los tres valores de RED, GREEN y BLUE con comas) y por último los puntos cartesianos (delimitando sus valores con coma). El delimitador entre el color y los diversos puntos es el ESPACIO. El delimitador entre polígonos es el "*;*".

Primero, realizaré pruebas sobre las distintas funciones (u operaciones) definidas en el contrato (.h).  

**Definición Matemática de polígono:**  

![Funcion Poligono](https://github.com/closada/AED/blob/master/Imgs/POLIGONOV02.JPG) 

**Definición en C++:**  

struct Punto {  
   double x, y;  
};  

struct Color {uint8_t R,G,B;};  

struct Nodo {  
    Punto p;  
    Nodo* next{nullptr};  
};  


struct Poligono {  
    unsigned cant_puntos{0};  
    Nodo* primerNodo;  
    Color color;  
};  

**Conjunto de Operaciones:**  

El conjunto de operaciones son las funciones definidas en los prototipos (ver listapolig.md).    

**Conjunto de Valores:**  

Los valores que puede tomar este tipo de dato se componen en las combinaciones de números reales de los puntos, sin un máximo definido, y un color con un rango de 0 a 255.
