# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Flujo Poligonos*

**Hipótesis del problema:**  

Generar un programa que reciba un flujo de datos de entrada (stream) compuesto por polígonos y los imprima (o guarde) en otro flujo de datos de salida. En este caso, he dividido el programa en dos posibles soluciones:

* En primer caso, el flujo de datos de entrada recibe primero el Color del mismo (delimitado los tres valores de RED, GREEN y BLUE con comas), luego la cantidad de puntos y por último los puntos cartesianos mencionados (delimitando sus valores con coma). El delimitador entre el color, la cantiad de puntos y los puntos mismos es el ESPACIO. El delimitador entre polígonos es el *enter*. Este es el caso **CC**.

* En el segundo caso, el flujo de datos recibe los datos en el mismo orden, exceptuando la cantidad de puntos el cual NO lo define como un parámetro a tomar. El delimitador entre polígonos es el ";". Este caso se encuentran en la carpeta **SC**.

Tomaré como flujos de datos de entrada y salida los cin y cout de la librería *iostream* de C++ y para las pruebas los archivos TXT en la línea de comando con los operadores '>' y '<'.

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
