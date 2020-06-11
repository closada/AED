# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### Función Celsius
#### *Dominio del problema*  

**Hipótesis:**  
Ingresa a la función un año (del tipo unsigned) y la misma devolverá un tipo de dato booleano que afirma o niega si el año mencionado es bisiesto.
Tomar en cuenta que el año debe ser mayor o igual a 1582; caso contrario el booleano devolverá 'false'.  

**Modelo IPO:**  

![IPO BISIESTO](https://github.com/closada/AED/blob/master/Imgs/IPOBISIESTO.JPG)  

**Léxico:**  

![Funcion Binario](https://github.com/closada/AED/blob/master/Imgs/BISIESTO.JPG)  

#### *Dominio del problema*  

**Pruebas:**  
assert (IsBisiesto(2020));  
assert (IsBisiesto(2000));  
assert (IsBisiesto(1600));  
assert (IsBisiesto(2400));  
assert (IsBisiesto(2016));  

assert (not IsBisiesto(1582));  
assert (not IsBisiesto(2021));  
assert (not IsBisiesto(1700));  
assert (not IsBisiesto(1800));  
assert (not IsBisiesto(1900));  
assert (not IsBisiesto(2100));  
  

**Prototipo:**  

bool IsBisiesto (unsigned);  

**Definición:**  
bool IsBisiesto (unsigned anio) {return 
anio>=1582 and anio%4==0 and(anio%100!=0 or (anio%100==0 and anio%400==0));}  

**Definición:**  

![Arbol de Expresion](https://github.com/closada/AED/blob/master/Imgs/arbol_expresion_bisiesto.JPG)  

