# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### Función valor Absoluto
**Léxico:**  

![Funcion Absoluto](https://github.com/closada/AED/blob/master/Imgs/ABS.JPG)  

**Prueba:**  

assert(3 == Abs(3));  
assert (3.75 == Abs(-3.75));  

**Prototipo:**  
double Abs (double);  

**Definición:**  
double Abs(double x){return x<0 ? -x : x;}

### Función mínimo entre dos valores

**Léxico:**  

![Funcion Minimo](https://github.com/closada/AED/blob/master/Imgs/MIN.JPG)  


**Prueba:**  
assert(4 == Min(5,4));  
assert(-3.4 == Min(-3.4,1));  
assert(2.4554 == Min(2.4554,2.5));  

**Prototipo:**  
double Min (double, double);

**Definición:**  
double Min(double x, double y){return x<y ? x : y;}

### Función 3

**Léxico:**  

![Funcion 3](https://github.com/closada/AED/blob/master/Imgs/F3.JPG)  


**Prueba:**  
assert(-3 == funcion(3));  
assert(3.1 == funcion(3.1));  
assert(3 == funcion(-3));  
assert(4.1 == funcion(4.1));  
assert(2 == funcion(-2));  
assert(-1 == funcion(1));  

**Prototipo:**  
double funcion (double);

**Definición:**  
double funcion(double x){return x>=-3 and x<=3 ? -x : x;}  
