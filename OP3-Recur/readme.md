# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Función Div*
*Dominio del problema*  

**Modelo IPO:**  

![Funcion CELSIUS](https://github.com/closada/AED/blob/master/Imgs/CELSIUS.JPG)  

*Dominio de la solucion*  

**Léxico:**  

![Funcion CELSIUS](https://github.com/closada/AED/blob/master/Imgs/CELSIUS.JPG)  

**Pruebas:**  

assert (9 == Div(45,5));  
assert (14 == Div(100,7));  
assert (0 == Div(1,2));  
assert (35 == Div(425,12));  
assert (35 == Div(428,12));  

**Prototipos:**  

unsigned Div (unsigned, unsigned);  

**Definiciones:**  

unsigned Div (unsigned Dividendo, unsigned Divisor){  
return Dividendo < Divisor ? 0:  
Dividendo - Divisor <= 0 ? 1:  
Div(Dividendo - Divisor, Divisor)+1;}


### *Función Mcd*
*Dominio del problema*  

**Modelo IPO:**  

![Funcion CELSIUS](https://github.com/closada/AED/blob/master/Imgs/CELSIUS.JPG)  

*Dominio de la solucion*  

**Léxico:**  

![Funcion CELSIUS](https://github.com/closada/AED/blob/master/Imgs/CELSIUS.JPG)  

**Pruebas:**  

aassert (6 == Mcd(270,192));  
assert (14 == Mcd(42,56));  
assert (10 == Mcd(20,10));  
assert (20 == Mcd(40,60));  
assert (1 ==  Mcd(457,1014));  
 

**Prototipos:**  

unsigned Mcd (unsigned, unsigned);  

**Definiciones:**  
unsigned Mcd (unsigned a, unsigned b){  
return  
a == 0 ? b:  
b== 0 ? a:  
Mcd(b, a%b);}  

### *Función Factorial*
*Dominio del problema*  

**Modelo IPO:**  

![Funcion CELSIUS](https://github.com/closada/AED/blob/master/Imgs/CELSIUS.JPG)  

*Dominio de la solucion*  

**Léxico:**  

![Funcion CELSIUS](https://github.com/closada/AED/blob/master/Imgs/CELSIUS.JPG)  

**Pruebas:**  

assert (1 == Factorial(1));  
assert (2 == Factorial(2));  
assert (120 == Factorial(5));  
assert (3628800 == Factorial(10));  
assert (39916800 == Factorial(11));  
assert (479001600 == Factorial(12));  

**Prototipos:**  

unsigned Factorial (unsigned);  

**Definiciones:**  

unsigned Factorial (unsigned n){return  
n <2 ? 1 :  
n * Factorial(n-1);}  

### *Función Fibonacci*
*Dominio del problema*  

**Modelo IPO:**  

![Funcion CELSIUS](https://github.com/closada/AED/blob/master/Imgs/CELSIUS.JPG)  

*Dominio de la solucion*  

**Léxico:**  

![Funcion CELSIUS](https://github.com/closada/AED/blob/master/Imgs/CELSIUS.JPG)  

**Pruebas:**  

assert (1 == Fibonacci(1));  
assert (1 == Fibonacci(2));  
assert (8 == Fibonacci(6));  
assert (21 == Fibonacci(8));  
assert (55 == Fibonacci(10));  
assert (233 == Fibonacci(13));  

**Prototipos:**  

unsigned Fibonacci (unsigned);  

**Definiciones:**  

unsigned Fibonacci (unsigned n){return  
n <2 ? n :  
Fibonacci(n-1) + Fibonacci(n-2);}

