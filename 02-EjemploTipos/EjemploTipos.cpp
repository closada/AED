/* Camila Victoria Losada
20200518
Tipos de Datos */

#include <iostream>
#include <string.h>
#include <assert.h>

int main() {
bool booleano{true};
char caracter{'\n'};
unsigned contador{1};
int i{2};
double numero{2.53};
char cadena[] {"\nResultado: "};

std::cout << "A continuacion se presentara un ejemplo de la utilizacion de los distintos tipos de datos en C++, sera una suma:\n\n";

if (booleano == true)
{
std::cout << "El contador comenzara en " << contador;
std::cout << caracter;
for (contador;contador<=i;contador++)
{
numero = numero + i;
}}
std::cout << cadena << numero;
}