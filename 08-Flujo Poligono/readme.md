# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Flujo Poligonos*

**Hipótesis del problema:**  

Generar un programa que reciba un flujo de datos de entrada (stream) compuesto por polígonos e imprima (o guarde) en otro flujo de datos de salida los poligonos cuyo perimetro sea mayor a 'X' (valor definido como variable global modificable).

El flujo de datos de entrada recibe el Color del mismo (delimitado los tres valores de RED, GREEN y BLUE con comas) y por último los puntos cartesianos (delimitando sus valores con coma). El delimitador entre el color y los diversos puntos es el ESPACIO. El delimitador entre polígonos es el "*;*".


**Definición Matemática de polígono:**  

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

El conjunto de operaciones son la lectura y escritura de los poligonos.  

**Conjunto de Valores:**  

Los valores que puede tomar este tipo de dato se componen en las combinaciones de números reales de los puntos, con un máximo de 30 de ellos y un color con un rango de 0 a 255.
