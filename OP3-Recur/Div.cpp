/* Camila Victoria Losada
20200628
Funciones Recursivas con Operador Condicional */

#include <cassert>
#include <iostream>
unsigned Div (unsigned, unsigned);

int main () {

assert (9 == Div(45,5));
assert (14 == Div(100,7));
assert (0 == Div(1,2));
assert (35 == Div(425,12));
assert (35 == Div(428,12));

}


unsigned Div (unsigned Dividendo, unsigned Divisor){
return Dividendo < Divisor ? 0:
Dividendo - Divisor <= 0 ? 1:Div(Dividendo - Divisor, Divisor)+1;}

 