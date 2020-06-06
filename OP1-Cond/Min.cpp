/* Camila Victoria Losada
20200531
Funciones y Operador Condicional */

#include <cassert>

double Min (double, double);

int main () {

assert(4 == Min(4,4));
assert(-3.4 == Min(-3.4,1));
assert(2.4554 == Min(2.4554,2.5));

}

double Min(double x, double y){return x<y ? x : y;}