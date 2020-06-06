/* Camila Victoria Losada
20200531
Funciones y Operador Condicional */

#include <cassert>

double Abs (double);

int main () {

assert(3 == Abs(3));
assert (3.75 == Abs(-3.75));

}

double Abs(double x){return x<0 ? -x : x;}