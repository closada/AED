/* Camila Victoria Losada
20200518
Tipos de Datos */

#include <iostream>
#include <string>
#include <cassert>

int main() {
/* ejemplo de un tipo de dato double- numero real-*/
double numero{2.53};

/* ejemplo de cadena de texto string y de caracter */
std::string cadena = "Cadena de Texto";
char caracter{'C'};

/********************/
bool booleano{true};
unsigned contador{1};
int i{-3};

/* en este otro ejemplo, se puede ver la utilización de los tipos unsigned, bool, int */
if (booleano == true)
{
for (contador;contador<=2;contador++)
{
i = i + 1;
}}
assert(i == -1);
assert(caracter  == 67);
assert(cadena + " en C++" == "Cadena de Texto en C++");
assert(numero + 1 == 2.53 + 1);
}