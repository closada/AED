# Camila Victoria Losada - Legajo 167356-7
## Compilador usado: g++
### *Definicion Color*

**Definición en C++:**  

struct Color {std::array <unsigned,3> RGB;};  


**Conjunto de Operaciones:**  

El conjunto de operaciones son las funciones descriptas en el apartado Prototipo de funciones.  

**Conjunto de Valores:**  

Los valores que puede tomar este tipo son en formato (..,..,..); es decir, cada color posee tres valores ENTEROS que componen RED, GREEN y BLUE y estos
pueden tomar un valor en el rango de 0 a 255.  

**Prototipos de funciones:**  

Color MezclarDosColoresenPIguales (const Color&,const Color&);  
Color MezclarDosColoresProporcion (const Color&, unsigned, const Color&, unsigned); // se asume los unsigned son las proporciones  
Color GetComplementario (const Color&);  
void ImprimirColor (const Color&);  

**Pruebas:**  

pruebas = MezclarDosColoresenPIguales(azul,amarillo);  
assert (pruebas.RGB.at(0) == 127);  
assert (pruebas.RGB.at(1) == 127);  
assert (pruebas.RGB.at(2) == 127);  
pruebas = MezclarDosColoresProporcion(azul,100,amarillo,100);  
assert (pruebas.RGB.at(0) == 127);  
assert (pruebas.RGB.at(1) == 127);  
assert (pruebas.RGB.at(2) == 127);  
pruebas = MezclarDosColoresProporcion(azul,80,amarillo,20);  
assert (pruebas.RGB.at(0) == 25);  
assert (pruebas.RGB.at(1) == 25);  
assert (pruebas.RGB.at(2) == 102);  
pruebas = GetComplementario(rojo);  
assert (pruebas.RGB.at(0) == 0);  
assert (pruebas.RGB.at(1) == 255);  
assert (pruebas.RGB.at(2) == 255);  
